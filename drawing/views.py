from django.shortcuts import render
from django.http import HttpResponse
from functions import *
from django.shortcuts import redirect


# Create your views here.
def index(request):
	fo = open("all_commands.txt","wb")
	commands = ""
	commands = request.POST.get('commands',False)
	if commands != False:
		fo.write(commands)
	else:
		fo.write("")
	fo.close()
	sys_exec("python plotter.py")
	
	return render(request,'index.html')

def drawing(request):
	return render(request,'drawing.html')

def clear(request):
	fo = open("drawing/static/app1.js","w")
	
	fo.close()
	sys_exec("python clearscreen.py")
	
	return redirect('/')