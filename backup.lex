
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
int lineNum = 1;
int colNum = 0;
bool printToken = false;
bool printSymbol = false;
%}

%option noyywrap
alpha   [A-Za-z]
dig     [0-9]
name    ({alpha}|{dig}|\$)({alpha}|{dig}|[_.\-/$])*
num1    [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2    [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number  {num1}|{num2}

%%
\n {std::cout << "Line: " << lineNum << "   Col: " << colNum << std::endl; lineNum++; colNum = 0;}
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
\!\![A-z]       {if(printToken) {std::cout << "DEBUG" << std::endl;}}
[0-9]+          {if(printToken) {std::cout << "INTEGER_CONSTANT" << std::endl;} colNum += yyleng;}
[0-9]+\.?[0-9]* {if(printToken) {std::cout << "FLOATING_CONSTANT" << std::endl;} colNum += yyleng;}
\'(\\.|.)\'     {if(printToken) {std::cout << "CHARACTER_CONSTANT" << std::endl;} colNum += yyleng;}
"ENUM"          {if(printToken) {std::cout << "ENUMERATION_CONSTANT" << std::endl;} colNum += yyleng;}
\"[A-z]+\"      {if(printToken) {std::cout << "STRING_LITERAL" << std::endl;} colNum += yyleng;}
sizeof          {if(printToken) {std::cout << "SIZEOF" << std::endl;} colNum += yyleng;}
\+\+            {if(printToken) {std::cout << "INC_OP" << std::endl;} colNum += yyleng;}
--              {if(printToken) {std::cout << "DEC_OP" << std::endl;} colNum += yyleng;}
\<\<            {if(printToken) {std::cout << "LEFT_OP" << std::endl;} colNum += yyleng;}
>>              {if(printToken) {std::cout << "RIGHT_OP" << std::endl;} colNum += yyleng;}
\<=             {if(printToken) {std::cout << "LE_OP" << std::endl;} colNum += yyleng;}
>=              {if(printToken) {std::cout << "GE_OP" << std::endl;} colNum += yyleng;}
==              {if(printToken) {std::cout << "EQ_OP" << std::endl;} colNum += yyleng;}
!=              {if(printToken) {std::cout << "NE_OP" << std::endl;} colNum += yyleng;}
&&              {if(printToken) {std::cout << "AND_OP" << std::endl;} colNum += yyleng;}
\|\|            {if(printToken) {std::cout << "OR_OP" << std::endl;} colNum += yyleng;}
\*=             {if(printToken) {std::cout << "MUL_ASSIGN" << std::endl;} colNum += yyleng;}
\/=             {if(printToken) {std::cout << "DIV_ASSIGN" << std::endl;} colNum += yyleng;}
%=              {if(printToken) {std::cout << "MOD_ASSIGN" << std::endl;} colNum += yyleng;}
\+=             {if(printToken) {std::cout << "ADD_ASSIGN" << std::endl;} colNum += yyleng;}
-=              {if(printToken) {std::cout << "SUB_ASSIGN" << std::endl;} colNum += yyleng;}
'<<='           {if(printToken) {std::cout << "LEFT_ASSIGN" << std::endl;} colNum += yyleng;}
'>>='           {if(printToken) {std::cout << "RIGHT_ASSIGN" << std::endl;} colNum += yyleng;}
&=              {if(printToken) {std::cout << "AND_ASSIGN" << std::endl;} colNum += yyleng;}
\|=             {if(printToken) {std::cout << "OR_ASSIGN" << std::endl;} colNum += yyleng;}
\;              {if(printToken) {std::cout << "SEMI" << std::endl;} colNum += yyleng;}
\:              {if(printToken) {std::cout << "COLON" << std::endl;} colNum += yyleng;}
\{              {if(printToken) {std::cout << "CURLYOPEN" << std::endl;} colNum += yyleng;}
\}              {if(printToken) {std::cout << "CURLYCLOSE" << std::endl;} colNum += yyleng;}
\[              {if(printToken) {std::cout << "BRACKETOPEN" << std::endl;} colNum += yyleng;}
\]              {if(printToken) {std::cout << "BRACKETCLOSE" << std::endl;} colNum += yyleng;}
\,              {if(printToken) {std::cout << "COMMA" << std::endl;} colNum += yyleng;}
\.              {if(printToken) {std::cout << "PERIOD" << std::endl;} colNum += yyleng;}
\=              {if(printToken) {std::cout << "EQUALS" << std::endl;} colNum += yyleng;}
\(              {if(printToken) {std::cout << "OPEN" << std::endl;} colNum += yyleng;}
\)              {if(printToken) {std::cout << "CLOSE" << std::endl;} colNum += yyleng;}
\*              {if(printToken) {std::cout << "STAR" << std::endl;} colNum += yyleng;}
\?              {if(printToken) {std::cout << "QUESTION" << std::endl;} colNum += yyleng;}
\|              {if(printToken) {std::cout << "BAR" << std::endl;} colNum += yyleng;}
\^              {if(printToken) {std::cout << "CARROT" << std::endl;} colNum += yyleng;}
\&              {if(printToken) {std::cout << "AMP" << std::endl;} colNum += yyleng;}
\<              {if(printToken) {std::cout << "LESS_OP" << std::endl;} colNum += yyleng;}
\>              {if(printToken) {std::cout << "GREAT_OP" << std::endl;} colNum += yyleng;}
\+              {if(printToken) {std::cout << "PLUS" << std::endl;} colNum += yyleng;}
\-              {if(printToken) {std::cout << "MINUS" << std::endl;} colNum += yyleng;}
\/              {if(printToken) {std::cout << "FORSLASH" << std::endl;} colNum += yyleng;}
\%              {if(printToken) {std::cout << "PERCENT" << std::endl;} colNum += yyleng;}
\!              {if(printToken) {std::cout << "BANG" << std::endl;} colNum += yyleng;}
\~              {if(printToken) {std::cout << "TILDA" << std::endl;} colNum += yyleng;}
typedef         {if(printToken) {std::cout << "TYPEDEF" << std::endl;} colNum += yyleng;}
extern          {if(printToken) {std::cout << "EXTERN" << std::endl;} colNum += yyleng;}
static          {if(printToken) {std::cout << "STATIC" << std::endl;} colNum += yyleng;}
auto            {if(printToken) {std::cout << "AUTO" << std::endl;} colNum += yyleng;}
register        {if(printToken) {std::cout << "REGISTER" << std::endl;} colNum += yyleng;}
char            {if(printToken) {std::cout << "CHAR" << std::endl;} colNum += yyleng;}
short           {if(printToken) {std::cout << "SHORT" << std::endl;} colNum += yyleng;}
int             {if(printToken) {std::cout << "INT" << std::endl;} colNum += yyleng;}
main            {if(printToken) {std::cout << "MAIN" << std::endl;} colNum += yyleng;}
long            {if(printToken) {std::cout << "LONG" << std::endl;} colNum += yyleng;}
signed          {if(printToken) {std::cout << "SIGNED" << std::endl;} colNum += yyleng;}
unsigned        {if(printToken) {std::cout << "UNSIGNED" << std::endl;} colNum += yyleng;}
float           {if(printToken) {std::cout << "FLOAT" << std::endl;} colNum += yyleng;}
double          {if(printToken) {std::cout << "DOUBLE" << std::endl;} colNum += yyleng;}
const           {if(printToken) {std::cout << "CONST" << std::endl;} colNum += yyleng;}
volatile        {if(printToken) {std::cout << "VOLATILE" << std::endl;} colNum += yyleng;}
void            {if(printToken) {std::cout << "VOID" << std::endl;} colNum += yyleng;}
struct          {if(printToken) {std::cout << "STRUCT" << std::endl;} colNum += yyleng;}
union           {if(printToken) {std::cout << "UNION" << std::endl;} colNum += yyleng;}
enum            {if(printToken) {std::cout << "ENUM" << std::endl;} colNum += yyleng;}
elipsis         {if(printToken) {std::cout << "ELIPSIS" << std::endl;} colNum += yyleng;}
case            {if(printToken) {std::cout << "CASE" << std::endl;} colNum += yyleng;}
default         {if(printToken) {std::cout << "DEFAULT" << std::endl;} colNum += yyleng;}
if              {if(printToken) {std::cout << "IF" << std::endl;} colNum += yyleng;}
else            {if(printToken) {std::cout << "ELSE" << std::endl;} colNum += yyleng;}
switch          {if(printToken) {std::cout << "SWITCH" << std::endl;} colNum += yyleng;}
while           {if(printToken) {std::cout << "WHILE" << std::endl;} colNum += yyleng;}
do              {if(printToken) {std::cout << "DO" << std::endl;} colNum += yyleng;}
for             {if(printToken) {std::cout << "FOR" << std::endl;} colNum += yyleng;}
goto            {if(printToken) {std::cout << "GOTO" << std::endl;} colNum += yyleng;}
continue        {if(printToken) {std::cout << "CONTINUE" << std::endl;} colNum += yyleng;}
break           {if(printToken) {std::cout << "BREAK" << std::endl;} colNum += yyleng;}
return          {if(printToken) {std::cout << "RETURN" << std::endl;} colNum += yyleng;}
{name}          {if(printToken) {std::cout << "IDENTIFIER" << std::endl;}}
.               {if(printToken) {std::cout << "ERROR" << std::endl;}}
%%

int main (int argc, char** argv)
{
    std::string tokenFlag = "-dl";
	  std::string symbolFlag= "-ds";

    // Check command line args for debug symbols
    for (int i = 0; i < argc; i++) {
        if((tokenFlag.compare(argv[i])) == 0)
        {
            printToken = true;
        }
    }

    FlexLexer* lexer = new yyFlexLexer;
    while(lexer->yylex() != 0)
    ;
    return 0;
}
