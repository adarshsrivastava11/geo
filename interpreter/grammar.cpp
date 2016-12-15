#include "grammar.h"
#include "lib.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>
#define GDEBUG 0

using namespace std;

grammar_t GrammarReader::getGrammar(){
  ifstream grammarFile(GRAMMAR_FILE_PATH);
  string line;
  grammar_t grammar;
  
  if(!grammarFile.is_open() || grammarFile.eof()){
    throw string("Cannot open grammar file\n");
  }
  
  getline(grammarFile, line);//get the next non-terminal
  while(!grammarFile.eof()){
    //~ cout<<"NONTERMINAL LINE"<<line<<endl;
    assert(line.find("=") != string::npos);//commands =
    nonterminal_t nonTerminal = line.substr(0, line.find(" ")); //commands =
    productionrules_t productionRules;
    
    if(GDEBUG){
      cout<<"NONTERMINAL "<<nonTerminal<<endl;
    }
    
    getline(grammarFile, line);//command
    while(!line.empty()){
      productionrule_t productionRule;
      int cursorIndex = line.find_first_not_of(" ");
      if(GDEBUG){
        cout<<"PRODUCTION RULE LINE"<<line<<endl;
      }
      assert(cursorIndex != string::npos);
      if(!line.substr(cursorIndex, 1).compare("|")){
        //| commands command
        cursorIndex = line.find_first_not_of(" ", cursorIndex+1);
      }
      assert(cursorIndex != string::npos);
      while(cursorIndex != string::npos){
        //either a space or end of string
        int nextDelimiter = line.find_first_of(" ", cursorIndex);
        
        if(nextDelimiter==string::npos){
          nextDelimiter = line.length();
        }
        
        productionRule.push_back(
          line.substr(cursorIndex, nextDelimiter - cursorIndex)
        );
        
        cursorIndex = line.find_first_not_of(" ", nextDelimiter);
        
      }
      productionRules.push_back(productionRule);
      getline(grammarFile, line);
    }
    productionrules_t alreadyexists = grammar[nonTerminal];
    assert(alreadyexists.empty());
    grammar[nonTerminal] = productionRules;
    while(!grammarFile.eof() && line.empty()){
      getline(grammarFile, line);//get the next non-terminal
    }
  }
  return grammar;
}

void GrammarReader::printGrammar(grammar_t grammar){
  for(grammar_t::iterator it = grammar.begin(); it != grammar.end(); ++it){
    cout<<(*it).first<<" ="<<endl;
    productionrules_t productionRules = (*it).second;
    for(productionrules_t::iterator it2 = productionRules.begin(); it2 != productionRules.end(); ++it2){
      productionrule_t productionRule = (*it2);
      for(productionrule_t::iterator it3 = productionRule.begin(); it3 != productionRule.end(); ++it3){
        cout<<(*it3)<<" ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
}

bool isRegex(string str){
  if(GDEBUG) cout<<"isRegex("<<str<<")"<<endl;
  if(str.size() == 0) return false;
  if(str.at(0) == '\'' && str.at(((int)str.size()) - 1) == '\''){
    assert(str.size() > 2);
    return true;
  }
  
  return
    (str.compare(regexInteger) == 0)
    || (str.compare(regexReal)==0)
    || (str.compare(regexPointSinglet)==0)
    || (str.compare(regexPointDoublet)==0)
    || (str.compare(regexPointTriplet)==0)
    || (str.compare(regexSmallCaps)==0);
}

bool satisfiesRegex(string str, string regex){
  if(GDEBUG) cout<<"satisfiesRegex("<<str<<", "<<regex<<")"<<endl;
  if(regex.compare(regexInteger) == 0){
    for(int i=0; i<(int)str.size(); i++){
      if(str.at(i) < '0' || str.at(i) > '9'){
        return false;
      }
    }
    return true;
  } else if(regex.compare(regexReal) == 0){
    bool seenDecimalPoint = false;
    for(int i=0; i<(int)str.size(); i++){
      if(str.at(i) == '.'){
        if(seenDecimalPoint == true){
          //already seen a decimal point
          return false;
        }
        seenDecimalPoint = true;
        continue;
      }
      
      if(str.at(i) < '0' || str.at(i) > '9'){
        //neither a dot nor a number
        return false;
      }
    }
    return true;
  } else if(regex.compare(regexPointTriplet)==0){
    if(((int)str.size()) != 3) return false;
    for(int i=0; i<3; i++){
      if(str.at(i) < 'A' || str.at(i) > 'Z'){
        return false;
      }
    }
    return true;
  } else if(regex.compare(regexPointDoublet)==0){
    if(((int)str.size()) != 2) return false;
    for(int i=0; i<2; i++){
      if(str.at(i) < 'A' || str.at(i) > 'Z'){
        return false;
      }
    }
    return true;
  } else if(regex.compare(regexPointSinglet)==0){
    if(((int)str.size()) != 1) return false;
    for(int i=0; i<1; i++){
      if(str.at(i) < 'A' || str.at(i) > 'Z'){
        return false;
      }
    }
    return true;
  } else if (regex.compare(regexSmallCaps) == 0){
    if(((int)str.size()) != 1) return false;
    for(int i=0; i<1; i++){
      if(str.at(i) < 'a' || str.at(i) > 'z'){
        return false;
      }
    }
    return true;
  } else{
    assert(regex.at(0) == '\'');
    int size = (int) regex.size();
    assert(regex.at(size - 1) == '\'');
    assert(size > 2);
    
    string literal = regex.substr(1, size-2);
    if(GDEBUG) cout<<"comparing "<<literal<<" with "<<str<<endl;
    if(literal.compare(str) == 0) return true;
    else return false;
  }
}
