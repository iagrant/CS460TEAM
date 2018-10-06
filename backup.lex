
%{
/*
// Name: scanner.lex
// Author: Semantic Team (Franklin, Grant, Knutson)
// Purpose: This file is the scanner that performs lexical analysis on the tokens
//			of the input stream and program.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
int lineNum = 0;
int colNum = 0;
bool printToken = true;
%}

%option noyywrap
alpha   [A-Za-z]
dig     [0-9]
name    ({alpha}|{dig}|\$)({alpha}|{dig}|[_.\-/$])*
num1    [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2    [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number  {num1}|{num2}

%%
\n {lineNum++; colNum = 0;}
[ ]	{colNum += 1; /* skip white space */ }
"/*"    {
        int c;

        while((c = yyinput()) != 0)
            {
            if(c == '\n')
                ++lineNum;

            else if(c == '*')
                {
                if((c = yyinput()) == '/')
                    break;
                else
                    unput(c);
                }
            }
        }

\/\/.*
\!\![A-z] std::cout << "DEBUG" << std::endl;
[0-9]+ std::cout << "INTEGER_CONSTANT" << std::endl;
[0-9]+\.?[0-9]* std::cout << "FLOATING_CONSTANT" << std::endl;
\'(\\.|.)\' std::cout << "CHARACTER_CONSTANT" << std::endl;
"ENUM" std::cout << "ENUMERATION_CONSTANT" << std::endl;
\"[A-z]+\" std::cout << "STRING_LITERAL" << std::endl;
sizeof std::cout << "SIZEOF" << std::endl;
\+\+ std::cout << "INC_OP" << std::endl;
-- std::cout << "DEC_OP" << std::endl;
\<\< std::cout << "LEFT_OP" << std::endl;
>> std::cout << "RIGHT_OP" << std::endl;
\<= std::cout << "LE_OP" << std::endl;
>= std::cout << "GE_OP" << std::endl;
== std::cout << "EQ_OP" << std::endl;
!= std::cout << "NE_OP" << std::endl;
&& std::cout << "AND_OP" << std::endl;
\|\| std::cout << "OR_OP" << std::endl;
\*= std::cout << "MUL_ASSIGN" << std::endl;
\/= std::cout << "DIV_ASSIGN" << std::endl;
%= std::cout << "MOD_ASSIGN" << std::endl;
\+= std::cout << "ADD_ASSIGN" << std::endl;
-= std::cout << "SUB_ASSIGN" << std::endl;
'<<=' std::cout << "LEFT_ASSIGN" << std::endl;
'>>=' std::cout << "RIGHT_ASSIGN" << std::endl;
&= std::cout << "AND_ASSIGN" << std::endl;
\|= std::cout << "OR_ASSIGN" << std::endl;
\; std::cout << "SEMI" << std::endl;
\: std::cout << "COLON" << std::endl;
\{ std::cout << "CURLYOPEN" << std::endl;
\} std::cout << "CURLYCLOSE" << std::endl;
\[ std::cout << "BRACKETOPEN" << std::endl;
\] std::cout << "BRACKETCLOSE" << std::endl;
\, std::cout << "COMMA" << std::endl;
\. std::cout << "PERIOD" << std::endl;
\= std::cout << "EQUALS" << std::endl;
\( std::cout << "OPEN" << std::endl;
\) std::cout << "CLOSE" << std::endl;
'*' std::cout << "STAR" << std::endl;
\? std::cout << "QUESTION" << std::endl;
\| std::cout << "BAR" << std::endl;
\^ std::cout << "CARROT" << std::endl;
\& std::cout << "AMP" << std::endl;
\< std::cout << "LESS_OP" << std::endl;
\> std::cout << "GREAT_OP" << std::endl;
\+ std::cout << "PLUS" << std::endl;
\- std::cout << "MINUS" << std::endl;
\\ std::cout << "FORSLASH" << std::endl;
\% std::cout << "PERCENT" << std::endl;
\! std::cout << "BANG" << std::endl;
\~ std::cout << "TILDA" << std::endl;
typedef std::cout << "TYPEDEF" << std::endl;
extern std::cout << "EXTERN" << std::endl;
static std::cout << "STATIC" << std::endl;
auto std::cout << "AUTO" << std::endl;
register std::cout << "REGISTER" << std::endl;
char std::cout << "CHAR" << std::endl;
short std::cout << "SHORT" << std::endl;
int std::cout << "INT" << std::endl;
main std::cout << "MAIN" << std::endl;
long std::cout << "LONG" << std::endl;
signed std::cout << "SIGNED" << std::endl;
unsigned std::cout << "UNSIGNED" << std::endl;
float std::cout << "FLOAT" << std::endl;
double std::cout << "DOUBLE" << std::endl;
const std::cout << "CONST" << std::endl;
volatile std::cout << "VOLATILE" << std::endl;
void std::cout << "VOID" << std::endl;
struct std::cout << "STRUCT" << std::endl;
union std::cout << "UNION" << std::endl;
enum std::cout << "ENUM" << std::endl;
elipsis std::cout << "ELIPSIS" << std::endl;
case std::cout << "CASE" << std::endl;
default std::cout << "DEFAULT" << std::endl;
if std::cout << "IF" << std::endl;
else std::cout << "ELSE" << std::endl;
switch std::cout << "SWITCH" << std::endl;
while std::cout << "WHILE" << std::endl;
do std::cout << "DO" << std::endl;
for std::cout << "FOR" << std::endl;
goto std::cout << "GOTO" << std::endl;
continue std::cout << "CONTINUE" << std::endl;
break std::cout << "BREAK" << std::endl;
return std::cout << "RETURN" << std::endl;
{name} std::cout << "IDENTIFIER" << std::endl;
. std::cout << "ERROR" << std::endl;
%%

int main (int , char**)
{
  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0)
  ;
  return 0;
}
