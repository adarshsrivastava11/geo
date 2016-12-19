from django.shortcuts import render
from django.http import HttpResponse
from functions import *
from django.shortcuts import redirect
from .models import *
from django.contrib.auth.decorators import login_required
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.models import User
import sys, os
import urllib2

from bs4 import BeautifulSoup


def index(request):
	return render(request,'index.html')

@login_required(login_url = '/login/')
def drawing(request,user_name):
	if user_name != request.user.username:
		return redirect('/login/')
	student = Student.objects.get(user=request.user)
	file_name = "files_"+user_name+"/all_commands.txt"
	fo = open(file_name,"wb")
	commands = ""
	commands = request.POST.get('commands',False)
	if commands != False:
		commands = commands.split('.')
		for command in commands:

			print command
			student.natural_lang_commands = student.natural_lang_commands+"."+command
			command = command+"\n"
			fo.write(command)
			
			student.save()

			
	else:
		fo.write("")
	fo.close()
	system_command = "python "+"files_"+user_name+"/plotter.py "+user_name+""
	sys_exec(system_command)
	
	file_name = "files_"+user_name+"/draw_commands.js"
	fo = open(file_name,"r")
	file_content = fo.read()
	student.construction_commands = file_content +"<br>"+ student.construction_commands
	fo.close()

	file_name = "files_"+user_name+"/preOrder.txt"
	fo = open(file_name,"r")
	meta_command = fo.read()
	student.meta_lang_commands = meta_command+"<br>"+student.meta_lang_commands
	student.save()
	fo.close()
	return render(request,'drawing.html',{'user_name':user_name,'content':file_content,'student':student})


def clear(request,user_name):
	sys_exec("python "+"files_"+user_name+"/clearscreen.py "+user_name+"")
	
	file_name = "files_"+user_name+"/draw_commands.js"
	fo = open(file_name,"w")
	
	fo.close()

	return redirect('/'+user_name+'/drawing/')

def login_view(request):
	username = request.POST.get('username',False)
	password = request.POST.get('password',False)

	if username != False:
		user = authenticate(username=username, password=password)
		if user is not None:
			
			login(request,user)
			sys_exec("mkdir files_"+username)
			sys_exec("cp -rf files/. files_"+username+"")
			return redirect('/'+username+'/drawing/')

	return render(request,'login.html')

def logout_view(request):
	user_name = request.user.username
	sys_exec("rm -rf files_"+user_name)
	logout(request)
	return redirect('/')

def signup_view(request):
	error = ""
	states = State.objects.all()
	full_name = request.POST.get('fullname',False)
	username = request.POST.get('username',False)
	password = request.POST.get('password',False)
	email_id = request.POST.get('email',False)
	college = request.POST.get('college',False)
	city = request.POST.get('city',False)
	state = request.POST.get('state',False)
	if username != False:
		if User.objects.filter(username=username).exists():
			error = 'Username Exists'
		else:
			user = User.objects.create_user(username=username,password=password,email=email_id)
			user.save()
			state = State.objects.get(state_name=state)
			city = City(city_name=city,state=state)
			city.save()
			student = Student(user=user,full_name=full_name,username=username,city=city,college=college,state=state)
			student.save()
			return redirect('/login/')

	return render(request,'signup.html',{'error':error,'states':states})

def testing_stuff(request):
	wiki = "http://127.0.0.1:8000/"
	page = urllib2.urlopen(wiki)
	soup = BeautifulSoup(page)

	all_tables = soup.find('p')
	city_list =  all_tables.text.split()
		

	State.objects.bulk_create(states)
	return redirect('/')