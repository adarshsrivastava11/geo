from __future__ import unicode_literals
from django.contrib.auth.models import User
from django.db import models

class Student(models.Model):

	user = models.OneToOneField(User)
	natural_lang_commands = models.CharField(max_length=5000,blank=True)
	meta_lang_commands = models.CharField(max_length=5000,blank=True)
	construction_commands = models.CharField(max_length=10000,blank=True)
	username = models.CharField(max_length=10,blank=True)
	full_name = models.CharField(max_length=200)
	def __str__(self):
		return self.username

