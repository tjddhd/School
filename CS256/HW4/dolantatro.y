/*
      mfpl.y

 	Specifications for the MFPL language, YACC input file.

      To create syntax analyzer:

        flex mfpl.l
        bison mfpl.y
        g++ mfpl.tab.c -o mfpl_parser
        mfpl_parser < inputFileName
 */

/*
 *	Declaration section.
 */
%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stack>
#include "SymbolTable.h"
#include "Type_info.h"
using namespace std;

#define SEMANTIC_TRACE 1

int lineNum = 1; 
int numPara = 0;
int exprCount = 0;

stack<SYMBOL_TABLE> scopeStack;    // stack of scope hashtables
SYMBOL_TABLE* table;

void beginScope();
void endScope();
void cleanUp();
bool findEntryInAnyScope(string theName);

void printRule(const char*, const char*);
int yyerror(const char* s) {
  printf("Line %d: %s\n", lineNum, s);
  cleanUp();
  exit(1);
}

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
}

%}

%union {
  char* text;
  TYPE_INFO typeInfo;
};

/*
 *	Token declarations
*/
%token  T_LPAREN T_RPAREN 
%token  T_IF T_LET T_LAMBDA T_PRINT T_INPUT
%token  T_ADD  T_SUB  T_MULT  T_DIV	 
%token  T_INTCONST T_STRCONST T_IDENT T_UNKNOWN

%type <text> T_IDENT
%type <typeInfo> N_EXPR 
%type <typeInfo> N_PARENTHESIZED_EXPR 
%type <typeInfo> N_IF_EXPR 
%type <typeInfo> N_LAMBDA_EXPR
%type <typeInfo> N_ID_EXPR_LIST
%type <typeInfo> N_INPUT_EXPR
%type <typeInfo> N_PRINT_EXPR
%type <typeInfo> N_EXPR_LIST
%type <typeInfo> N_ARITHMETIC_EXPR
%type <typeInfo> N_LET_EXPR
%type <typeInfo> T_INPUT



/*
 *	Starting point.
 */
%start 	N_START

/*
 *	Translation rules.
 */
%%
N_START		: N_EXPR
			{
			printRule("START", "EXPR");
			printf("\n---- Completed parsing ----\n\n");
			return 0;
			}
			;
N_EXPR		: T_INTCONST
			{
			printRule("EXPR", "INTCONST");
			$$.type = INT; 
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
			}
                | T_STRCONST
			{
			printRule("EXPR", "STRCONST");
			$$.type = STR; 
			$$.numParams = NOT_APPLICABLE;
			$$.returnType = NOT_APPLICABLE;
			}
                | T_IDENT
            {
			printRule("EXPR", "ID");
            if (!findEntryInAnyScope($1)) {
               yyerror("Undefined identifier");
               return(0);
               }
            $$.type = table->findEntryType(string($1)); 
            //$$.numParams = NOT_APPLICABLE;
			//$$.returnType = NOT_APPLICABLE;
			}
                | T_LPAREN N_PARENTHESIZED_EXPR T_RPAREN
            {
			printRule("EXPR", "( PARENTHESIZED_EXPR )");
			$$.type = $2.type; 
            $$.numParams = $2.numParams;
			$$.returnType = $2.returnType;
			}
			;
N_PARENTHESIZED_EXPR	: N_ARITHMETIC_EXPR 
				{
				printRule("PARENTHESIZED_EXPR",
                               "ARITHMETIC_EXPR");
                $$.type = $1.type; 
            	$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				}
                      | N_IF_EXPR 
				{
				printRule("PARENTHESIZED_EXPR", "IF_EXPR");
				$$.type = $1.type; 
            	$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				}
                      | N_LET_EXPR 
				{
				printRule("PARENTHESIZED_EXPR",
			               "LET_EXPR");
			    $$.type = $1.type; 
            	$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				}
                      | N_LAMBDA_EXPR 
				{
				printRule("PARENTHESIZED_EXPR",
					    "LAMBDA_EXPR");
				$$.type = $1.type; 
            	$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				}
                      | N_PRINT_EXPR 
				{
				printRule("PARENTHESIZED_EXPR",
				          "PRINT_EXPR");
				$$.type = $1.type; 
            	$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				}
                      | N_INPUT_EXPR 
				{
				printRule("PARENTHESIZED_EXPR",
				          "INPUT_EXPR");
				$$.type = $1.type; 
            	$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				}
                      | N_EXPR_LIST 
				{
				printRule("PARENTHESIZED_EXPR",
				          "EXPR_LIST");
				$$.type = $1.type; 
            	$$.numParams = $1.numParams;
				$$.returnType = $1.returnType;
				}
				;
