
%{
/*
// Name: scanner.lex
// Author: Semantic Team (Franklin, Grant, Knutson)
// Purpose: This file is the scanner that performs lexical analysis on the tokens 
//			of the input stream and program.
*/
	#include <stdio.h>
  #include <string.h>
	
%}

let [a-Z]

%%
\!\![A-z] {yylval.sval = yytext; return DEBUG;}
let[let_]*let|let return IDENTIFIER;
[0-9]+ {yylval.int = atoi(yytext); return INTEGER_CONSTANT;}
[0-9]+\.?[0-9]* {yylval.fval = stof(yytext); return FLOATING_CONSTANT;}
CHARACTER_CONSTANT {yylval.cval = yytext; return CHARACTER_CONSTANT;}
ENUMERATION_CONSTANT return ENUMERATION_CONSTANT;
STRING_LITERAL {yylval.sval = strcat(yytext,"\0"); return STRING_LITERAL;}
SIZEOF return SIZEOF;
PTR_OP return PTR_OP;
\+\+ return INC_OP;
-- return DEC_OP;
\<\< return LEFT_OP;
>> return RIGHT_OP;
\<= return LE_OP;
>= return GE_OP;
== return EQ_OP;
!= return NE_OP;
&& return AND_OP;
\|\| return OR_OP;
\* return MUL_ASSIGN;
\/ return DIV_ASSIGN;
% return MOD_ASSIGN;
\+ return ADD_ASSIGN;
- return SUB_ASSIGN;
'<<' return LEFT_ASSIGN;
'>>' return RIGHT_ASSIGN;
& return AND_ASSIGN;
\| return OR_ASSIGN;
TYPEDEF_NAME return TYPEDEF_NAME;
\; return SEMI;
\: return COLON;
\{ return CURLYOPEN;
\} return CURLYCLOSE;
\[ return BRACKETOPEN;
\] return BRACKETCLOSE;
\, return COMMA;
\. return PERIOD;
\= return EQUALS;
\( return OPEN;
\) return CLOSE;
'*' return STAR;
\? return QUESTION;
'\|' return BAR;
\^ return CARROT;
'&' return AMP;
\< return LESS_OP;
\> return GREAT_OP;
'\+' return PLUS;
'-' return MINUS;
\\ return FORSLASH;
'\%' return PERCENT;
\! return BANG;
\~ return TILDA;
TYPEDEF return TYPEDEF;
extern return EXTERN;
static return STATIC;
auto return AUTO;
register return REGISTER;
char return CHAR;
short return SHORT;
int return INT;
long return LONG;
signed return SIGNED;
unsigned return UNSIGNED;
float return FLOAT;
double return DOUBLE;
const return CONST;
volatile return VOLATILE;
void return VOID;
struct return STRUCT;
union return UNION;
ENUM return ENUM;
ELIPSIS return ELIPSIS;
CASE return CASe;
DEFAULT return DEFAULT;
IF return IF;
ELSE return ELSE;
SWITCH return SWITCH;
WHILE return WHILE;
DO return DO;
FOR return FOR;
goto return GOTO;
continue return CONTINUE;
break return BREAK;
return return RETURN;
%%
