from __future__ import unicode_literals
from django.contrib.auth.models import User
from django.db import models

class Student(models.Model):

	user = models.OneToOneField(User)
	natural_lang_commands = models.CharField(max_length=50000,blank=True)
	meta_lang_commands = models.CharField(max_length=50000,blank=True)
	construction_commands = models.CharField(max_length=100000,blank=True)
	username = models.CharField(max_length=10,blank=True)
	full_name = models.CharField(max_length=200)
	city = models.CharField(max_length=30,blank=True)
	college = models.CharField(max_length=30,blank=True)
	state = models.CharField(max_length=30,blank=True)
	def __str__(self):
		return self.username

class State(models.Model):
	state_name = models.CharField(max_length=200,blank=True)
	def __str__(self):
		return self.state_name

class City(models.Model):
	parent_state = models.ForeignKey(State, on_delete=models.CASCADE)
	city_name = models.CharField(max_length=200,blank=True)
	def __str__(self):
		return self.city_name
		