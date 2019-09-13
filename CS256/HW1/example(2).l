/*    example.l
 
 	Example of a lex specification file.
     
      To create the lexical analyzer:

      flex example.l
      g++ lex.yy.c -o lexer
      lexer < inputFileName
*/

%{
/* Definitions of constants, variables, & function prototypes go here */

#define T_IDENT	  1
#define T_INTCONST  2
#define T_UNKNOWN	  3
#define T_FOO       4

int numLines = 0;

void printTokenInfo(const char* tokenType, char* lexeme);

%}

/* Defintions of regular expressions go here */

WSPACE		[ \t\v\r]+
NEWLINE           \n

DIGIT	            [0-9]
LETTER            [a-zA-Z]

IDENT			{LETTER}({LETTER}|{DIGIT})* 
INTCONST          {DIGIT}+

%%

"foo"             {
				printTokenInfo("FOO", yytext);
				return T_INTCONST;
			}
{INTCONST}	      {
				printTokenInfo("INTCONST", yytext);
				return T_INTCONST;
			}
{IDENT}		{
				printTokenInfo("IDENT", yytext);
				return T_IDENT;
			}
{NEWLINE}		{
                        numLines++;
                  }
{WSPACE}		{ }
.			{
				printTokenInfo("UNKNOWN", yytext);
				return T_UNKNOWN;
			}

%%

// User-written code goes here

void printTokenInfo(const char* tokenType, char* lexeme) {
  printf("TOKEN: %s  LEXEME: %s\n", tokenType, lexeme);
}

// You should supply a yywrap function.
// Having it return 1 means only 1 input file will be scanned.
int yywrap(void) { return 1; }

int main(void) {
  while ( yylex() ) ;  // Keep processing tokens until 0 returned

  printf("Processed %d lines\n", numLines);
  return 0;
}

