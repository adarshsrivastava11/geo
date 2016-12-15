#include "parse.h"
#include <string>

using namespace std;

class Action{
	public:
		int action;
		int constructible;
		double length;
		char point1, point2, point3;
		char center1, center2;
		double radius1, radius2;
		
		Action();
		string toString();
		bool isValid();
    void extractAction(ParseTree tree);
};

class keywords{
	public:
	//action words
	static const int numActionWords = 5;
	static const int CONSTRUCT = 1;
	static const int CUT = 2;
	static const int MARK = 3;
	static const int LABEL = 4;
	static const int JOIN = 5;
	
	
	//constructibles
	static const int numConstructibles = 3;
	static const int LINE_SEGMENT = 101;
	static const int INTERSECTING_ARCS =102;
	static const int ARC =103;
	
	static const int JOINING_SEGMENT = 104;
	
	//parameter names
	static const int numParameterNames = 4;
	static const int LENGTH = 201;
	static const int CENTER = 202;
	static const int RADIUS = 203;
	static const int POINT = 204;
	static const int INTERSECTING_AT = 205;
	static const int CENTERS = 206;

	//parameter values
	static const int numParameterValues = 4;
	static const int POINT_SINGLE = 301;
	static const int POINT_PAIR = 302;
	static const int POINT_TRIPLET = 303;
	static const int DOUBLE = 304;
};

		
static const int actions[] = {
		keywords::CONSTRUCT,
		keywords::CUT,
		keywords::MARK,
		keywords::JOIN,
		keywords::LABEL
};


const int constructibles[] = {
		keywords::LINE_SEGMENT,
		keywords::INTERSECTING_ARCS,
		keywords::ARC
};


const int parameterNames[] = {
		keywords::LENGTH,
		keywords::CENTER,
		keywords::RADIUS,
		keywords::POINT
};


const int parameterValues[] = {
		keywords::POINT_SINGLE,
		keywords::POINT_PAIR,
		keywords::POINT_TRIPLET,
		keywords::DOUBLE
};

bool isValidPoint(char point);
