
%{
/*
// Name: scanner.lex
// Author: Semantic Team (Franklin, Grant, Knutson)
// Purpose: This file is the scanner that performs lexical analysis on the tokens 
//			of the input stream and program.
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include "C_grammar.tab.h"
int yyline = 0;
int colNum = 0;	
bool printToken = true;
%}

%%
\n {yyline++; colNum = 0;}
[ ]	{colNum += 1; /* skip white space */ }
[\t] {colNum += yyleng;}
"\*"(\n|.)*"*/"	{ /* skip comment */ }
"//".* { /* skip comment */ }
\!\![A-z] {yylval.sval = yytext[0] + "\0"; if(printToken) {std::cout << "DEBUG" << std::endl;} return DEBUG;}
let[let_]*let|let {colNum += yyleng; if(printToken) {std::cout << "IDENTIFIER" << std::endl;} return IDENTIFIER;}
[0-9]+ {yylval.ival = atoi(yytext); colNum += yyleng; if(printToken) {std::cout << "INTEGER_CONSTANT" << std::endl;} return INTEGER_CONSTANT;}
[0-9]+\.?[0-9]* {yylval.fval = stof(yytext); colNum += yyleng; if(printToken) {std::cout << "FLOATING_CONSTANT" << std::endl;} return FLOATING_CONSTANT;}
\'(\\.|.)\' {yylval.cval = yytext[0]; colNum += yyleng; if(printToken) {std::cout << "CHARACTER_CONSTANT" << std::endl;} return CHARACTER_CONSTANT;}
"ENUM" ENUMERATION_CONSTANT {colNum += yyleng; if(printToken) {std::cout << "ENUMERATION_CONSTANT" << std::endl;} return ENUMERATION_CONSTANT;}
\"[A-z]+\" {yylval.sval = yytext + "\0"; colNum += yyleng; if(printToken) {std::cout << "STRING_LITERAL" << std::endl;} return STRING_LITERAL;}
SIZEOF {colNum += yyleng; if(printToken) {std::cout << "SIZEOF" << std::endl;} return SIZEOF;}
\+\+ {colNum += yyleng; if(printToken) {std::cout << "INC_OP" << std::endl;} return INC_OP;}
-- {colNum += yyleng; if(printToken) {std::cout << "DEC_OP" << std::endl;} return DEC_OP;}
\<\< {colNum += yyleng; if(printToken) {std::cout << "LEFT_OP" << std::endl;} return LEFT_OP;}
>> {colNum += yyleng; if(printToken) {std::cout << "RIGHT_OP" << std::endl;} return RIGHT_OP;}
\<= {colNum += yyleng; if(printToken) {std::cout << "LE_OP" << std::endl;} return LE_OP;}
>= {colNum += yyleng; if(printToken) {std::cout << "GE_OP" << std::endl;} return GE_OP;}
== {colNum += yyleng; if(printToken) {std::cout << "EQ_OP" << std::endl;} return EQ_OP;}
!= {colNum += yyleng; if(printToken) {std::cout << "NE_OP" << std::endl;} return NE_OP;}
&& {colNum += yyleng; if(printToken) {std::cout << "AND_OP" << std::endl;} return AND_OP;}
\|\| {colNum += yyleng; if(printToken) {std::cout << "OR_OP" << std::endl;} return OR_OP;}
\*= {colNum += yyleng; if(printToken) {std::cout << "MUL_ASSIGN" << std::endl;} return MUL_ASSIGN;}
\/= {colNum += yyleng; if(printToken) {std::cout << "DIV_ASSIGN" << std::endl;} return DIV_ASSIGN;}
%= {colNum += yyleng; if(printToken) {std::cout << "MOD_ASSIGN" << std::endl;} return MOD_ASSIGN;}
\+= {colNum += yyleng; if(printToken) {std::cout << "ADD_ASSIGN" << std::endl;} return ADD_ASSIGN;}
-= {colNum += yyleng; if(printToken) {std::cout << "SUB_ASSIGN" << std::endl;} return SUB_ASSIGN;}
'<<=' {colNum += yyleng; if(printToken) {std::cout << "LEFT_ASSIGN" << std::endl;} return LEFT_ASSIGN;}
'>>=' {colNum += yyleng; if(printToken) {std::cout << "RIGHT_ASSIGN" << std::endl;} return RIGHT_ASSIGN;}
&= {colNum += yyleng; if(printToken) {std::cout << "AND_ASSIGN" << std::endl;} return AND_ASSIGN;}
\|= {colNum += yyleng; if(printToken) {std::cout << "OR_ASSIGN" << std::endl;} return OR_ASSIGN;}
TYPEDEF_NAME {colNum += yyleng; if(printToken) {std::cout << "TYPEDEF_NAME" << std::endl;} return TYPEDEF_NAME;}
\; {colNum += yyleng; if(printToken) {std::cout << "SEMI" << std::endl;} return SEMI;}
\: {colNum += yyleng; if(printToken) {std::cout << "COLON" << std::endl;} return COLON;}
\{ {colNum += yyleng; if(printToken) {std::cout << "CURLYOPEN" << std::endl;} return CURLYOPEN;}
\} {colNum += yyleng; if(printToken) {std::cout << "CURLYCLOSE" << std::endl;} return CURLYCLOSE;}
\[ {colNum += yyleng; if(printToken) {std::cout << "BRACKETOPEN" << std::endl;} return BRACKETOPEN;}
\] {colNum += yyleng; if(printToken) {std::cout << "BRACKETCLOSE" << std::endl;} return BRACKETCLOSE;}
\, {colNum += yyleng; if(printToken) {std::cout << "COMMA" << std::endl;} return COMMA;}
\. {colNum += yyleng; if(printToken) {std::cout << "PERIOD" << std::endl;} return PERIOD;}
\= {colNum += yyleng; if(printToken) {std::cout << "EQUALS" << std::endl;} return EQUALS;}
\( {colNum += yyleng; if(printToken) {std::cout << "OPEN" << std::endl;} return OPEN;}
\) {colNum += yyleng; if(printToken) {std::cout << "CLOSE" << std::endl;} return CLOSE;}
'*' {colNum += yyleng; if(printToken) {std::cout << "STAR" << std::endl;} return STAR;}
\? {colNum += yyleng; if(printToken) {std::cout << "QUESTION" << std::endl;} return QUESTION;}
'\|' {colNum += yyleng; if(printToken) {std::cout << "BAR" << std::endl;} return BAR;}
\^ {colNum += yyleng; if(printToken) {std::cout << "CARROT" << std::endl;} return CARROT;}
'&' {colNum += yyleng; if(printToken) {std::cout << "AMP" << std::endl;} return AMP;}
\< {colNum += yyleng; if(printToken) {std::cout << "LESS_OP" << std::endl;} return LESS_OP;}
\> {colNum += yyleng; if(printToken) {std::cout << "GREAT_OP" << std::endl;} return GREAT_OP;}
'\+' {colNum += yyleng; if(printToken) {std::cout << "PLUS" << std::endl;} return PLUS;}
'-' {colNum += yyleng; if(printToken) {std::cout << "MINUS" << std::endl;} return MINUS;}
\\ {colNum += yyleng; if(printToken) {std::cout << "FORSLASH" << std::endl;} return FORSLASH;}
'\%' {colNum += yyleng; if(printToken) {std::cout << "PERCENT" << std::endl;} return PERCENT;}
\! {colNum += yyleng; if(printToken) {std::cout << "BANG" << std::endl;} return BANG;}
\~ {colNum += yyleng; if(printToken) {std::cout << "TILDA" << std::endl;} return TILDA;}
TYPEDEF {colNum += yyleng; if(printToken) {std::cout << "TYPEDEF" << std::endl;} return TYPEDEF;}
extern {colNum += yyleng; if(printToken) {std::cout << "EXTERN" << std::endl;} return EXTERN;}
static {colNum += yyleng; if(printToken) {std::cout << "STATIC" << std::endl;} return STATIC;}
auto {colNum += yyleng; if(printToken) {std::cout << "AUTO" << std::endl;} return AUTO;}
register {colNum += yyleng; if(printToken) {std::cout << "REGISTER" << std::endl;} return REGISTER;}
char {colNum += yyleng; if(printToken) {std::cout << "CHAR" << std::endl;} return CHAR;}
short {colNum += yyleng; if(printToken) {std::cout << "SHORT" << std::endl;} return SHORT;}
int {colNum += yyleng; if(printToken) {std::cout << "INT" << std::endl;} return INT;}
long {colNum += yyleng; if(printToken) {std::cout << "LONG" << std::endl;} return LONG;}
signed {colNum += yyleng; if(printToken) {std::cout << "SIGNED" << std::endl;} return SIGNED;}
unsigned {colNum += yyleng; if(printToken) {std::cout << "UNSIGNED" << std::endl;} return UNSIGNED;}
float {colNum += yyleng; if(printToken) {std::cout << "FLOAT" << std::endl;} return FLOAT;}
double {colNum += yyleng; if(printToken) {std::cout << "DOUBLE" << std::endl;} return DOUBLE;}
const {colNum += yyleng; if(printToken) {std::cout << "CONST" << std::endl;} return CONST;}
volatile {colNum += yyleng; if(printToken) {std::cout << "VOLATILE" << std::endl;} return VOLATILE;}
void {colNum += yyleng; if(printToken) {std::cout << "VOID" << std::endl;} return VOID;}
struct {colNum += yyleng; if(printToken) {std::cout << "STRUCT" << std::endl;} return STRUCT;}
union {colNum += yyleng; if(printToken) {std::cout << "UNION" << std::endl;} return UNION;}
ENUM {colNum += yyleng; if(printToken) {std::cout << "ENUM" << std::endl;} return ENUM;}
ELIPSIS {colNum += yyleng; if(printToken) {std::cout << "ELIPSIS" << std::endl;} return ELIPSIS;}
CASE {colNum += yyleng; if(printToken) {std::cout << "CASE" << std::endl;} return CASE;}
DEFAULT {colNum += yyleng; if(printToken) {std::cout << "DEFAULT" << std::endl;} return DEFAULT;}
IF {colNum += yyleng; if(printToken) {std::cout << "IF" << std::endl;} return IF;}
ELSE {colNum += yyleng; if(printToken) {std::cout << "ELSE" << std::endl;} return ELSE;}
SWITCH {colNum += yyleng; if(printToken) {std::cout << "SWITCH" << std::endl;} return SWITCH;}
WHILE {colNum += yyleng; if(printToken) {std::cout << "WHILE" << std::endl;} return WHILE;}
DO {colNum += yyleng; if(printToken) {std::cout << "DO" << std::endl;} return DO;}
FOR {colNum += yyleng; if(printToken) {std::cout << "FOR" << std::endl;} return FOR;}
goto {colNum += yyleng; if(printToken) {std::cout << "GOTO" << std::endl;} return GOTO;}
continue {colNum += yyleng; if(printToken) {std::cout << "CONTINUE" << std::endl;} return CONTINUE;}
break {colNum += yyleng; if(printToken) {std::cout << "BREAK" << std::endl;} return BREAK;}
return {colNum += yyleng; if(printToken) {std::cout << "RETURN" << std::endl;} return RETURN;}
. { std::cout << "\n" << (std::string(colNum, "-")) << "^ INVALID TOKEN"; return ERROR;}
%%
