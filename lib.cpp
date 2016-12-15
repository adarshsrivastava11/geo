#include "lib.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> split(string str) {
  vector<string> *answer = new vector<string>;
  int j=0;
  for(int i=0;i<str.length();i++) {
    if(str[i] == ' ') {
      (*answer).push_back(str.substr(j, i-j));
      j=i+1;
    }
  }
  (*answer).push_back(str.substr(j, str.length()-j));
  return *answer;
}

void printListOfStrings(vector<string> list){
  for(int i=0; i< (int) list.size(); i++){
    cout<<list[i]<<" ";
  }
}
