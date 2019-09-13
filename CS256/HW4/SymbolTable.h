#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#define FUNCTION    -5  // Type codes
#define INT               -4
#define STR               -3
#define INT_or_STR  -2
#define UNDEFINED   -1
#define NOT_APPLICABLE  -1


#include <map>
#include <string>
#include "SymbolTableEntry.h"
using namespace std;

class SYMBOL_TABLE {
private:
  std::map<string, SYMBOL_TABLE_ENTRY> hashTable;

public:
  //Constructor
  SYMBOL_TABLE( ) { }

  // Add SYMBOL_TABLE_ENTRY x to this symbol table.
  // If successful, return true; otherwise, return false.
  bool addEntry(SYMBOL_TABLE_ENTRY x) {
    // Make sure there isn't already an entry with the same name
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    if ((itr = hashTable.find(x.getName())) == hashTable.end()) {
      hashTable.insert(make_pair(x.getName(), x));
	return(true);
    }
    else return(false);
  }

  // If a SYMBOL_TABLE_ENTRY with name theName is
  // found in this symbol table, then return true;
  // otherwise, return false.
  bool findEntry(string theName) {
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    if ((itr = hashTable.find(theName)) == hashTable.end())
      return(false);
    else return(true);
  }

  int findEntryType(string theName)  
									 
	{
		map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
		itr = hashTable.find(theName);
		if ((itr = hashTable.find(theName)) == hashTable.end())
			return(UNDEFINED);
		else return(itr->second.getTypeCode());
	}

  int findEntryParams(string theName) 
  {
		map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
		itr = hashTable.find(theName);
		if ((itr = hashTable.find(theName)) == hashTable.end())
			return(UNDEFINED);
		else return(itr->second.getNumParam());
  }

  int findEntryReturn(string theName) 
  {
		map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
		itr = hashTable.find(theName);
		if ((itr = hashTable.find(theName)) == hashTable.end())
			return(UNDEFINED);
		else return(itr->second.getReturnType());
  }


};

#endif  // SYMBOL_TABLE_H
