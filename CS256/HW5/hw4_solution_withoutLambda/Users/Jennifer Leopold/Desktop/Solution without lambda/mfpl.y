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
#include <string>
#include <stack>
#include <iostream>
#include <stdlib.h>
#include "SymbolTable.h"
#include <cstdlib>
using namespace std;



int lineNum = 1; 

stack<SYMBOL_TABLE> scopeStack;    // stack of scope hashtables

bool isIntCompatible(const int theType);
bool isStrCompatible(const int theType);
bool isIntOrStrCompatible(const int theType);

void beginScope();
void endScope();
void cleanUp();
TYPE_INFO findEntryInAnyScope(const string theName);

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
  operator OP;
};

/*
 *	Token declarations
*/
%token  T_LPAREN T_RPAREN 
%token  T_IF T_LET T_PRINT T_INPUT
%token  T_ADD  T_SUB  T_MULT  T_DIV	 
%token  T_INTCONST T_STRCONST T_IDENT T_UNKNOWN

%type	<text> T_IDENT T_STRCONST T_INTCONST
%type <typeInfo> N_EXPR N_PARENTHESIZED_EXPR N_ARITHMETIC_EXPR  
%type <typeInfo> N_IF_EXPR N_PRINT_EXPR N_INPUT_EXPR 
%type <typeInfo> N_LET_EXPR N_EXPR_LIST 
%type <OP> N_OP

/*
 *	Starting point.
 */
%start		N_START

/*
 *	Translation rules.
 */
%%
N_START		: N_EXPR
			{
			printRule("START", "EXPR");
			printf("\n---- Completed parsing ----\n\n");
			printf("\nValue of the expression is: ");
			if($1.type==INT)
			{
				printf("%d\n", $1.intVal);
			}
			else if($1.type==STR)
			{
				printf("%s\n", $1.exprVal);
			}
			return 0;
			}
			;
N_EXPR		: T_INTCONST
			{
			printRule("EXPR", "INTCONST");
                	$$.type = INT;
					$$.intVal = atoi($1);
			}
               	| T_STRCONST
			{
			printRule("EXPR", "STRCONST");
                	$$.type = STR; 
					strcpy($$.exprVal,$1);
			}
                | T_IDENT
                {
			printRule("EXPR", "ID");
                	string ident = string($1);
                	TYPE_INFO exprTypeInfo = 
						findEntryInAnyScope(ident);
                	if (exprTypeInfo.type == UNDEFINED) {
                	  yyerror("Undefined identifier");
                	  return(0);
					}
					$$.type = exprTypeInfo.type; 
					if(exprTypeInfo.type == INT)
					{
						$$.intVal = exprTypeInfo.intVal;
					}
					else if(exprTypeInfo.type == STR)
					{
						strcpy($$.exprVal, exprTypeInfo.exprVal);
					}
			}
                | T_LPAREN N_PARENTHESIZED_EXPR T_RPAREN
                {
			printRule("EXPR", "( PARENTHESIZED_EXPR )");
               	$$.type = $2.type; 
				if(exprTypeInfo.type == INT)
					{
						$$.intVal = $2.intVal;
					}
					else if(exprTypeInfo.type == STR)
					{
						strcpy($$.exprVal, $2.exprVal);
					}
			}
			;