N_ARITHMETIC_EXPR	: N_OP N_EXPR N_EXPR
				{
				printRule("ARITHMETIC_EXPR", 
					     "OP EXPR EXPR");
				if (! isIntCompatible($2.type)) {
                   yyerror("Arg 1 must be of type integer");
                   return(1);
                   }
                if (! isIntCompatible($3.type)) {
                   yyerror("Arg 2 must be of type integer");
                   return(1);
                   }
                $$.type = INT; 
                $$.numParams = NOT_APPLICABLE;
                $$.returnType = NOT_APPLICABLE;
				}
                      ;
N_IF_EXPR    	: T_IF N_EXPR N_EXPR N_EXPR
			{
			printRule("IF_EXPR", "if EXPR EXPR EXPR");
			
			if (! isIntCompatible($2.type)) {
               yyerror("Arg 1 must be of type integer");
               return(1);
               }
			if (! isIntCompatible($3.type) && !isStringCompatible($3.type)) {
               yyerror("Arg 2 must be of type integer or string");
               return(1);
               }
			if (! isIntCompatible($4.type) && !isStringCompatible($4.type)) {
               yyerror("Arg 3 must be of type integer or string");
               return(1);
               }
            $$.type = INT_or_STR; 
            $$.numParams = NOT_APPLICABLE;
            $$.returnType = NOT_APPLICABLE;
			}
			;
N_LET_EXPR    	: T_LET T_LPAREN N_ID_EXPR_LIST T_RPAREN N_EXPR
			{
			printRule("LET_EXPR", 
				    "let ( ID_EXPR_LIST ) EXPR");
			endScope();
			if (!isIntOrStringCompatible($5.type)) {

               yyerror("Arg 2 must be of type integer or string");
               return(1);
               }
                	
			}
			;
N_ID_EXPR_LIST  	: /* epsilon */
			{
			printRule("ID_EXPR_LIST", "epsilon");
			}
                | N_ID_EXPR_LIST T_LPAREN T_IDENT N_EXPR T_RPAREN 
			{
                	printRule("ID_EXPR_LIST", 
				    "ID_EXPR_LIST ( ID EXPR )");

                	string lexeme = string($3);
                	if (SEMANTIC_TRACE)
                  printf("___Adding %s to symbol table\n", $3);
                	bool success = scopeStack.top().addEntry
                               (SYMBOL_TABLE_ENTRY(lexeme.c_str(),
								       $4.type, $4.numParams, $4.returnType));
                	if (! success) {
                  yyerror("Multiply defined identifier");
                  return(0);
               	}
               	$$.type = $4.type;
               	$$.numParams = NOT_APPLICABLE;
            	$$.returnType = NOT_APPLICABLE;
			}
			;
N_LAMBDA_EXPR   : T_LAMBDA T_LPAREN N_ID_LIST T_RPAREN N_EXPR
			{
			printRule("LAMBDA_EXPR", 
				    "lambda ( ID_LIST ) EXPR");
					endScope();
					if( isIntOrStringCompatible($5.type))
			{
              // type, num params, and return type			
			  $$.type = FUNCTION;
			  $$.returnType = $5.type;
			  $$.numParams = numPara;
			  /*if( exprCount > numPara)
			    yyerror("Too many parameters in function call");
			  if( exprCount < numPara)
			    yyerror("Too few parameters in function call");*/
			 }
			 else
			 {
			   yyerror("Arg 2 must be of type integer or string");
			   return 1;
			 }
			 
               	
			}
			;
