/* Thomas Dolan
   CS256, FS2012
   12272974
   purpose: lexical analysis exercise

   instructions for use:
   flex example.l
   g++ lex.yy.c -o lexer
   lexer < inputFileName

   current status: sleepy
*/

%{

#define T_LET 1
#define T_LAMBDA 2
#define T_INPUT 3
#define T_PRINT 4
#define T_IF 5
#define T_LPAREN 6
#define T_RPAREN 7
#define T_ADD 8
#define T_MULT 9
#define T_DIV 10
#define T_SUB 11
#define T_INTCONST 12
#define T_STRCONST 13
#define T_UNKNOWN 14
#define T_COMMENT 15
#define T_IDENT 16

int numLines = 0;

void printTokenInfo(const char* tokenType, char* lexeme);

%}

WSPACE		[ \t\v\r]+
NEWLINE		\n

DIGIT		[0-9]
LETTER		[a-zA-Z]

IDENT		[_]*{LETTER}({LETTER}|{DIGIT}|[_])*
INTCONST	{DIGIT}+

STRCONST	(({LETTER}|{DIGIT}|[_!?+-])*)

ADD		{\+}
SUB		{\-}
MULT		{\*}
DIV		{\/}

LPAREN		{\(}
RPAREN		{\)}
COMMENT		({LETTER}|{DIGIT}|{WSPACE}|[?!_])*

%%

"let"		{
                  printTokenInfo("LET", yytext);
                  return T_LET;
               }
"if"		{
                  printTokenInfo("IF", yytext);
                  return T_IF;
               }
"lambda"	{	
                  printTokenInfo("LAMBDA", yytext);
                  return T_LAMBDA;
               }
"input"		{
                  printTokenInfo("INPUT", yytext);
                  return T_INPUT;
               }
"print"		{
                  printTokenInfo("PRINT", yytext);
                  return T_PRINT;
               }
"("		{
                  printTokenInfo("LPAREN", yytext);
                  return T_LPAREN;
               }
")"		{
                  printTokenInfo("RPAREN", yytext);
                  return T_RPAREN;
               }
{NEWLINE}	{
                  numLines++;
               }
{WSPACE}	{ }
"+"		{
                  printTokenInfo("ADD", yytext);
                  return T_ADD;
               }
"*"		{
                  printTokenInfo("MULT", yytext);
                  return T_MULT;
               }
"/"		{
                  printTokenInfo("DIV", yytext);
                  return T_DIV;
               }
"-"		{
                  printTokenInfo("SUB", yytext);
                  return T_SUB;
               }
{IDENT}		{
                  printTokenInfo("IDENT", yytext);
                  return T_IDENT;
               }
(\+|\-)*{INTCONST}	{
                  printTokenInfo("INTCONST", yytext);
                  return T_INTCONST;
               }
\"{STRCONST}\"	{
                  printTokenInfo("STRCONST", yytext);
                  return T_STRCONST;
               }
"%"{COMMENT}	{
                  numLines++;
               }
.		{
                  printTokenInfo("UNKNOWN", yytext);
                  return T_UNKNOWN;
               }

%%

void printTokenInfo(const char* tokenType, char* lexeme) {
  printf("TOKEN: %s LEXEME: %s\n", tokenType, lexeme);
}

int yywrap(void) { return 1; }

int main(void) {
  while ( yylex() ) ;
  printf("Processed %d lines\n", numLines);
  return 0;
}


