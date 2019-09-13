#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H
//Thomas Dolan
#include <string>
#include <cstring>
using namespace std;


#define ADD			-8
#define SUB			-7
#define MULT		-6
#define DIV			-5
#define INT        -4   
#define STR        -3
#define INT_or_STR -2
#define UNDEFINED  -1   
#define NOT_APPLICABLE -1

typedef struct { 
  int type;       // one of the above type codes
  char exprVal[256];
  int intVal;
} TYPE_INFO;

typedef struct{
int op;
}OPERATOR;

class SYMBOL_TABLE_ENTRY {
private:
  // Member variables
  string name;
  TYPE_INFO typeInfo;

public:
  // Constructors
  SYMBOL_TABLE_ENTRY( ) { 
    name = ""; 
    typeInfo.type = UNDEFINED;
  }

  SYMBOL_TABLE_ENTRY(const string theName, const TYPE_INFO theType) {
    name = theName;
    typeInfo.type = theType.type;
	typeInfo.intVal = theType.intVal;
	strcpy(typeInfo.exprVal, theType.exprVal);
  }

  // Accessors
  string getName() const { return name; }
  TYPE_INFO getTypeInfo() const { return typeInfo; }
};

#endif  // SYMBOL_TABLE_ENTRY_H