N_PARENTHESIZED_EXPR	: N_ARITHMETIC_EXPR 
				{
				printRule("PARENTHESIZED_EXPR",
					     "ARITHMETIC_EXPR");
                      $$.type = $1.type;
					if($1.type == INT)
					{
						$$.intVal = $1.intVal;
					}
					else if($1.type == STR)
					{
						strcpy($$.exprVal, $1.exprVal);
					}					
				}
                      | N_IF_EXPR 
				{
				printRule("PARENTHESIZED_EXPR", "IF_EXPR");
                     	$$.type = $1.type; 
					if($1.type == INT)
					{
						$$.intVal = $1.intVal;
					}
					else if($1.type == STR)
					{
						strcpy($$.exprVal, $1.exprVal);
					}	
				}
                      | N_LET_EXPR 
				{
				printRule("PARENTHESIZED_EXPR","LET_EXPR");
                     	$$.type = $1.type; 
					if($1.type == INT)
					{
						$$.intVal = $1.intVal;
					}
					else if($1.type == STR)
					{
						strcpy($$.exprVal, $1.exprVal);
					}	
				}
                     	| N_PRINT_EXPR 
				{
				printRule("PARENTHESIZED_EXPR", 
					     "PRINT_EXPR");
                     	$$.type = $1.type; 
					if($1.type == INT)
					{
						$$.intVal = $1.intVal;
					}
					else if($1.type == STR)
					{
						strcpy($$.exprVal, $1.exprVal);
					}	
				}
                     	| N_INPUT_EXPR 
				{
				printRule("PARENTHESIZED_EXPR", 
					     "INPUT_EXPR");
                      $$.type = $1.type; 
					if($1.type == INT)
					{
						$$.intVal = $1.intVal;
					}
					else if($1.type == STR)
					{
						strcpy($$.exprVal, $1.exprVal);
					}	
				}
                     	| N_EXPR_LIST 
				{
				printRule("PARENTHESIZED_EXPR",
					     "EXPR_LIST");
                     	$$.type = $1.type; 
					if($1.type == INT)
					{
						$$.intVal = $1.intVal;
					}
					else if($1.type == STR)
					{
						strcpy($$.exprVal, $1.exprVal);
					}	
				}
				;
N_ARITHMETIC_EXPR	: N_OP N_EXPR N_EXPR
				{
				printRule("ARITHMETIC_EXPR", 
					     "OP EXPR EXPR");
                     	if (! isIntCompatible($2.type)) {
                        yyerror("Arg 1 must be of type integer");
                        return(0);
                     	}
                     	if (! isIntCompatible($3.type)) {
                        yyerror("Arg 2 must be of type integer");
                        return(0);
                     	}
                $$.type = INT;
				switch ($1.op)
				{
				case ADD:
					$$.intVal = ($1.intVal) + ($2.intVal);
					break;
				case SUB:
					$$.intVal = ($1.intVal) - ($2.intVal);
					break;
				case MULT:
					$$.intVal = ($1.intVal) * ($2.intVal);
					break;
				case DIV:
					if($2.intVal != 0)
						$$.intVal = ($1.intVal) / ($2.intVal);
					else
						yyerror("Attempted division by zero");
					break;
				}
				}
                      ;
N_IF_EXPR    	: T_IF N_EXPR N_EXPR N_EXPR
			{
			printRule("IF_EXPR", "if EXPR EXPR EXPR");
                if (! isIntCompatible($2.type)) {
                  yyerror("Arg 1 must be of type integer");
                  return(0);
                }
                if (! isIntOrStrCompatible($3.type)) {
                  yyerror("Arg 2 must be of type integer or string");
                  return(0);
                }
                if (! isIntOrStrCompatible($4.type)) {
                  yyerror("Arg 3 must be of type integer or string");
                  return(0);
                }
				if($2.intVal != 0)
				{
					$$.type = $3.type;
					if($3.type == INT)
					{
						$$.intVal = $3.intVal;
					}
					else if($3.type == STR)
					{
						strcpy($$.exprVal, $3.exprVal);
					}
				}
				else
				{
					$$.type = $4.type;
					if($4.type == INT)
					{
						$$.intVal = $4.intVal;
					}
					else if($4.type == STR)
					{
						strcpy($$.exprVal, $4.exprVal);
					}
				}
			}
			;
N_LET_EXPR      : T_LET T_LPAREN N_ID_EXPR_LIST T_RPAREN N_EXPR
			{
			printRule("LET_EXPR", 
				    "let ( ID_EXPR_LIST ) EXPR");
                endScope();
                if (! isIntOrStrCompatible($5.type)) {
                  yyerror("Arg 2 must be of type integer or string");
                  return(0);
                }
                $$.type = $5.type; 
				if($$.type == INT)
				{
					$$.intVal = $5.intVal;
				}
				else if($$.type == STR)
				{
					strcpy($$.exprVal, $5.exprVal);
				}
			}
			;
