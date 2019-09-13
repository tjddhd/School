#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <map>
#include "SymbolTableEntry.h"
using namespace std;

class SYMBOL_TABLE {
private:
  std::map<string, SYMBOL_TABLE_ENTRY> hashTable;

public:
  //Constructor
  SYMBOL_TABLE( ) { }

  // Add symbol table entry x to this symbol table.
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

  // If a symbol table entry with name theName is
  // found in this symbol table, then return its token type
  // info; otherwise, return token info with type UNDEFINED.
  TYPE_INFO findEntry(string theName) {
    TYPE_INFO info = {UNDEFINED};
    map<string, SYMBOL_TABLE_ENTRY>::iterator itr;
    if ((itr = hashTable.find(theName)) == hashTable.end())
      return(info);
    else return(itr->second.getTypeInfo());
  }

};

#endif  // SYMBOL_TABLE_H
