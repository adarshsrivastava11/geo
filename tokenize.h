#define N_KEYWORDS 50
#define MAX_SYMBOLS 1<<10

enum datatype{
	DT_INT,
	DT_LONG,
	DT_FLOAT,
	DT_CHAR,
	DT_STRING,
	DT_KEYWORD,
	DT_NONE
};

struct symbol{
	char* name;
	enum datatype type;
};

int init();
