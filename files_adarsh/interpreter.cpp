#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include "interpreter.h"
#include "mapper.h"
#include "action.h"
#define MAX_TRANSLATIONS 10
#define FileDebug true

string getInterpretation(string parse){
  if(DEBUG) cout<<"Interpreting \""<<parse<<"\"..."<<endl;
  vector<pair<string, double> > mappings = getPossibleMappings(parse);
	/*
  cout<<"Listing mappings..."<<endl;
  for(int i=0; i<(int)mappings.size(); i++){
    cout<<mappings[i].first<<"\t ->"<<mappings[i].second<<endl;
  }
  */

  Action *action = new Action();

  if(DEBUG) cout<<"No. of possibilities " <<mappings.size()<<endl;
  if(mappings.size()==0 and FileDebug) {
    ofstream file("testing.txt", ios::out|ios::app);
    file<<"\nParse String:"<<endl<<parse<<endl;
    file<<"No mappings generated"<<endl;
    file.close();
  }

  int numTranslations = mappings.size() < MAX_TRANSLATIONS ? mappings.size() : MAX_TRANSLATIONS;
  for(int i=0; i < numTranslations ; ++i){
    
    ParseTree parseTree(mappings[i].first);
    if(DEBUG) cout<<"Parsing \""<<mappings[i].first<<"\""<<endl;
    parseTree.parse();
    
    if(parseTree.isEmpty()){
      if(DEBUG) cout<<"Could not parse "<<i+1<<"th possibility \""
        <<mappings[i].first<<"\""<<endl;
      if(numTranslations == i+1 and DEBUG) {
	cout<<"All possibilities parsed. No parse tree found"<<endl;
	if(FileDebug) {
	  ofstream file("testing.txt", ios::out|ios::app);
	  file<<"\nParse String:"<<endl<<parse<<endl;
	  file<<"All possibilities parsed. No parse tree found"<<endl;
	  file.close();
	}
      }
      continue;
    }
    
    if(DEBUG) cout<<"Found a parse tree:"<<endl;
    parseTree.print();

    string preOrder = parseTree.preOrder();
    cout<< "PreOrder Traversal of Tree:" <<endl<< preOrder <<endl;
    if(FileDebug) {
      ofstream file("testing.txt", ios::out|ios::app);
      file<<"\nParse String:"<<endl<<parse<<endl;
      file<<"Parse Successful. PreOrder Traversal:"<<endl<<preOrder<<endl;
      file.close();
    }
    ofstream file("preOrder.txt", ios::out);
    file<<parseTree.preOrder()<<endl;
    file.close();
    
    return action->toString();
    
    action->extractAction(parseTree);
    while(!action->isValid()){
      parseTree.correctParseTree();
      if(parseTree.isEmpty()){//we tried all possible parses
        break;
      }
      action->extractAction(parseTree);
    }
    
    if(action->isValid()){
      continue;
    }
    
    return action->toString();
  }
  return action->toString();
}
