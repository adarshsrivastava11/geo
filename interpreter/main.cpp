#include<iostream>
#include<vector>
#include<string>
#include "interpreter.h"
#include "grammar.h"
#define MDEBUG false

using namespace std;
grammar_t grammar;

int main(){
  grammar = GrammarReader::getGrammar();
  //GrammarReader::printGrammar(grammar);
  
  string cmd;
  while(getline(cin, cmd)) {
    cout<<cmd<<endl;
    string interpretation = getInterpretation(cmd);
    if(MDEBUG)
      cout<<interpretation;
  }

  return 0;
}
