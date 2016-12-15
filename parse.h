#include <vector>
#include <string>
#include <assert.h>
#include "lib.h"

using namespace std;

class Word{
  public:
    int leafIndex;
    string content;
    Word(string content){
      this->content = content;
      this->leafIndex = 0;
    }
};

typedef vector<Word> ListOfWords;


class ParseTreeNode{
  public:
    string grammarSymbol;
    int grammarRuleUsed;
    int numChildren;
    int leftmostLeafIndex; //it's own index if terminal node
    //otherwise the index of the first leaf under its subtree
    int rightmostLeafIndex; //it's own index if terminal node
    //otherwise the index of the last leaf under its subtree
    int pivotIndex; //where is this node pivoted
    int wordIndex; //associated word in the input sentence (if this node is terminal)
    ParseTreeNode** children;
    string content; //only for leaf nodes
    
    ParseTreeNode(){
      this->children = NULL;
    }
    
    int getPivotIndex(){
      return this->pivotIndex;
    }
    
    int getLeftmostLeafIndex(){
      return this->leftmostLeafIndex;
    }
    
    int getRightmostLeafIndex(){
      return this->rightmostLeafIndex;
    }
  
    int getNumOfLeaves(){
      return this->getRightmostLeafIndex() - this->getLeftmostLeafIndex() + 1;
    }
  
    bool isTerminal(){
      return (this->numChildren == 0);
    }
};

class ParseTree{
  string str;//parse tree for str
  ParseTreeNode* root;
  ListOfWords words;
  string prefixString; //used in preOrder traversal
  
  public:
    ParseTree(string str){
      this->str = str;
      this->root = NULL;
      this->generateListOfWords();
      if(DEBUG) this->printListOfWords();
    }
    ~ParseTree(){
      if(this->root!=NULL){
        deleteSubtree(this->root);
      }
    }

    bool isEmpty(){
      if(root==NULL) return true;
      return false;
    }
    
    void correctParseTree();
    void parse();
    ParseTreeNode* recursiveParse(string grammarSymbol, int leafsTillNow, int parentPivot);
    void print();
    void recursivePrint(ParseTreeNode* node, int numTabs);
    void generateListOfWords();
    void printListOfWords();
    void deleteSubtree(ParseTreeNode* node);
    void printTabs(int num);
    string preOrder();
    void recursivePreOrder(ParseTreeNode* node);
};
