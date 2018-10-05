
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
%}

let [a-Z]

%%
\n {yyline++; colNum = 0;}
[ ]	{colNum += 1; /* skip white space */ }
[\t] {colNum += yylen;}
"\*"(\n|.)*"*/"	{ /* skip comment */ }
"//".* { /* skip comment */ }
\!\![A-z] {yylval.sval = yytext; return DEBUG;}
let[let_]*let|let {colNum += yylen; return IDENTIFIER;}
[0-9]+ {yylval.ival = atoi(yytext); colNum += yylen; return INTEGER_CONSTANT;}
[0-9]+\.?[0-9]* {yylval.fval = atof(yytext); colNum += yylen; return FLOATING_CONSTANT;}
CHARACTER_CONSTANT {yylval.cval = yytext; colNum += yylen; return CHARACTER_CONSTANT;}
ENUMERATION_CONSTANT {colNum += yylen; return ENUMERATION_CONSTANT;}
STRING_LITERAL {yylval.sval = strcat(yytext, '\0'); colNum += yylen; return STRING_LITERAL;}
SIZEOF {colNum += yylen; return SIZEOF;}
PTR_OP {colNum += yylen; return PTR_OP;}
\+\+ {colNum += yylen; return INC_OP;}
-- {colNum += yylen; return DEC_OP;}
\<\< {colNum += yylen; return LEFT_OP;}
>> {colNum += yylen; return RIGHT_OP;}
\<= {colNum += yylen; return LE_OP;}
>= {colNum += yylen; return GE_OP;}
== {colNum += yylen; return EQ_OP;}
!= {colNum += yylen; return NE_OP;}
&& {colNum += yylen; return AND_OP;}
\|\| {colNum += yylen; return OR_OP;}
\* {colNum += yylen; return MUL_ASSIGN;}
\/ {colNum += yylen; return DIV_ASSIGN;}
% {colNum += yylen; return MOD_ASSIGN;}
\+ {colNum += yylen; return ADD_ASSIGN;}
- {colNum += yylen; return SUB_ASSIGN;}
'<<' {colNum += yylen; return LEFT_ASSIGN;}
'>>' {colNum += yylen; return RIGHT_ASSIGN;}
& {colNum += yylen; return AND_ASSIGN;}
\| {colNum += yylen; return OR_ASSIGN;}
TYPEDEF_NAME {colNum += yylen; return TYPEDEF_NAME;}
\; {colNum += yylen; return SEMI;}
\: {colNum += yylen; return COLON;}
\{ {colNum += yylen; return CURLYOPEN;}
\} {colNum += yylen; return CURLYCLOSE;}
\[ {colNum += yylen; return BRACKETOPEN;}
\] {colNum += yylen; return BRACKETCLOSE;}
\, {colNum += yylen; return COMMA;}
\. {colNum += yylen; return PERIOD;}
\= {colNum += yylen; return EQUALS;}
\( {colNum += yylen; return OPEN;}
\) {colNum += yylen; return CLOSE;}
'*' {colNum += yylen; return STAR;}
\? {colNum += yylen; return QUESTION;}
'\|' {colNum += yylen; return BAR;}
\^ {colNum += yylen; return CARROT;}
'&' {colNum += yylen; return AMP;}
\< {colNum += yylen; return LESS_OP;}
\> {colNum += yylen; return GREAT_OP;}
'\+' {colNum += yylen; return PLUS;}
'-' {colNum += yylen; return MINUS;}
\\ {colNum += yylen; return FORSLASH;}
'\%' {colNum += yylen; return PERCENT;}
\! {colNum += yylen; return BANG;}
\~ {colNum += yylen; return TILDA;}
TYPEDEF {colNum += yylen; return TYPEDEF;}
extern {colNum += yylen; return EXTERN;}
static {colNum += yylen; return STATIC;}
auto {colNum += yylen; return AUTO;}
register {colNum += yylen; return REGISTER;}
char {colNum += yylen; return CHAR;}
short {colNum += yylen; return SHORT;}
int {colNum += yylen; return INT;}
long {colNum += yylen; return LONG;}
signed {colNum += yylen; return SIGNED;}
unsigned {colNum += yylen; return UNSIGNED;}
float {colNum += yylen; return FLOAT;}
double {colNum += yylen; return DOUBLE;}
const {colNum += yylen; return CONST;}
volatile {colNum += yylen; return VOLATILE;}
void {colNum += yylen; return VOID;}
struct {colNum += yylen; return STRUCT;}
union {colNum += yylen; return UNION;}
ENUM {colNum += yylen; return ENUM;}
ELIPSIS {colNum += yylen; return ELIPSIS;}
CASE {colNum += yylen; return CASE;}
DEFAULT {colNum += yylen; return DEFAULT;}
IF {colNum += yylen; return IF;}
ELSE {colNum += yylen; return ELSE;}
SWITCH {colNum += yylen; return SWITCH;}
WHILE {colNum += yylen; return WHILE;}
DO {colNum += yylen; return DO;}
FOR {colNum += yylen; return FOR;}
goto {colNum += yylen; return GOTO;}
continue {colNum += yylen; return CONTINUE;}
break {colNum += yylen; return BREAK;}
return {colNum += yylen; return RETURN;}
%%
