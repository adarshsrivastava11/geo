#include<iostream>
#include<fstream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#define debug 0
using namespace std;

vector<pair<int, string> > src;
vector<pair<int, string> > trg;
vector<pair<pair<int, int>, double > > relation;
map<string, vector<pair<string, double> > > rel2;

string find_src(int token) {
  for(int i=0;i<int(src.size());i++) {
    if(token == src[i].first)
      return src[i].second;
  }
  return "";
}

string find_trg(int token) {
  for(int i=0;i<int(trg.size());i++) {
    if(token == trg[i].first)
      return trg[i].second;
  }
  return "";
}

int main() {
  src.clear();
  trg.clear();
  relation.clear();
  
  ifstream f("source.vcb");
  int tmp1, tmp3;
  string tmp2;
  while (true) {
    f>>tmp1>>tmp2>>tmp3;
    src.push_back((pair<int, string>)make_pair(tmp1, tmp2));
    if(f.eof()) 
      break;
  }
  f.close();

  if(debug) {
    for(int i=0;i<int(src.size());i++) {
      cout<<src[i].first<<" "<<src[i].second<<endl;
    }
  }
	
  f.open("target.vcb");
  while (true) {
    f>>tmp1>>tmp2>>tmp3;
    trg.push_back((pair<int, string>)make_pair(tmp1, tmp2));
    if(f.eof()) 
      break;
  }
  f.close();

  if(debug) {
    for(int i=0;i<int(trg.size());i++) {
      cout<<trg[i].first<<" "<<trg[i].second<<endl;
    }
  }
  
  f.open("alignment.txt");
  double tmp4;
  while (true) {
    f>>tmp1>>tmp3>>tmp4;
    relation.push_back( (pair<pair<int, int>, double>)make_pair((pair<int, int>)make_pair(tmp1, tmp3), tmp4) );
    if(f.eof()) 
      break;
  }
  f.close();
	

  for(int i=0;i<int(relation.size());i++) {
    if(debug) {
      cout<<find_src(relation[i].first.first)<<" "<<find_trg(relation[i].first.second)<<" "<<relation[i].second<<endl;
    }
    rel2[find_src(relation[i].first.first)].push_back(make_pair(find_trg(relation[i].first.second), relation[i].second));
  }
  
  for(map<string, vector<pair<string, double> > >::iterator it=rel2.begin(); it!=rel2.end(); it++) {
    cout<<(*it).first<<" ->";
    vector<pair<string, double> > tmp = (*it).second;
    for(int i=0;i<int(tmp.size());i++) {
      cout<<" ("<<tmp[i].first<<","<<tmp[i].second<<")";
    }
    cout<<endl;
  }

}

