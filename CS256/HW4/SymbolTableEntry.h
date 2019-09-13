#ifndef SYMBOL_TABLE_ENTRY_H
#define SYMBOL_TABLE_ENTRY_H

#include <string>
using namespace std;

#define FUNCTION    -5  // Type codes
#define INT         -4
#define STR         -3
#define INT_or_STR  -2
#define UNDEFINED   -1
#define NOT_APPLICABLE  -1

class SYMBOL_TABLE_ENTRY {
private:
  // Member variables
  string name;
  int typeCode;  
  int numParam;     
  int returnType;   

public:
  // Constructors
  SYMBOL_TABLE_ENTRY( ) { name = ""; typeCode = UNDEFINED; numParam = UNDEFINED; returnType = UNDEFINED;}

  SYMBOL_TABLE_ENTRY(const string theName, const int theType, const int theNum, const int theReturn) {
    name = theName;
    typeCode = theType;
	numParam = theNum;
	returnType = theReturn;
  }

  // Accessors
  string getName() const { return name; }
  int getTypeCode() const { return typeCode; }
  int getNumParam() const { return numParam; }
  int getReturnType() const { return returnType; }
};

#endif  // SYMBOL_TABLE_ENTRY_H