N_ID_EXPR_LIST  : /* epsilon */
			{
			printRule("ID_EXPR_LIST", "epsilon");
			}
                | N_ID_EXPR_LIST T_LPAREN T_IDENT N_EXPR T_RPAREN 
			{
                 printRule("ID_EXPR_LIST", 
					"ID_EXPR_LIST ( ID EXPR )");

                 string lexeme = string($3);
                 TYPE_INFO exprTypeInfo = $4;
                 printf("___Adding %s to symbol table\n", $3);
                 bool success = scopeStack.top().addEntry
                                (SYMBOL_TABLE_ENTRY(lexeme,
									 exprTypeInfo));
                 if (! success) {
                   yyerror("Multiply defined identifier");
                   return(0);
                 }
			}
			;
N_PRINT_EXPR    : T_PRINT N_EXPR
			{
			printRule("PRINT_EXPR", "print EXPR");
                if (! isIntOrStrCompatible($2.type)) {
                  yyerror("Arg 1 must be of type integer or string");
                  return(0);
                }
                $$.type = $2.type;
				if($2.type == INT)
				{
					$$.intVal = $2.intVal;
					printf("%d\n",$2.intVal);
				}
				else if($2.type == STR)
				{
					strcpy($$.exprVal, $2.exprVal);
					printf("%s\n", $2.exprVal);
				}

			}
			;
N_INPUT_EXPR    : T_INPUT
			{
			printRule("INPUT_EXPR", "input");
			string buff;
			getline(cin, buff);
			if(buff[0] == '+' || buff[0] == '-' || buff[0] == '0' || buff[0] == '1' || buff[0] == '2' || buff[0] == '3' || buff[0] == '4' || buff[0] == '5' || buff[0] == '6' || buff[0] == '7' || buff[0] == '8' || buff[0] == '9')
			{
				$$.type = INT;
				$$.intVal = atoi(buff.c_str());
			}
			else
			{
				$$.type = STR;
				strcpy($$.exprVal, buff.c_str());
			}
			}
			;
N_EXPR_LIST     : N_EXPR N_EXPR_LIST  
			{
			printRule("EXPR_LIST", "EXPR EXPR_LIST");
                $$.type = $2.type;
				if($2.type == INT)
				{
					$$.intVal = $2.intVal;
				}
				else if($2.type == STR)
				{
					strcpy($$.exprVal, $2.exprVal);
				}
			}
                | N_EXPR
			{
			printRule("EXPR_LIST", "EXPR");
                $$.type = $1.type;
				if($1.type == INT)
				{
					$$.intVal = $1.intVal;
				}
				else if($1.type == STR)
				{
					strcpy($$.exprVal, $1.exprVal);
				}
			}
			;
N_OP	      : T_ADD
		{
		printRule("OP", "+");
		$$.op = ADD;
		}
           | T_SUB
		{
		printRule("OP", "-");
		$$.op = SUB;
		}
		| T_MULT
		{
		printRule("OP", "*");
		$$.op = MULT;
		}
		| T_DIV
		{
		printRule("OP", "/");
		$$.op = DIV;
		}
		;
%%

#include "lex.yy.c"
extern FILE *yyin;

bool isIntCompatible(const int theType) {
  return((theType == INT) || (theType == INT_or_STR));
}

bool isStrCompatible(const int theType) {
  return((theType == STR) || (theType == INT_or_STR));
}

bool isIntOrStrCompatible(const int theType) {
  return(isStrCompatible(theType) || isIntCompatible(theType));
}

void printRule(const char* lhs, const char* rhs) {
  printf("%s -> %s\n", lhs, rhs);
  return;
}

void beginScope() {
  scopeStack.push(SYMBOL_TABLE());
  printf("\n___Entering new scope...\n\n");
}

void endScope() {
  scopeStack.pop();
  printf("\n___Exiting scope...\n\n");
}

TYPE_INFO findEntryInAnyScope(const string theName) {
  TYPE_INFO info = {UNDEFINED};
  if (scopeStack.empty( )) return(info);
  info = scopeStack.top().findEntry(theName);
  if (info.type != UNDEFINED)
    return(info);
  else { // check in "next higher" scope
	   SYMBOL_TABLE symbolTable = scopeStack.top( );
	   scopeStack.pop( );
	   info = findEntryInAnyScope(theName);
	   scopeStack.push(symbolTable); // restore the stack
	   return(info);
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

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("You must specify a file in the command line!\n");
		exit(1);
	}
	yyin = fopen(argv[1], "r");
	do {
		yyparse();
	} while (!feof(yyin));
	return 0;
}
