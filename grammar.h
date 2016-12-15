#include<vector>
#include<string>
#include<string.h>
#include<map>
#define GRAMMAR_FILE_PATH "./language_grammar.grm"

using namespace std;
typedef string nonterminal_t;
typedef vector<string> productionrule_t;
typedef vector<productionrule_t> productionrules_t;
typedef map<nonterminal_t, productionrules_t> grammar_t;

class GrammarReader{
  public:
    static grammar_t getGrammar();
    static void printGrammar(grammar_t grammar);
};

const string startSymbol = "command";
const string regexInteger = "[0-9]+";
const string regexReal = "[0-9]+(.[0-9]+)?";
const string regexSmallCaps = "[a-z]";
const string regexPointSinglet = "[A-Z]";
const string regexPointDoublet = "[A-Z][A-Z]";
const string regexPointTriplet = "[A-Z][A-Z][A-Z]";

bool isRegex(string str);
bool satisfiesRegex(string str, string regex);