N_ID_LIST       : /* epsilon */
			{
			printRule("ID_LIST", "epsilon");
			}
                 | N_ID_LIST T_IDENT 
			{
			printRule("ID_LIST", "ID_LIST ID");

                	string lexeme = string($2);
                	if (SEMANTIC_TRACE)
                	  printf("___Adding %s to symbol table\n", $2);
                	bool success = scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(lexeme.c_str(), 
									    INT, UNDEFINED, UNDEFINED));
					//assume each ident is int
					numPara++;
                	if (! success) {
               	  yyerror("Multiply defined identifier");
                	  return(0);
                	}
			}
			;
N_PRINT_EXPR    	: T_PRINT N_EXPR
			{
			printRule("PRINT_EXPR", "print EXPR");
			
			if (!isIntOrStringCompatible($2.type)) {
               yyerror("Arg 1 must be of type integer or string");
               return(1);
               }
            $$.type = $2.type; 
            $$.numParams = NOT_APPLICABLE;
            $$.returnType = NOT_APPLICABLE;
			}
			;
N_INPUT_EXPR    	: T_INPUT
			{
			printRule("INPUT_EXPR", "input");
			//if (! isIntCompatible($1.type) && !isStringCompatible($1.type)) {
            //   yyerror("Arg 1 must be of type integer or string");
            //   return(1);
            //   }
			
			$$.type = INT_or_STR;//$1.type
            $$.numParams = NOT_APPLICABLE;
            $$.returnType = NOT_APPLICABLE;
			}
			;
N_EXPR_LIST     	: N_EXPR N_EXPR_LIST  
			{
			printRule("EXPR_LIST", "EXPR EXPR_LIST");
			if ($1.type == FUNCTION)
			{
				if($1.numParams > numPara)
				{
					yyerror("Too few parameters in function call");
					return(1);
				}
				else if($1.numParams < numPara)
				{
					yyerror("Too many parameters in function call");
					return(1);
				}
				$$.type = $1.returnType;
				numPara = 1;
			}
			else
			{
				if (!isIntOrStringCompatible($1.type)) {
					yyerror("Arg 1 must be of type integer or string");
					return(1);
                }
				$$.type = $2.type;
				numPara++;
			}
			/*if (!isIntOrStringCompatible($2.type)) {
               yyerror("Arg 1 must be of type integer or string");
               return(1);
               }
			exprCount++;*/
			}
                	| N_EXPR
			{
			printRule("EXPR_LIST", "EXPR");
			if ($1.type == FUNCTION)
			{
				if($1.numParams > 0)
				{
					yyerror("Too few parameters in function call");
					return(1);
				}
				$$.type = $1.returnType;
				numPara = 1;
			}
			else
			{
				if (!isIntOrStringCompatible($1.type)) {
					yyerror("Arg 1 must be of type integer or string");
					return(1);
                }
				$$.type = $1.type;
				numPara = 1;
			}
                	}
			;
N_OP	      	: T_ADD
			{
			printRule("OP", "+");
			}
               	| T_SUB
			{
			printRule("OP", "-");
			}
			| T_MULT
			{
			printRule("OP", "*");
			}
			| T_DIV
			{
			printRule("OP", "/");
			}
			;
%%

#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char* lhs, const char* rhs) {
  printf("%s -> %s\n", lhs, rhs);
  return;
}

void beginScope() {
  scopeStack.push(SYMBOL_TABLE());
  if (SEMANTIC_TRACE)
    printf("\n___Entering new scope...\n\n");
}

void endScope() {
  scopeStack.pop();
  if (SEMANTIC_TRACE)
    printf("\n___Exiting scope...\n\n");
}

bool findEntryInAnyScope(string theName) {
//cout << "\n___findEntryInAnyScope " << theName << endl;
  if (scopeStack.empty( )) return(false);
  bool found = scopeStack.top().findEntry(theName);
  if (found){
	table = &(scopeStack.top());
    return(true);
	}
  else { // check in "next higher" scope
	   SYMBOL_TABLE symbolTable = scopeStack.top( );
	   scopeStack.pop( );
	   found = findEntryInAnyScope(theName);
	   scopeStack.push(symbolTable); // restore the stack
	   return(found);  //NEW SHIT, return new member variables from SymbolTableEntry.h instead of found
  }
}

void cleanUp() {
  if (scopeStack.empty()) 
    return;
  else {
        scopeStack.pop();
        cleanUp();
  }
}

int main() {
  do {
	yyparse();
  } while (!feof(yyin));

  cleanUp();
  return 0;
}
