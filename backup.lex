
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
#include <fstream>
#include <string>
//#include "C_grammar.tab.h"

int lineNum = 1;
int colNum = 1;
bool printToken = false;
bool printSymbol = false;
bool printProductions = false;
std::string buffer = "";
std::string srcFile = "";
void printError (int colNum,std::string errorTok);

%}

%option noyywrap
alpha   [A-Za-z]
dig     [0-9]
name    ({alpha}|{dig}|\$)({alpha}|{dig}|[_.\-/$])*
num1    [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2    [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
number  {num1}|{num2}

%%
\n              {/*std::cout << "Line: " << lineNum << "   Col: " << colNum << std::endl;*/ lineNum++; colNum = 1;}
[ ]	            {colNum++; /* skip white space */ }
"/*"   			{
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

\/\/.* 			/*skipping single line comments */
\!\![A-z]       {
                    if(printToken) {std::cout << "DEBUG" << std::endl;}
                    if (yytext == "!!dl")
                    {
                        if(printToken)
                            printToken = false;
                        else
                            printToken = true;
                    }
                    if (yytext == "!!dp")
                    {
                        if(printProductions)
                            printProductions = false;
                        else
                            printProductions = true;
                    }
                    if (yytext == "!!ds")
                    {
                        if(printSymbol)
                            printSymbol = false;
                        else
                            printSymbol = true;
                    }
                    ////return DEBUG;
                }
[-]?[0-9]+      {
                    if(printToken) {std::cout << "INTEGER_CONSTANT" << std::endl;}
                    colNum += yyleng;
                    ////return INTEGER_CONSTANT;
                }
[0-9]+\.?[0-9]* {
                    if(printToken) {std::cout << "FLOATING_CONSTANT" << std::endl;}
                    colNum += yyleng;
                    ////return FLOATING_CONSTANT;
                }
\'(\\.|.)\'     {
                    if(printToken) {std::cout << "CHARACTER_CONSTANT" << std::endl;}
                    colNum += yyleng;
                    ////return CHARACTER_CONSTANT;
                }
"ENUM"          {
                    if(printToken) {std::cout << "ENUMERATION_CONSTANT" << std::endl;}
                    colNum += yyleng;
                    ////return ENUMERATION_CONSTANT;
                }
\"[A-z]+\"      {
                    if(printToken) {std::cout << "STRING_LITERAL" << std::endl;}
                    colNum += yyleng;
                    ////return STRING_LITERAL;
                }
sizeof          {
                    if(printToken) {std::cout << "SIZEOF" << std::endl;}
                    colNum += yyleng;
                    ////return SIZEOF;
                }
\+\+            {
                    if(printToken) {std::cout << "INC_OP" << std::endl;}
                    colNum += yyleng;
                    ////return INC_OP;
                }
--              {
                    if(printToken) {std::cout << "DEC_OP" << std::endl;}
                    colNum += yyleng;
                    ////return DEC_OP;
                }
\<\<            {
                    if(printToken) {std::cout << "LEFT_OP" << std::endl;}
                    colNum += yyleng;
                    ////return LEFT_OP;
                }
>>              {
                    if(printToken) {std::cout << "RIGHT_OP" << std::endl;}
                    colNum += yyleng;
                    ////return RIGHT_OP;
                }
\<=             {
                    if(printToken) {std::cout << "LE_OP" << std::endl;}
                    colNum += yyleng;
                    ////return LE_OP;
                }
>=              {
                    if(printToken) {std::cout << "GE_OP" << std::endl;}
                    colNum += yyleng;
                    ////return GE_OP;
                }
==              {
                    if(printToken) {std::cout << "EQ_OP" << std::endl;}
                    colNum += yyleng;
                    ////return EQ_OP;
                }
!=              {
                    if(printToken) {std::cout << "NE_OP" << std::endl;}
                    colNum += yyleng;
                    //return NE_OP;
                }
&&              {
                    if(printToken) {std::cout << "AND_OP" << std::endl;}
                    colNum += yyleng;
                    //return AND_OP;
                }
\|\|            {
                    if(printToken) {std::cout << "OR_OP" << std::endl;}
                    colNum += yyleng;
                    //return OR_OP;
                }
\*=             {
                    if(printToken) {std::cout << "MUL_ASSIGN" << std::endl;}
                    colNum += yyleng;
                    //return MUL_ASSIGN;
                }
\/=             {
                    if(printToken) {std::cout << "DIV_ASSIGN" << std::endl;}
                    colNum += yyleng;
                    //return DIV_ASSIGN;
                }
%=              {
                    if(printToken) {std::cout << "MOD_ASSIGN" << std::endl;}
                    colNum += yyleng;
                    //return MOD_ASSIGN;
                }
\+=             {
                    if(printToken) {std::cout << "ADD_ASSIGN" << std::endl;}
                    colNum += yyleng;
                    //return ADD_ASSIGN;
                }
-=              {
                    if(printToken) {std::cout << "SUB_ASSIGN" << std::endl;}
                    colNum += yyleng;
                    //return SUB_ASSIGN;
                }
'<<='           {
                    if(printToken) {std::cout << "LEFT_ASSIGN" << std::endl;}
                    colNum += yyleng;
                    //return LEFT_ASSIGN;
                }
'>>='           {
                    if(printToken) {std::cout << "RIGHT_ASSIGN" << std::endl;}
                    colNum += yyleng;
                    //return RIGHT_ASSIGN;
                }
&=              {
                    if(printToken) {std::cout << "AND_ASSIGN" << std::endl;}
                    colNum += yyleng;
                    //return AND_ASSIGN;
                }
\|=             {
                    if(printToken) {std::cout << "OR_ASSIGN" << std::endl;}
                    colNum += yyleng;
                    //return OR_ASSIGN;
                }
\;              {
                    if(printToken) {std::cout << "SEMI" << std::endl;}
                    colNum += yyleng;
                    //return SEMI;
                }
\:              {
                    if(printToken) {std::cout << "COLON" << std::endl;}
                    colNum += yyleng;
                    //return COLON;
                }
\{              {
                    if(printToken) {std::cout << "CURLYOPEN" << std::endl;}
                    colNum += yyleng;
                    //return CURLYOPEN;
                }
\}              {
                    if(printToken) {std::cout << "CURLYCLOSE" << std::endl;}
                    colNum += yyleng;
                    //return CURLYCLOSE;
                }
\[              {
                    if(printToken) {std::cout << "BRACKETOPEN" << std::endl;}
                    colNum += yyleng;
                    //return BRACKETOPEN;
                }
\]              {
                    if(printToken) {std::cout << "BRACKETCLOSE" << std::endl;}
                    colNum += yyleng;
                    //return BRACKETCLOSE;
                }
\,              {
                    if(printToken) {std::cout << "COMMA" << std::endl;}
                    colNum += yyleng;
                    //return COMMA;
                }
\.              {
                    if(printToken) {std::cout << "PERIOD" << std::endl;}
                    colNum += yyleng;
                    //return PERIOD;
                }
\=              {
                    if(printToken) {std::cout << "EQUALS" << std::endl;}
                    colNum += yyleng;
                    //return EQUALS;
                }
\(              {
                    if(printToken) {std::cout << "OPEN" << std::endl;}
                    colNum += yyleng;
                    //return OPEN;
                }
\)              {
                    if(printToken) {std::cout << "CLOSE" << std::endl;}
                    colNum += yyleng;
                    //return CLOSE;
                }
\*              {
                    if(printToken) {std::cout << "STAR" << std::endl;}
                    colNum += yyleng;
                    //return STAR;
                }
\?              {
                    if(printToken) {std::cout << "QUESTION" << std::endl;}
                    colNum += yyleng;
                    //return QUESTION;
                }
\|              {
                    if(printToken) {std::cout << "BAR" << std::endl;}
                    colNum += yyleng;
                    //return BAR;
                }
\^              {
                    if(printToken) {std::cout << "CARROT" << std::endl;}
                    colNum += yyleng;
                    //return CARROT;
                }
\&              {
                    if(printToken) {std::cout << "AMP" << std::endl;}
                    colNum += yyleng;
                    //return AMP;
                }
\<              {
                    if(printToken) {std::cout << "LESS_OP" << std::endl;}
                    colNum += yyleng;
                    //return LESS_OP;
                }
\>              {
                    if(printToken) {std::cout << "GREAT_OP" << std::endl;}
                    colNum += yyleng;
                    //return GREAT_OP;
                }
\+              {
                    if(printToken) {std::cout << "PLUS" << std::endl;}
                    colNum += yyleng;
                    //return PLUS;
                }
\-              {
                    if(printToken) {std::cout << "MINUS" << std::endl;}
                    colNum += yyleng;
                    //return MINUS;
                }
\/              {
                    if(printToken) {std::cout << "FORSLASH" << std::endl;}
                    colNum += yyleng;
                    //return FORSLASH;
                }
\%              {
                    if(printToken) {std::cout << "PERCENT" << std::endl;}
                    colNum += yyleng;
                    //return PERCENT;
                }
\!              {
                    if(printToken) {std::cout << "BANG" << std::endl;}
                    colNum += yyleng;
                    //return BANG;
                }
\~              {
                    if(printToken) {std::cout << "TILDA" << std::endl;}
                    colNum += yyleng;
                    //return TILDA;
                }
typedef         {
                    if(printToken) {std::cout << "TYPEDEF" << std::endl;}
                    colNum += yyleng;
                    //return TYPEDEF;
                }
extern          {
                    if(printToken) {std::cout << "EXTERN" << std::endl;}
                    colNum += yyleng;
                    //return EXTERN;
                }
static          {
                    if(printToken) {std::cout << "STATIC" << std::endl;}
                    colNum += yyleng;
                    //return STATIC;
                }
auto            {
                    if(printToken) {std::cout << "AUTO" << std::endl;}
                    colNum += yyleng;
                    //return AUTO;
                }
register        {
                    if(printToken) {std::cout << "REGISTER" << std::endl;}
                    colNum += yyleng;
                    //return REGISTER;
                }
char            {
                    if(printToken) {std::cout << "CHAR" << std::endl;}
                    colNum += yyleng;
                    //return CHAR;
                }
short           {
                    if(printToken) {std::cout << "SHORT" << std::endl;}
                    colNum += yyleng;
                    //return SHORT;
                }
int             {
                    if(printToken) {std::cout << "INT" << std::endl;}
                    colNum += yyleng;
                    //return INT;
                }
main            {
                    if(printToken) {std::cout << "MAIN" << std::endl;}
                    colNum += yyleng;
                    //return MAIN;
                }
long            {
                    if(printToken) {std::cout << "LONG" << std::endl;}
                    colNum += yyleng;
                    //return LONG;
                }
signed          {
                    if(printToken) {std::cout << "SIGNED" << std::endl;}
                    colNum += yyleng;
                    //return SIGNED;
                }
unsigned        {
                    if(printToken) {std::cout << "UNSIGNED" << std::endl;}
                    colNum += yyleng;
                    //return UNSIGNED;
                }
float           {
                    if(printToken) {std::cout << "FLOAT" << std::endl;}
                    colNum += yyleng;
                    //return FLOAT;
                }
double          {
                    if(printToken) {std::cout << "DOUBLE" << std::endl;}
                    colNum += yyleng;
                    //return DOUBLE;
                }
const           {
                    if(printToken) {std::cout << "CONST" << std::endl;}
                    colNum += yyleng;
                    //return CONST;
                }
volatile        {
                    if(printToken) {std::cout << "VOLATILE" << std::endl;}
                    colNum += yyleng;
                    //return VOLATILE;
                }
void            {
                    if(printToken) {std::cout << "VOID" << std::endl;}
                    colNum += yyleng;
                    //return VOID;
                }
struct          {
                    if(printToken) {std::cout << "STRUCT" << std::endl;}
                    colNum += yyleng;
                    //return STRUCT;
                }
union           {
                    if(printToken) {std::cout << "UNION" << std::endl;}
                    colNum += yyleng;
                    //return UNION;
                }
enum            {
                    if(printToken) {std::cout << "ENUM" << std::endl;}
                    colNum += yyleng;
                    //return ENUM;
                }
elipsis         {
                    if(printToken) {std::cout << "ELIPSIS" << std::endl;}
                    colNum += yyleng;
                    //return ELIPSIS;
                }
case            {
                    if(printToken) {std::cout << "CASE" << std::endl;}
                    colNum += yyleng;
                    //return CASE;
                }
default         {
                    if(printToken) {std::cout << "DEFAULT" << std::endl;}
                    colNum += yyleng;
                    //return DEFAULT;
                }
if              {
                    if(printToken) {std::cout << "IF" << std::endl;}
                    colNum += yyleng;
                    //return IF;
                }
else            {
                    if(printToken) {std::cout << "ELSE" << std::endl;}
                    colNum += yyleng;
                    //return ELSE;
                }
switch          {
                    if(printToken) {std::cout << "SWITCH" << std::endl;}
                    colNum += yyleng;
                    //return SWITCH;
                }
while           {
                    if(printToken) {std::cout << "WHILE" << std::endl;}
                    colNum += yyleng;
                    //return WHILE;
                }
do              {
                    if(printToken) {std::cout << "DO" << std::endl;}
                    colNum += yyleng;
                    //return DO;
                }
for             {
                    if(printToken) {std::cout << "FOR" << std::endl;}
                    colNum += yyleng;
                    //return FOR;
                }
goto            {
                    if(printToken) {std::cout << "GOTO" << std::endl;}
                    colNum += yyleng;
                    //return GOTO;
                }
continue        {
                    if(printToken) {std::cout << "CONTINUE" << std::endl;}
                    colNum += yyleng;
                    //return CONTINUE;
                }
break           {
                    if(printToken) {std::cout << "BREAK" << std::endl;}
                    colNum += yyleng;
                    //return BREAK;
                }
return          {
                    if(printToken) {std::cout << "RETURN" << std::endl;}
                    colNum += yyleng;
                    //return RETURN;
                }
{name}          {
                    if(printToken) {std::cout << "IDENTIFIER" << std::endl;}
                    colNum +=yyleng;
                    if (yyleng > 31)
                    {
                        std::cout << std::string(colNum,'-') << " ^ "<< "ID LENGTH LONGER THAN 31" << std::endl;
                        //return ERROR;
                    }
                    //return IDENTIFIER;
                }
.               {
                    if(printToken) {std::cout << "ERROR" << std::endl;}
                    printError(colNum,yytext);
                    //return ERROR;
                }
%%
void printError (int colNum, std::string errorTok) {
    std::ifstream srcFileP(srcFile);
    for (int i = 0; i < lineNum; i++)
    {
        std::getline(srcFileP,buffer);
    }
    std::cout << buffer << std::endl;
    std::cout << std::string(colNum - 1,'-') << "\033[1;91m^ Unidentifed Token: \033[0m\033[4;33m"
    		  << errorTok << "\033[0m on Line: " << lineNum
    		  << " and Column: " << colNum <<std::endl;
    //remeber to close file pointer lmao
}

int main (int argc, char** argv)
{
    std::string tokenFlag = "-dl";
	std::string symbolFlag = "-ds";
	std::string fhFlag = "-fh";
	std::string productionFlag = "-p";
    std::string inputFlag = "-i";
    extern std::string srcFile;
    extern std::string buffer;

    // Check command line args for debug symbols
    for (int i = 0; i < argc; i++) {
        if((tokenFlag.compare(argv[i])) == 0)
        {
            printToken = true;
        }
        if((symbolFlag.compare(argv[i])) == 0)
        {
            // Dump the symbol table
        }
        if((fhFlag.compare(argv[i])) == 0)
        {
            // RELEASE THE FH
        }
		if ((productionFlag.compare(argv[i])) == 0)
		{
			printProductions = true;
		}
        if ((inputFlag.compare(argv[i]))==0)
        {
            if (i++ < argc)
                srcFile = argv[i++];
            else
            {
                std::cout << "ERROR: PLEASE SPECIFIY A SRC CODE FILE AFTER -i" << std::endl;
                return 0;
            }
        }
    }

    FlexLexer* lexer = new yyFlexLexer;
    while(lexer->yylex() != 0)
    ;
    return 0;
}
