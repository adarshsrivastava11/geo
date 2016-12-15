#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstdlib>
#define debug 0
using namespace std;

string toupper(string a) {
  for(int i=0;i<a.length();i++) {
    if(a[i] >= 97 and a[i] <= 122)
      a[i] = a[i] - 32;
  }
  return a;
}

bool isNumber(string str) {
  bool decimal = false;
  for(int i=0;i<str.length();i++) {
    if(str[i] == '.' and !decimal) {
      decimal = true;
      continue;
    }
    if(str[i]<48 or str[i]>57)
      return false;
  }
  return true;
}

bool isPointSingle(string str) {
  if(str.length() == 1 and str.compare(toupper(str))==0 and !isNumber(str))
    return true;
  return false;
}

bool isPointDouble(string str) {
  if(str.length() == 2 and str.compare(toupper(str))==0 and !isNumber(str))
    return true;
  return false;
}

bool isPointTriple(string str) {
  if(str.length() == 3 and str.compare(toupper(str))==0 and !isNumber(str))
    return true;
  return false;
}

double stod(string str) {
  bool decimal = false;
  double n = 0;
  double power = 1;
  for(int i=0;i<str.length();i++) {
    if(str[i] == '.') {
      decimal = true;
      power = 10;
      continue;
    }
    if(decimal) {
      n = n + (str[i] - '0')/power;
      power = power*10;
    } else {
      n = n*10 + (str[i] - '0');
    }
  }
  return n;
}

bool isLine(string str) {
  if(str.length()!=1)
    return false;
  if(str[0] >=97 and str[0] <=122)
    return true;
  else
    return false;
}

// int main() {
//   string str = "a";
//   cout<<isNumber("9.1")<<endl;
// }
