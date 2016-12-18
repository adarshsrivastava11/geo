import urllib2
from bs4 import BeautifulSoup
wiki = "http://adaniel.tripod.com/statelist.htm"
page = urllib2.urlopen(wiki)
soup = BeautifulSoup(page)
print soup