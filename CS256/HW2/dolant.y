/*
  Thomas Dolan
  dolant.y
  Jennifer Leopold
  CS256, 11am MWF
  purpose: bison tutorial
  
  current status: still pretty sleepy
*/

%{
  #include<stdio.h>

  int numlines = 0;

  void printRule(const char *lhs, const char *rhs);
  int yyerror(const char *s);
  void printTokenInfo(const char* tokenType, const char* lexeme);
  
  extern "C"
  {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
  }
%}

%token T_COMMENT T_IDENT T_INTCONST T_STRCONST T_LPAREN T_RPAREN T_UNKNOWN T_PAREN_EXPR T_MATH T_IF T_LET T_ID_EXPR T_LAMBDA T_ID_LIST T_PRINT T_INPUT T_EXPR_LIST T_OP T_ADD T_SUB T_MULT T_DIV
  
%start N_START

%%
N_START			: N_EXPR
                          {
                          printRule("START", "EXPR");
                          printf("\n---Parsing /commencing---\n\n");
                          return 0;;
                          }
                        ;
N_EXPR			: T_INTCONST
                          {
                          printRule("EXPR", "INTCONST");
                          }
                        | T_STRCONST
                          {
                          printRule("EXPR", "STRCONST");
                          }
                        | T_IDENT
                          {
                          printRule("EXPR", "IDENT");
                          }
                        | T_LPAREN N_PAREN_EXPR T_RPAREN
                          {
                          printRule("EXPR", "(PARENTHESIZED_EXPR)");
                          }
                        ;
N_PAREN_EXPR		: N_MATH 
                          {
                          printRule("PARENTHESIZED_EXPR", "ARITHMETIC_EXPR");
                          }
                        | N_IF
                          {
                          printRule("PARENTHESIZED_EXPR", "IF_EXPR");
                          }
                        | N_LET
                          {
                          printRule("PARENTHESIZED_EXPR", "LET_EXPR");
                          }
                        | N_LAMBDA
                          {
                          printRule("PARENTHESIZED_EXPR", "LAMBDA_EXPR");
                          }
                        | N_PRINT
                          {
                          printRule("PARENTHESIZED_EXPR", "PRINT_RULE");
                          }
                        | N_INPUT
                          {
                          printRule("PARENTHESIZED_EXPR", "INPUT_EXPR");
                          }
                        | N_EXPR_LIST
                          {
                          printRule("PARENTHESIZED_EXPR", "EXPR_LIST_EXPR");
                          }
                        ;
N_MATH			: N_OP N_EXPR N_EXPR
                          {
                          printRule("ARITHMETIC_EXPR", "OP EXPR EXPR");
                          }
                        ;
N_OP			: T_ADD
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
N_IF			: T_IF N_EXPR N_EXPR N_EXPR
                          {
                          printRule("IF", "EXPR EXPR EXPR");
                          }
                        ;
N_LET			: T_LET T_LPAREN N_ID_EXPR_LIST T_RPAREN N_EXPR
                          {
                          printRule("LET_EXPR", "let(ID_EXPR_LIST) EXPR");
                          }
                        ;
N_ID_EXPR_LIST		: 
                          {
                          printRule("ID_EXPR_LIST", "epsilon");
                          }
                        | N_ID_EXPR_LIST T_LPAREN T_IDENT N_EXPR T_RPAREN
                          {
                          printRule("ID_EXPR_LIST", "ID_EXPR_LIST (ident EXPR)");
                          }
                        ;
N_LAMBDA		: T_LAMBDA T_LPAREN N_ID_LIST T_RPAREN N_EXPR
                          {
                          printRule("LAMBDA", "lambda( ID_LIST ) EXPR");
                          }
                        ;
N_ID_LIST		: 
                          {
                          printRule("ID_LIST", "epsilon");
                          }
                        | N_ID_LIST T_IDENT
                          {
                          printRule("ID_LIST", "ID_LIST ident");
                          }
                        ;
N_PRINT			: T_PRINT N_EXPR
                          {
                          printRule("PRINT", "print EXPR");
                          }
                        ;
N_INPUT			: T_INPUT
                          {
                          printRule("INPUT", "input");
                          }
                        ;
N_EXPR_LIST		: N_EXPR N_EXPR_LIST
                          {
                          printRule("EXPR_LIST", "EXPR EXPR_LIST");
                          }
                        | N_EXPR
                          {
                          printRule("EXPR_LIST", "EXPR");
                          }
                        ;
%%

#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs) {
  printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s) {
  printf("%s\n", s);
  return(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme) {
  printf("TOKEN: %s LEXEME: %s\n", tokenType, lexeme);
}

int main() {
  do {
    yyparse();
  }while(!feof(yyin));
  
  printf("%d lines processed\n", numLines);
  return 0;
}

