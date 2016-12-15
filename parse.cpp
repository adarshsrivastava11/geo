#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include "parse.h"
#include "grammar.h"
#include "lib.h"
#define START_PIVOT -1
#define PDEBUG 1

using namespace std;
extern grammar_t grammar;

void ParseTree::print(){
  this->recursivePrint(this->root, 0);
}

void ParseTree::printTabs(int num){
  for(int i=0; i<num; i++){
    cout<<"|\t";
  }
}

void ParseTree::recursivePrint(ParseTreeNode* node, int numTabs){
  printTabs(numTabs);

  if(!(node->isTerminal())){
    cout<< node->grammarSymbol<<endl;
  } else {
    cout<< node->grammarSymbol <<" === "<<node->content<<endl;
  }
  for(int i=0; i< node->numChildren; i++){
    ParseTreeNode** childTrees = node->children;
    this->recursivePrint(childTrees[i], numTabs+1);
  }
}

string ParseTree::preOrder() {
  this->prefixString.clear();
  this->recursivePreOrder(this->root);
  return this->prefixString;
}

void ParseTree::recursivePreOrder(ParseTreeNode* node) {
  if(node->isTerminal()) {
    // cout<< node->content;
    this->prefixString = (string)this->prefixString + (string)(node->content);
    this->prefixString = (string)this->prefixString + (string)" ";
  }
  for(int i=0; i< node->numChildren; i++){
    ParseTreeNode** childTrees = node->children;
    this->recursivePreOrder(childTrees[i]);
  }
}

void ParseTree::correctParseTree(){
  return;
}
    
void ParseTree::parse(){
  if(PDEBUG) cout<<"ParseTree::parse()"<<endl;
  if(this->root!=NULL) deleteSubtree(root);
  this->root = recursiveParse(startSymbol, 0, START_PIVOT);
}

