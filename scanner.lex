// Name: scanner.lex
// Author: Semantic Team (Franklin, Grant, Knutson)
// Purpose: This file is the scanner that performs lexical analysis on the tokens 
//			of the input stream and program.

%{
	#include <stdio.h>
	
%}

// Reserved Words
#define  
#define
#define

let [a-Z]

%%
\!\![a-Z] return DEBUG;
let[let_]*let|let return IDENTIFIER;
INTEGER_CONSTANT
FLOATING_CONSTANT
CHARACTER_CONSTANT
ENUMERATION_CONSTANT
STRING_LITERAL
SIZEOF
PTR_OP
++ return INC_OP
-- return DEC_OP
<< return LEFT_OP
>> return RIGHT_OP
<= return LE_OP
>= return GE_OP
== return EQ_OP
!= return NE_OP
&& return AND_OP
|| return OR_OP
\*= return MUL_ASSIGN
/= return DIV_ASSIGN
\%= return MOD_ASSIGN
\+= return ADD_ASSIGN
-= return SUB_ASSIGN
<<= return LEFT_ASSIGN
>>= return RIGHT_ASSIGN
&= return AND_ASSIGN
|= return OR_ASSIGN
TYPEDEF_NAME
\; return SEMI
\: return COLON
\{ return CURLYOPEN
\} return CURLYCLOSE
\[ return BRACKETOPEN
\] return BRACKETCLOSE
\, return COMMA
\. return PERIOD
\= return EQUALS
\( return OPEN
\) return CLOSE
\* return STAR
\? return QUESTION
\| return BAR
\^ return CARROT
\& return AMP
\< return LESS_OP
\> return GREAT_OP
\+ return PLUS
\- return MINUS
\/ return FORSLASH
\% return PERCENT
\! return BANG
\~ return TILDA
TYPEDEF
extern return EXTERN
static return STATIC
auto return AUTO
register return REGISTER
char return CHAR
short return SHORT
int return INT
long return LONG
signed return SIGNED
unsigned return UNSIGNED
float return FLOAT
double return DOUBLE
const return CONST
volatile return VOLATILE
void return VOID
struct return STRUCT
union return UNION
ENUM
ELIPSIS
CASE
DEFAULT
IF
ELSE
SWITCH
WHILE
DO
FOR
goto return GOTO
continue return CONTINUE
break return BREAK
return return RETURN
%%
