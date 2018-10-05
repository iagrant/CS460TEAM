
%{
/*
// Name: scanner.lex
// Author: Semantic Team (Franklin, Grant, Knutson)
// Purpose: This file is the scanner that performs lexical analysis on the tokens 
//			of the input stream and program.
*/
#include <stdio.h>
#include <string>
#include "C_grammar.tab.h"
int yyline = 0;
int colNum = 0;	
bool printToken = true;
%}

let [a-Z]

%%
\n {yyline++; colNum = 0;}
[ ]	{colNum += 1; /* skip white space */ }
[\t] {colNum += yylen;}
"\*"(\n|.)*"*/"	{ /* skip comment */ }
"//".* { /* skip comment */ }
\!\![A-z] {yylval.sval = yytext; if(printToken) {cout << "DEBUG" << endl;} return DEBUG;}
let[let_]*let|let {colNum += yylen; if(printToken) {cout << "IDENTIFIER" << endl;} return IDENTIFIER;}
[0-9]+ {yylval.ival = atoi(yytext); colNum += yylen; if(printToken) {cout << "INTEGER_CONSTANT" << endl;} return INTEGER_CONSTANT;}
[0-9]+\.?[0-9]* {yylval.fval = atof(yytext); colNum += yylen; if(printToken) {cout << "FLOATING_CONSTANT" << endl;} return FLOATING_CONSTANT;}
CHARACTER_CONSTANT {yylval.cval = yytext; colNum += yylen; if(printToken) {cout << "CHARACTER_CONSTANT" << endl;} return CHARACTER_CONSTANT;}
ENUMERATION_CONSTANT {colNum += yylen; if(printToken) {cout << "ENUMERATION_CONSTANT" << endl;} return ENUMERATION_CONSTANT;}
STRING_LITERAL {yylval.sval = strcat(yytext, '\0'); colNum += yylen; if(printToken) {cout << "STRING_LITERAL" << endl;} return STRING_LITERAL;}
SIZEOF {colNum += yylen; if(printToken) {cout << "SIZEOF" << endl;} return SIZEOF;}
PTR_OP {colNum += yylen; if(printToken) {cout << "PTR_OP" << endl;} return PTR_OP;}
\+\+ {colNum += yylen; if(printToken) {cout << "INC_OP" << endl;} return INC_OP;}
-- {colNum += yylen; if(printToken) {cout << "DEC_OP" << endl;} return DEC_OP;}
\<\< {colNum += yylen; if(printToken) {cout << "LEFT_OP" << endl;} return LEFT_OP;}
>> {colNum += yylen; if(printToken) {cout << "RIGHT_OP" << endl;} return RIGHT_OP;}
\<= {colNum += yylen; if(printToken) {cout << "LE_OP" << endl;} return LE_OP;}
>= {colNum += yylen; if(printToken) {cout << "GE_OP" << endl;} return GE_OP;}
== {colNum += yylen; if(printToken) {cout << "EQ_OP" << endl;} return EQ_OP;}
!= {colNum += yylen; if(printToken) {cout << "NE_OP" << endl;} return NE_OP;}
&& {colNum += yylen; if(printToken) {cout << "AND_OP" << endl;} return AND_OP;}
\|\| {colNum += yylen; if(printToken) {cout << "OR_OP" << endl;} return OR_OP;}
\* {colNum += yylen; if(printToken) {cout << "MUL_ASSIGN" << endl;} return MUL_ASSIGN;}
\/ {colNum += yylen; if(printToken) {cout << "DIV_ASSIGN" << endl;} return DIV_ASSIGN;}
% {colNum += yylen; if(printToken) {cout << "MOD_ASSIGN" << endl;} return MOD_ASSIGN;}
\+ {colNum += yylen; if(printToken) {cout << "ADD_ASSIGN" << endl;} return ADD_ASSIGN;}
- {colNum += yylen; if(printToken) {cout << "SUB_ASSIGN" << endl;} return SUB_ASSIGN;}
'<<' {colNum += yylen; if(printToken) {cout << "LEFT_ASSIGN" << endl;} return LEFT_ASSIGN;}
'>>' {colNum += yylen; if(printToken) {cout << "RIGHT_ASSIGN" << endl;} return RIGHT_ASSIGN;}
& {colNum += yylen; if(printToken) {cout << "AND_ASSIGN" << endl;} return AND_ASSIGN;}
\| {colNum += yylen; if(printToken) {cout << "OR_ASSIGN" << endl;} return OR_ASSIGN;}
TYPEDEF_NAME {colNum += yylen; if(printToken) {cout << "TYPEDEF_NAME" << endl;} return TYPEDEF_NAME;}
\; {colNum += yylen; if(printToken) {cout << "SEMI" << endl;} return SEMI;}
\: {colNum += yylen; if(printToken) {cout << "COLON" << endl;} return COLON;}
\{ {colNum += yylen; if(printToken) {cout << "CURLYOPEN" << endl;} return CURLYOPEN;}
\} {colNum += yylen; if(printToken) {cout << "CURLYCLOSE" << endl;} return CURLYCLOSE;}
\[ {colNum += yylen; if(printToken) {cout << "BRACKETOPEN" << endl;} return BRACKETOPEN;}
\] {colNum += yylen; if(printToken) {cout << "BRACKETCLOSE" << endl;} return BRACKETCLOSE;}
\, {colNum += yylen; if(printToken) {cout << "COMMA" << endl;} return COMMA;}
\. {colNum += yylen; if(printToken) {cout << "PERIOD" << endl;} return PERIOD;}
\= {colNum += yylen; if(printToken) {cout << "EQUALS" << endl;} return EQUALS;}
\( {colNum += yylen; if(printToken) {cout << "OPEN" << endl;} return OPEN;}
\) {colNum += yylen; if(printToken) {cout << "CLOSE" << endl;} return CLOSE;}
'*' {colNum += yylen; if(printToken) {cout << "STAR" << endl;} return STAR;}
\? {colNum += yylen; if(printToken) {cout << "QUESTION" << endl;} return QUESTION;}
'\|' {colNum += yylen; if(printToken) {cout << "BAR" << endl;} return BAR;}
\^ {colNum += yylen; if(printToken) {cout << "CARROT" << endl;} return CARROT;}
'&' {colNum += yylen; if(printToken) {cout << "AMP" << endl;} return AMP;}
\< {colNum += yylen; if(printToken) {cout << "LESS_OP" << endl;} return LESS_OP;}
\> {colNum += yylen; if(printToken) {cout << "GREAT_OP" << endl;} return GREAT_OP;}
'\+' {colNum += yylen; if(printToken) {cout << "PLUS" << endl;} return PLUS;}
'-' {colNum += yylen; if(printToken) {cout << "MINUS" << endl;} return MINUS;}
\\ {colNum += yylen; if(printToken) {cout << "FORSLASH" << endl;} return FORSLASH;}
'\%' {colNum += yylen; if(printToken) {cout << "PERCENT" << endl;} return PERCENT;}
\! {colNum += yylen; if(printToken) {cout << "BANG" << endl;} return BANG;}
\~ {colNum += yylen; if(printToken) {cout << "TILDA" << endl;} return TILDA;}
TYPEDEF {colNum += yylen; if(printToken) {cout << "TYPEDEF" << endl;} return TYPEDEF;}
extern {colNum += yylen; if(printToken) {cout << "EXTERN" << endl;} return EXTERN;}
static {colNum += yylen; if(printToken) {cout << "STATIC" << endl;} return STATIC;}
auto {colNum += yylen; if(printToken) {cout << "AUTO" << endl;} return AUTO;}
register {colNum += yylen; if(printToken) {cout << "REGISTER" << endl;} return REGISTER;}
char {colNum += yylen; if(printToken) {cout << "CHAR" << endl;} return CHAR;}
short {colNum += yylen; if(printToken) {cout << "SHORT" << endl;} return SHORT;}
int {colNum += yylen; if(printToken) {cout << "INT" << endl;} return INT;}
long {colNum += yylen; if(printToken) {cout << "LONG" << endl;} return LONG;}
signed {colNum += yylen; if(printToken) {cout << "SIGNED" << endl;} return SIGNED;}
unsigned {colNum += yylen; if(printToken) {cout << "UNSIGNED" << endl;} return UNSIGNED;}
float {colNum += yylen; if(printToken) {cout << "FLOAT" << endl;} return FLOAT;}
double {colNum += yylen; if(printToken) {cout << "DOUBLE" << endl;} return DOUBLE;}
const {colNum += yylen; if(printToken) {cout << "CONST" << endl;} return CONST;}
volatile {colNum += yylen; if(printToken) {cout << "VOLATILE" << endl;} return VOLATILE;}
void {colNum += yylen; if(printToken) {cout << "VOID" << endl;} return VOID;}
struct {colNum += yylen; if(printToken) {cout << "STRUCT" << endl;} return STRUCT;}
union {colNum += yylen; if(printToken) {cout << "UNION" << endl;} return UNION;}
ENUM {colNum += yylen; if(printToken) {cout << "ENUM" << endl;} return ENUM;}
ELIPSIS {colNum += yylen; if(printToken) {cout << "ELIPSIS" << endl;} return ELIPSIS;}
CASE {colNum += yylen; if(printToken) {cout << "CASE" << endl;} return CASE;}
DEFAULT {colNum += yylen; if(printToken) {cout << "DEFAULT" << endl;} return DEFAULT;}
IF {colNum += yylen; if(printToken) {cout << "IF" << endl;} return IF;}
ELSE {colNum += yylen; if(printToken) {cout << "ELSE" << endl;} return ELSE;}
SWITCH {colNum += yylen; if(printToken) {cout << "SWITCH" << endl;} return SWITCH;}
WHILE {colNum += yylen; if(printToken) {cout << "WHILE" << endl;} return WHILE;}
DO {colNum += yylen; if(printToken) {cout << "DO" << endl;} return DO;}
FOR {colNum += yylen; if(printToken) {cout << "FOR" << endl;} return FOR;}
goto {colNum += yylen; if(printToken) {cout << "GOTO" << endl;} return GOTO;}
continue {colNum += yylen; if(printToken) {cout << "CONTINUE" << endl;} return CONTINUE;}
break {colNum += yylen; if(printToken) {cout << "BREAK" << endl;} return BREAK;}
return {colNum += yylen; if(printToken) {cout << "RETURN" << endl;} return RETURN;}
%%
