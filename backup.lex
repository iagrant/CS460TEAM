
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
bool printToken = false;
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

\/\/.*\n
\!\![A-z] {if(printToken) {std::cout << "DEBUG" << std::endl;}}
[0-9]+ {if(printToken) {std::cout << "INTEGER_CONSTANT" << std::endl;}}
[0-9]+\.?[0-9]* {if(printToken) {std::cout << "FLOATING_CONSTANT" << std::endl;}}
\'(\\.|.)\' {if(printToken) {std::cout << "CHARACTER_CONSTANT" << std::endl;}}
"ENUM" {if(printToken) {std::cout << "ENUMERATION_CONSTANT" << std::endl;}}
\"[A-z]+\" {if(printToken) {std::cout << "STRING_LITERAL" << std::endl;}}
sizeof {if(printToken) {std::cout << "SIZEOF" << std::endl;}}
\+\+ {if(printToken) {std::cout << "INC_OP" << std::endl;}}
-- {if(printToken) {std::cout << "DEC_OP" << std::endl;}}
\<\< {if(printToken) {std::cout << "LEFT_OP" << std::endl;}}
>> {if(printToken) {std::cout << "RIGHT_OP" << std::endl;}}
\<= {if(printToken) {std::cout << "LE_OP" << std::endl;}}
>= {if(printToken) {std::cout << "GE_OP" << std::endl;}}
== {if(printToken) {std::cout << "EQ_OP" << std::endl;}}
!= {if(printToken) {std::cout << "NE_OP" << std::endl;}}
&& {if(printToken) {std::cout << "AND_OP" << std::endl;}}
\|\| {if(printToken) {std::cout << "OR_OP" << std::endl;}}
\*= {if(printToken) {std::cout << "MUL_ASSIGN" << std::endl;}}
\/= {if(printToken) {std::cout << "DIV_ASSIGN" << std::endl;}}
%= {if(printToken) {std::cout << "MOD_ASSIGN" << std::endl;}}
\+= {if(printToken) {std::cout << "ADD_ASSIGN" << std::endl;}}
-= {if(printToken) {std::cout << "SUB_ASSIGN" << std::endl;}}
'<<=' {if(printToken) {std::cout << "LEFT_ASSIGN" << std::endl;}}
'>>=' {if(printToken) {std::cout << "RIGHT_ASSIGN" << std::endl;}}
&= {if(printToken) {std::cout << "AND_ASSIGN" << std::endl;}}
\|= {if(printToken) {std::cout << "OR_ASSIGN" << std::endl;}}
\; {if(printToken) {std::cout << "SEMI" << std::endl;}}
\: {if(printToken) {std::cout << "COLON" << std::endl;}}
\{if(printToken) { {std::cout << "CURLYOPEN" << std::endl;}}
\} {if(printToken) {std::cout << "CURLYCLOSE" << std::endl;}}
\[ {if(printToken) {std::cout << "BRACKETOPEN" << std::endl;}}
\] {if(printToken) {std::cout << "BRACKETCLOSE" << std::endl;}}
\, {if(printToken) {std::cout << "COMMA" << std::endl;}}
\. {if(printToken) {std::cout << "PERIOD" << std::endl;}}
\= {if(printToken) {std::cout << "EQUALS" << std::endl;}}
\( {if(printToken) {std::cout << "OPEN" << std::endl;}}
\) {if(printToken) {std::cout << "CLOSE" << std::endl;}}
'*' {if(printToken) {std::cout << "STAR" << std::endl;}}
\? {if(printToken) {std::cout << "QUESTION" << std::endl;}}
\| {if(printToken) {std::cout << "BAR" << std::endl;}}
\^ {if(printToken) {std::cout << "CARROT" << std::endl;}}
\& {if(printToken) {std::cout << "AMP" << std::endl;}}
\< {if(printToken) {std::cout << "LESS_OP" << std::endl;}}
\> {if(printToken) {std::cout << "GREAT_OP" << std::endl;}}
\+ {if(printToken) {std::cout << "PLUS" << std::endl;}}
\- {if(printToken) {std::cout << "MINUS" << std::endl;}}
\\ {if(printToken) {std::cout << "FORSLASH" << std::endl;}}
\% {if(printToken) {std::cout << "PERCENT" << std::endl;}}
\! {if(printToken) {std::cout << "BANG" << std::endl;}}
\~ {if(printToken) {std::cout << "TILDA" << std::endl;}}
typedef {if(printToken) {std::cout << "TYPEDEF" << std::endl;}}
extern {if(printToken) {std::cout << "EXTERN" << std::endl;}}
static {if(printToken) {std::cout << "STATIC" << std::endl;}}
auto {if(printToken) {std::cout << "AUTO" << std::endl;}}
register {if(printToken) {std::cout << "REGISTER" << std::endl;}}
char {if(printToken) {std::cout << "CHAR" << std::endl;}}
short {if(printToken) {std::cout << "SHORT" << std::endl;}}
int {if(printToken) {std::cout << "INT" << std::endl;}}
main {if(printToken) {std::cout << "MAIN" << std::endl;}}
long {if(printToken) {std::cout << "LONG" << std::endl;}}
signed {if(printToken) {std::cout << "SIGNED" << std::endl;}}
unsigned {if(printToken) {std::cout << "UNSIGNED" << std::endl;}}
float {if(printToken) {std::cout << "FLOAT" << std::endl;}}
double {if(printToken) {std::cout << "DOUBLE" << std::endl;}}
const {if(printToken) {std::cout << "CONST" << std::endl;}}
volatile {if(printToken) {std::cout << "VOLATILE" << std::endl;}}
void {if(printToken) {std::cout << "VOID" << std::endl;}}
struct {if(printToken) {std::cout << "STRUCT" << std::endl;}}
union {if(printToken) {std::cout << "UNION" << std::endl;}}
enum {if(printToken) {std::cout << "ENUM" << std::endl;}}
elipsis {if(printToken) {std::cout << "ELIPSIS" << std::endl;}}
case {if(printToken) {std::cout << "CASE" << std::endl;}}
default {if(printToken) {std::cout << "DEFAULT" << std::endl;}}
if {if(printToken) {std::cout << "IF" << std::endl;}}
else {if(printToken) {std::cout << "ELSE" << std::endl;}}
switch {if(printToken) {std::cout << "SWITCH" << std::endl;}}
while {if(printToken) {std::cout << "WHILE" << std::endl;}}
do {if(printToken) {std::cout << "DO" << std::endl;}}
for {if(printToken) {std::cout << "FOR" << std::endl;}}
goto {if(printToken) {std::cout << "GOTO" << std::endl;}}
continue {if(printToken) {std::cout << "CONTINUE" << std::endl;}}
break {if(printToken) {std::cout << "BREAK" << std::endl;}}
return {if(printToken) {std::cout << "RETURN" << std::endl;}}
{name} {if(printToken) {std::cout << "IDENTIFIER" << std::endl;}}
. {if(printToken){std::cout << "ERROR" << std::endl;}}
%%

int main (int , char**)
{
  FlexLexer* lexer = new yyFlexLexer;
  while(lexer->yylex() != 0)
  ;
  return 0;
}