ParseTreeNode* ParseTree::recursiveParse(string grammarSymbol, int leafsTillNow, int parentPivot){
  if(PDEBUG) cout<<"ParseTree::recursiveParse("<<grammarSymbol<<", "<<leafsTillNow<<", "<<parentPivot<<")"<<endl;
  //first consider the terminal symbols
  if(isRegex(grammarSymbol)){
    string regex = grammarSymbol;
    vector<Word> words = this->words;
    int foundIndex = -1;
    for(int l=parentPivot-1, r=parentPivot+1; (l>=0 || r<words.size());){

      if(l>=0){//Look left
        Word leftWord = this->words[l];
        if(PDEBUG){
          //cout<<"leftWord content: "<<leftWord.content<<", leafIndex: "<<leftWord.leafIndex<<", sentence index: "<<r<<endl;
        }
        if(leftWord.leafIndex > 0 && leftWord.leafIndex <= leafsTillNow){
          //this word has already been used by the partially constructed parse tree
          l--;
        } else if(satisfiesRegex(leftWord.content, regex)){
          foundIndex = l;
          break;
        } else{
          l--;
        }
      }

      if(r<words.size()){//Look right
        Word rightWord = this->words[r];
        if(PDEBUG){
          //cout<<"rightWord content: "<<rightWord.content<<", leafIndex: "<<rightWord.leafIndex<<", sentence index: "<<r<<endl;
        }
        if(rightWord.leafIndex > 0 && rightWord.leafIndex <= leafsTillNow){
          //this word has already been used by the partially constructed parse tree
          r++;
        } else if(satisfiesRegex(rightWord.content, regex)){
          foundIndex = r;
          break;
        } else {
          r++;
        }
      }        
    }
    
    if(foundIndex == -1){
      return NULL;
    }

    Word& foundWord = this->words[foundIndex];
    foundWord.leafIndex = leafsTillNow + 1;
    if(PDEBUG) cout<<"FOUND TERMINAL "<<grammarSymbol<<" AS "<<foundWord.content
      <<" AT "<<foundIndex<<" index with "<<foundWord.leafIndex<<" as leaf index"<<endl;

    ParseTreeNode* newNode = new ParseTreeNode();
    newNode->grammarSymbol.assign(grammarSymbol);
    newNode->grammarRuleUsed = 0;
    newNode->numChildren = 0;
    newNode->leftmostLeafIndex = leafsTillNow + 1;
    newNode->rightmostLeafIndex = leafsTillNow + 1;
    newNode->pivotIndex = foundIndex;
    newNode->children = NULL;
    newNode->wordIndex = foundIndex;
    newNode->content = string(foundWord.content);
    foundWord.leafIndex = leafsTillNow + 1;

    return newNode;
  }
  
  productionrules_t pds = grammar[grammarSymbol];
  assert(!pds.empty());
  
  for(int i=0; i<(int) pds.size(); i++){
    int l = leafsTillNow;
    productionrule_t pd = pds[i];
    if(PDEBUG){
      cout<<"Trying production rule "<<grammarSymbol<<" -> ";
      printListOfStrings(pd);
      cout<<endl;
    }
    string firstDerivation = pd[0];
    ParseTreeNode* leftChildTree = recursiveParse(firstDerivation, l, parentPivot);

    if(leftChildTree == NULL){
      if(PDEBUG){
        cout<<"Could not derive "<<firstDerivation<<endl;
        //~ this->printListOfWords();
      }
      
      continue;
    }
    if(PDEBUG) cout<<"Left child tree at "<<firstDerivation<<endl;
    int selfPivot = leftChildTree->getPivotIndex();
    ParseTreeNode** childTrees = (ParseTreeNode**) malloc(pd.size() * sizeof(ParseTreeNode*));
    childTrees[0] = leftChildTree;
    l += leftChildTree->getNumOfLeaves();
    bool success = true;
    int j = 1;
    for(; j<(int) pd.size(); j++){
      string nextDerivation = pd[j];
      ParseTreeNode* nextChildTree = recursiveParse(nextDerivation, l, selfPivot);
      if(nextChildTree == NULL){
        success = false;
        break;
      }
      childTrees[j] = nextChildTree;
      l += nextChildTree->getNumOfLeaves();
    }
    
    if(success == false){
      while(--j >= 0){
        deleteSubtree(childTrees[j]);
      }
      free(childTrees);
      continue;
    }
    
    ParseTreeNode* thisNode = new ParseTreeNode();
    thisNode->grammarSymbol = string(grammarSymbol);
    thisNode->grammarRuleUsed = i;
    thisNode->numChildren = pd.size();
    thisNode->leftmostLeafIndex = leftChildTree->getLeftmostLeafIndex();
    assert(thisNode->leftmostLeafIndex == leafsTillNow + 1);
    thisNode->rightmostLeafIndex = l;
    thisNode->pivotIndex = selfPivot;
    thisNode->children = childTrees;
    
    if(PDEBUG){
      this->recursivePrint(thisNode, 0);
    }
    return thisNode;
  }
  return NULL;
}


void ParseTree::printListOfWords(){
  cout<<"Printing List of words"<<endl;
  for(int i=0; i < this->words.size(); i++){
    cout<<"\""<<this->words[i].content<<"\" leafIndex: "
      <<this->words[i].leafIndex<<endl;
  }  
}

void ParseTree::generateListOfWords(){
  if(PDEBUG) cout<<"Generating list of words"<<endl;
  vector<string> split_str = split(this->str);
  for(int i=0; i< (int)split_str.size(); i++){
    if(split_str[i].empty()) continue;
    Word* word = new Word(split_str[i]);
    this->words.push_back(*word);
  }
}

void ParseTree::deleteSubtree(ParseTreeNode* node){
  if(node->isTerminal()){
    assert(node->leftmostLeafIndex == node->rightmostLeafIndex);
    this->words[node->wordIndex].leafIndex = 0;
    if(PDEBUG){
      cout<<"Setting leaf index zero for "<<this->words[node->wordIndex].content<<endl;
    }
  }
  ParseTreeNode** childTrees = node->children;
  for(int i=0; i<node->numChildren; i++){
    deleteSubtree(childTrees[i]);
  }
  free(childTrees);
  free(node);
}
