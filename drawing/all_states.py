import urllib2
from .models import *
from bs4 import BeautifulSoup
wiki = "http://adaniel.tripod.com/statelist.htm"
page = urllib2.urlopen(wiki)
soup = BeautifulSoup(page)
all_tables = soup.find('table', width='390')
states = []
for row in all_tables.findAll('tr'):
	cells = row.findAll('td')
	states.append(cells[0].text)

print states


