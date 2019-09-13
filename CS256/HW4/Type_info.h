#ifndef TYPE_INFO_H
#define TYPE_INFO_H

#include <map>
#include <string>
#include "SymbolTableEntry.h"
using namespace std;

typedef struct {
  int type;                // one of the above type codes
  int numParams;  // numParams and returnType only applicable
  int returnType;    // if type == FUNCTION
} TYPE_INFO;

	bool isIntCompatible(int theName) {
	  bool wut = false;
	  if (theName == -4 || theName == -2)
		  wut = true;
	  return wut;
  }
  
  bool isStringCompatible(int theName) {
  	  bool wut = false;
  	  if (theName == -3 || theName == -2)
  		  wut = true;
  	  return wut;
  }

  bool isIntOrStringCompatible(int theName) {
	  bool wut = false;
	  if(theName == -2 || theName == -3 || theName == -4)
		  wut = true;
	  return wut;
  }
#endif  // TYPE_INFO_H
