import os
import subprocess
import commands

def sys_exec(command):
	#print "executing", command
	return commands.getstatusoutput(command)
	#output = subprocess.check_output(command, shell=True)
	#os.system(command)
