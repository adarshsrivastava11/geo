from django.shortcuts import render
from django.http import HttpResponse
from functions import *
from django.shortcuts import redirect
from .models import *
from django.contrib.auth.decorators import login_required
from django.contrib.auth import authenticate, login, logout
import sys, os


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
		student.natural_lang_commands = commands+"."+student.natural_lang_commands
		student.save()
		fo.write(commands)
	else:
		fo.write("")
	fo.close()
	system_command = "python "+"files_"+user_name+"/plotter.py "+user_name+""
	sys_exec(system_command)
	
	file_name = "files_"+user_name+"/draw_commands.js"
	fo = open(file_name,"r")
	file_content = fo.read()
	student.construction_commands = file_content + student.construction_commands
	fo.close()

	file_name = "files_"+user_name+"/preOrder.txt"
	fo = open(file_name,"r")
	meta_command = fo.read()
	student.meta_lang_commands = meta_command+";"+student.meta_lang_commands
	student.save()
	fo.close()
	return render(request,'drawing.html',{'user_name':user_name,'content':file_content})


def clear(request,user_name):
	pp = sys_exec("python "+"files_"+user_name+"/clearscreen.py "+user_name+"")
	print pp
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
