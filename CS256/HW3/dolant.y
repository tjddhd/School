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
#include <stack>
#include "SymbolTable.h"

int lineNum = 1; 
stack<SYMBOL_TABLE> scopeStack;

void printRule(const char *, const char *);

int yyerror(const char *s) {
  printf("Line %d: %s\n", lineNum, s);
  //deallocate memory
  exit(1);
}

void beginScope();
void endScope();

bool findEntryInAnyScope(string theName);

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
}

%}

%union{
  char* text;
};

/*
 *	Token declarations
*/
%token  T_LPAREN T_RPAREN 
%token  T_IF T_LET T_LAMBDA T_PRINT T_INPUT
%token  T_ADD  T_SUB  T_MULT  T_DIV	 
%token  T_INTCONST T_STRCONST T_IDENT T_UNKNOWN
%type<text> T_IDENT
/*
 *	Starting point.
 */
%start  N_START

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
			}
                | T_STRCONST
			{
			printRule("EXPR", "STRCONST");
			}
                | T_IDENT
                {
            yprRule("EXPR", "IDENT");
            bool found = findEntryInAnyScope(string($1));
			printRule("EXPR", "IDENT");
			}
                | T_LPAREN N_PARENTHESIZED_EXPR T_RPAREN
                {
			printRule("EXPR", "( PARENTHESIZED_EXPR )");
			}
			;
N_PARENTHESIZED_EXPR	: N_ARITHMETIC_EXPR 
				{
				printRule("PARENTHESIZED_EXPR",
                                "ARITHMETIC_EXPR");
				}
                      | N_IF_EXPR 
				{
				printRule("PARENTHESIZED_EXPR", "IF_EXPR");
				}
                      | N_LET_EXPR 
				{
				printRule("PARENTHESIZED_EXPR", 
                                "LET_EXPR");
				}
                      | N_LAMBDA_EXPR 
				{
				printRule("PARENTHESIZED_EXPR", 
				          "LAMBDA_EXPR");
				}
                      | N_PRINT_EXPR 
				{
				printRule("PARENTHESIZED_EXPR", 
					    "PRINT_EXPR");
				}
                      | N_INPUT_EXPR 
				{
				printRule("PARENTHESIZED_EXPR",
					    "INPUT_EXPR");
				}
                     | N_EXPR_LIST 
				{
				printRule("PARENTHESIZED_EXPR",
				          "EXPR_LIST");
				}
				;
N_ARITHMETIC_EXPR	: N_OP N_EXPR N_EXPR
				{
				printRule("ARITHMETIC_EXPR", 
				          "OP EXPR EXPR");
				}
                     	;
N_IF_EXPR    	: T_IF N_EXPR N_EXPR N_EXPR
			{
			printRule("IF_EXPR", "if EXPR EXPR EXPR");
			}
			;
N_LET_EXPR      : T_LET T_LPAREN N_ID_EXPR_LIST T_RPAREN N_EXPR
			{
			printRule("LET_EXPR", 
				    "let ( ID_EXPR_LIST ) EXPR");
			endScope();
			}
			;
N_ID_EXPR_LIST  : /* epsilon */
			{
			printRule("ID_EXPR_LIST", "epsilon");
			}
                | N_ID_EXPR_LIST T_LPAREN T_IDENT N_EXPR T_RPAREN 
			{
			printRule("ID_EXPR_LIST", 
                          "ID_EXPR_LIST ( IDENT EXPR )");
			}
			;
N_LAMBDA_EXPR   : T_LAMBDA T_LPAREN N_ID_LIST T_RPAREN N_EXPR
			{
			printRule("LAMBDA_EXPR", 
				    "lambda ( ID_LIST ) EXPR");
			endScope();
			}
			;
N_ID_LIST       : /* epsilon */
			{
			printRule("ID_LIST", "epsilon");
			}
                | N_ID_LIST T_IDENT 
			{
			printRule("ID_LIST", "ID_LIST IDENT");
			}
			;
N_PRINT_EXPR    : T_PRINT N_EXPR
			{
			printRule("PRINT_EXPR", "print EXPR");
			}
			;
N_INPUT_EXPR    : T_INPUT
			{
			printRule("INPUT_EXPR", "input");
			}
			;
N_EXPR_LIST     : N_EXPR N_EXPR_LIST  
			{
			printRule("EXPR_LIST", "EXPR EXPR_LIST");
			}
                | N_EXPR
			{
			printRule("EXPR_LIST", "EXPR");
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

void printRule(const char *lhs, const char *rhs) {
  printf("%s -> %s\n", lhs, rhs);
  return;
}

void beginScope(){
  scopeStack.push(SYMBOL_TABLE());
  printf("\n___Entering new scope...\n\n");
}

void endScope(){
  scopeStack.pop();
  printf("\n___Exiting scope...\n\n");
}

bool findEntryInAnyScope(string theName){
  if (scopeStack.empty( )) return(false);
  bool found = scopeStack.top( ).findEntry(theName);
  if (found)
    return(true);
  else {
 	SYMBOL_TABLE symbolTable = scopeStack.top( );
	scopeStack.pop( );
	found = findEntryInAnyScope(theName);
	scopeStack.push(symbolTable); // restore the stack
	return(found);
	}
}

int main() {
  do {
	yyparse();
  } while (!feof(yyin));

  return 0;
}
