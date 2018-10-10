
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
#include "C_grammar.tab.hpp"

#define POS_INT_MAX 2147483646
#define NEG_INT_MAX -2147483647
/*
#define POS_DOUBLE_MAX 1.7E+308
#define NEG_DOUBLE_MAX 2.3E-308
*/
extern int yylex();
extern int yyparse();

int lineNum = 1;
int colNum = 1;
bool printToken = false;
bool printSymbol = false;
bool printProductions = false;
bool printFile = true;
std::string buffer = "";
std::string srcFile = "";
std::string outSrcFile = "a.out";

void printError (int colNum,std::string errorTok);
void printConsole (std::string token);
void printToFile (std::string token);

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
\!\![A-z]+      {
                    if(printToken) {printConsole("DEBUG");}
                    if(printFile) {printToFile("DEBUG");}
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
                    return yy::parser::token::DEBUG;
                }
[-]?[0-9]+      {
                    if(printToken) {printConsole("INTEGER_CONSTANT");}
                    if(printFile) {printToFile("INTEGER_CONSTANT");}
                    colNum += yyleng;
                    std::cout << yytext << std::endl;
                    if (yyleng > 9)
                        std::cout << "\033[4;93mWARNING: POSSIBLE INT OVERFLOW\033[0m"<< std::endl;
                    return yy::parser::token::INTEGER_CONSTANT;
                }
[0-9]+\.?[0-9]* {
                    if(printToken) {printConsole("FLOATING_CONSTANT");}
                    if(printFile) {printToFile("FLOATING_CONSTANT");}
                    colNum += yyleng;
                    return yy::parser::token::FLOATING_CONSTANT;
                }
\'(\\[nrtbfv0]|.)\'     {
                    if(printToken) {printConsole("CHARACTER_CONSTANT");}
                    if(printFile) {printToFile("CHARACTER_CONSTANT");}
                    colNum += yyleng;
                    return yy::parser::token::CHARACTER_CONSTANT;
                }
"ENUM"          {
                    if(printToken) {printConsole("ENUMERATION_CONSTANT");}
                    if(printFile) {printToFile("ENUMERATION_CONSTANT");}
                    colNum += yyleng;
                    return yy::parser::token::ENUMERATION_CONSTANT;
                }
\"[A-z]+\"      {
                    if(printToken) {printConsole("STRING_LITERAL");}
                    if(printFile) {printToFile("STRING_LITERAL");}
                    colNum += yyleng;
                    return yy::parser::token::STRING_LITERAL;
                }
sizeof          {
                    if(printToken) {printConsole("SIZEOF");}
                    if(printFile) {printToFile("SIZEOF");}
                    colNum += yyleng;
                    return yy::parser::token::SIZEOF;
                }
\+\+            {
                    if(printToken) {printConsole("INC_OP");}
                    if(printFile) {printToFile("INC_OP");}
                    colNum += yyleng;
                    return yy::parser::token::INC_OP;
                }
--              {
                    if(printToken) {printConsole("DEC_OP");}
                    if(printFile) {printToFile("DEC_OP");}
                    colNum += yyleng;
                    return yy::parser::token::DEC_OP;
                }
\<\<            {
                    if(printToken) {printConsole("LEFT_OP");}
                    if(printFile) {printToFile("LEFT_OP");}
                    colNum += yyleng;
                    return yy::parser::token::LEFT_OP;
                }
>>              {
                    if(printToken) {printConsole("RIGHT_OP");}
                    if(printFile) {printToFile("RIGHT_OP");}
                    colNum += yyleng;
                    return yy::parser::token::RIGHT_OP;
                }
\<=             {
                    if(printToken) {printConsole("LE_OP");}
                    if(printFile) {printToFile("LE_OP");}
                    colNum += yyleng;
                    return yy::parser::token::LE_OP;
                }
>=              {
                    if(printToken) {printConsole("GE_OP");}
                    if(printFile) {printToFile("GE_OP");}
                    colNum += yyleng;
                    return yy::parser::token::GE_OP;
                }
==              {
                    if(printToken) {printConsole("EQ_OP");}
                    if(printFile) {printToFile("EQ_OP");}
                    colNum += yyleng;
                    return yy::parser::token::EQ_OP;
                }
!=              {
                    if(printToken) {printConsole("NE_OP");}
                    if(printFile) {printToFile("NE_OP");}
                    colNum += yyleng;
                    return yy::parser::token::NE_OP;
                }
&&              {
                    if(printToken) {printConsole("AND_OP");}
                    if(printFile) {printToFile("AND_OP");}
                    colNum += yyleng;
                    return yy::parser::token::AND_OP;
                }
\|\|            {
                    if(printToken) {printConsole("OR_OP");}
                    if(printFile) {printToFile("OR_OP");}
                    colNum += yyleng;
                    return yy::parser::token::OR_OP;
                }
\*=             {
                    if(printToken) {printConsole("MUL_ASSIGN");}
                    if(printFile) {printToFile("MUL_ASSIGN");}
                    colNum += yyleng;
                    return yy::parser::token::MUL_ASSIGN;
                }
\/=             {
                    if(printToken) {printConsole("DIV_ASSIGN");}
                    if(printFile) {printToFile("DIV_ASSIGN");}
                    colNum += yyleng;
                    return yy::parser::token::DIV_ASSIGN;
                }
%=              {
                    if(printToken) {printConsole("MOD_ASSIGN");}
                    if(printFile) {printToFile("MOD_ASSIGN");}
                    colNum += yyleng;
                    return yy::parser::token::MOD_ASSIGN;
                }
\+=             {
                    if(printToken) {printConsole("ADD_ASSIGN");}
                    if(printFile) {printToFile("ADD_ASSIGN");}
                    colNum += yyleng;
                    return yy::parser::token::ADD_ASSIGN;
                }
-=              {
                    if(printToken) {printConsole("SUB_ASSIGN");}
                    if(printFile) {printToFile("SUB_ASSIGN");}
                    colNum += yyleng;
                    return yy::parser::token::SUB_ASSIGN;
                }
'<<='           {
                    if(printToken) {printConsole("LEFT_ASSIGN");}
                    if(printFile) {printToFile("LEFT_ASSIGN");}
                    colNum += yyleng;
                    return yy::parser::token::LEFT_ASSIGN;
                }
'>>='           {
                    if(printToken) {printConsole("RIGHT_ASSIGN");}
                    if(printFile) {printToFile("RIGHT_ASSIGN");}
                    colNum += yyleng;
                    return yy::parser::token::RIGHT_ASSIGN;
                }
&=              {
                    if(printToken) {printConsole("AND_ASSIGN");}
                    if(printFile) {printToFile("AND_ASSIGN");}
                    colNum += yyleng;
                    return yy::parser::token::AND_ASSIGN;
                }
\|=             {
                    if(printToken) {printConsole("OR_ASSIGN");}
                    if(printFile) {printToFile("OR_ASSIGN");}
                    colNum += yyleng;
                    return yy::parser::token::OR_ASSIGN;
                }
\;              {
                    if(printToken) {printConsole("SEMI");}
                    if(printFile) {printToFile("SEMI");}
                    colNum += yyleng;
                    return yy::parser::token::SEMI;
                }
\:              {
                    if(printToken) {printConsole("COLON");}
                    if(printFile) {printToFile("COLON");}
                    colNum += yyleng;
                    return yy::parser::token::COLON;
                }
\{              {
                    if(printToken) {printConsole("CURLYOPEN");}
                    if(printFile) {printToFile("CURLYOPEN");}
                    colNum += yyleng;
                    return yy::parser::token::CURLYOPEN;
                }
\}              {
                    if(printToken) {printConsole("CURLYCLOSE");}
                    if(printFile) {printToFile("CURLYCLOSE");}
                    colNum += yyleng;
                    return yy::parser::token::CURLYCLOSE;
                }
\[              {
                    if(printToken) {printConsole("BRACKETOPEN");}
                    if(printFile) {printToFile("BRACKETOPEN");}
                    colNum += yyleng;
                    return yy::parser::token::BRACKETOPEN;
                }
\]              {
                    if(printToken) {printConsole("BRACKETCLOSE");}
                    if(printFile) {printToFile("BRACKETCLOSE");}
                    colNum += yyleng;
                    return yy::parser::token::BRACKETCLOSE;
                }
\,              {
                    if(printToken) {printConsole("COMMA");}
                    if(printFile) {printToFile("COMMA");}
                    colNum += yyleng;
                    return yy::parser::token::COMMA;
                }
\.              {
                    if(printToken) {printConsole("PERIOD");}
                    if(printFile) {printToFile("PERIOD");}
                    colNum += yyleng;
                    return yy::parser::token::PERIOD;
                }
\=              {
                    if(printToken) {printConsole("EQUALS");}
                    if(printFile) {printToFile("EQUALS");}
                    colNum += yyleng;
                    return yy::parser::token::EQUALS;
                }
\(              {
                    if(printToken) {printConsole("OPEN");}
                    if(printFile) {printToFile("OPEN");}
                    colNum += yyleng;
                    return yy::parser::token::OPEN;
                }
\)              {
                    if(printToken) {printConsole("CLOSE");}
                    if(printFile) {printToFile("CLOSE");}
                    colNum += yyleng;
                    return yy::parser::token::CLOSE;
                }
\*              {
                    if(printToken) {printConsole("STAR");}
                    if(printFile) {printToFile("STAR");}
                    colNum += yyleng;
                    return yy::parser::token::STAR;
                }
\?              {
                    if(printToken) {printConsole("QUESTION");}
                    if(printFile) {printToFile("QUESTION");}
                    colNum += yyleng;
                    return yy::parser::token::QUESTION;
                }
\|              {
                    if(printToken) {printConsole("BAR");}
                    if(printFile) {printToFile("BAR");}
                    colNum += yyleng;
                    return yy::parser::token::BAR;
                }
\^              {
                    if(printToken) {printConsole("CARROT");}
                    if(printFile) {printToFile("CARROT");}
                    colNum += yyleng;
                    return yy::parser::token::CARROT;
                }
\&              {
                    if(printToken) {printConsole("AMP");}
                    if(printFile) {printToFile("AMP");}
                    colNum += yyleng;
                    return yy::parser::token::AMP;
                }
\<              {
                    if(printToken) {printConsole("LESS_OP");}
                    if(printFile) {printToFile("LESS_OP");}
                    colNum += yyleng;
                    return yy::parser::token::LESS_OP;
                }
\>              {
                    if(printToken) {printConsole("GREAT_OP");}
                    if(printFile) {printToFile("GREAT_OP");}
                    colNum += yyleng;
                    return yy::parser::token::GREAT_OP;
                }
\+              {
                    if(printToken) {printConsole("PLUS");}
                    if(printFile) {printToFile("PLUS");}
                    colNum += yyleng;
                    return yy::parser::token::PLUS;
                }
\-              {
                    if(printToken) {printConsole("MINUS");}
                    if(printFile) {printToFile("MINUS");}
                    colNum += yyleng;
                    return yy::parser::token::MINUS;
                }
\/              {
                    if(printToken) {printConsole("FORSLASH");}
                    if(printFile) {printToFile("FORSLASH");}
                    colNum += yyleng;
                    return yy::parser::token::FORSLASH;
                }
\%              {
                    if(printToken) {printConsole("PERCENT");}
                    if(printFile) {printToFile("PERCENT");}
                    colNum += yyleng;
                    return yy::parser::token::PERCENT;
                }
\!              {
                    if(printToken) {printConsole("BANG");}
                    if(printFile) {printToFile("BANG");}
                    colNum += yyleng;
                    return yy::parser::token::BANG;
                }
\~              {
                    if(printToken) {printConsole("TILDA");}
                    if(printFile) {printToFile("TILDA");}
                    colNum += yyleng;
                    return yy::parser::token::TILDA;
                }
typedef         {
                    if(printToken) {printConsole("TYPEDEF");}
                    if(printFile) {printToFile("TYPEDEF");}
                    colNum += yyleng;
                    return yy::parser::token::TYPEDEF;
                }
extern          {
                    if(printToken) {printConsole("EXTERN");}
                    if(printFile) {printToFile("EXTERN");}
                    colNum += yyleng;
                    return yy::parser::token::EXTERN;
                }
static          {
                    if(printToken) {printConsole("STATIC");}
                    if(printFile) {printToFile("STATIC");}
                    colNum += yyleng;
                    return yy::parser::token::STATIC;
                }
auto            {
                    if(printToken) {printConsole("AUTO");}
                    if(printFile) {printToFile("AUTO");}
                    colNum += yyleng;
                    return yy::parser::token::AUTO;
                }
register        {
                    if(printToken) {printConsole("REGISTER");}
                    if(printFile) {printToFile("REGISTER");}
                    colNum += yyleng;
                    return yy::parser::token::REGISTER;
                }
char            {
                    if(printToken) {printConsole("CHAR");}
                    if(printFile) {printToFile("CHAR");}
                    colNum += yyleng;
                    return yy::parser::token::CHAR;
                }
short           {
                    if(printToken) {printConsole("SHORT");}
                    if(printFile) {printToFile("SHORT");}
                    colNum += yyleng;
                    return yy::parser::token::SHORT;
                }
int             {
                    if(printToken) {printConsole("INT");}
                    if(printFile) {printToFile("INT");}
                    colNum += yyleng;
                    return yy::parser::token::INT;
                }
main            {
                    if(printToken) {printConsole("MAIN");}
                    if(printFile) {printToFile("MAIN");}
                    colNum += yyleng;
                    return yy::parser::token::MAIN;
                }
long            {
                    if(printToken) {printConsole("LONG");}
                    if(printFile) {printToFile("LONG");}
                    colNum += yyleng;
                    return yy::parser::token::LONG;
                }
signed          {
                    if(printToken) {printConsole("SIGNED");}
                    if(printFile) {printToFile("SIGNED");}
                    colNum += yyleng;
                    return yy::parser::token::SIGNED;
                }
unsigned        {
                    if(printToken) {printConsole("UNSIGNED");}
                    if(printFile) {printToFile("UNSIGNED");}
                    colNum += yyleng;
                    return yy::parser::token::UNSIGNED;
                }
float           {
                    if(printToken) {printConsole("FLOAT");}
                    if(printFile) {printToFile("FLOAT");}
                    colNum += yyleng;
                    return yy::parser::token::FLOAT;
                }
double          {
                    if(printToken) {printConsole("DOUBLE");}
                    if(printFile) {printToFile("DOUBLE");}
                    colNum += yyleng;
                    return yy::parser::token::DOUBLE;
                }
const           {
                    if(printToken) {printConsole("CONST");}
                    if(printFile) {printToFile("CONST");}
                    colNum += yyleng;
                    return yy::parser::token::CONST;
                }
volatile        {
                    if(printToken) {printConsole("VOLATILE");}
                    if(printFile) {printToFile("VOLATILE");}
                    colNum += yyleng;
                    return yy::parser::token::VOLATILE;
                }
void            {
                    if(printToken) {printConsole("VOID");}
                    if(printFile) {printToFile("VOID");}
                    colNum += yyleng;
                    return yy::parser::token::VOID;
                }
struct          {
                    if(printToken) {printConsole("STRUCT");}
                    if(printFile) {printToFile("STRUCT");}
                    colNum += yyleng;
                    return yy::parser::token::STRUCT;
                }
union           {
                    if(printToken) {printConsole("UNION");}
                    if(printFile) {printToFile("UNION");}
                    colNum += yyleng;
                    return yy::parser::token::UNION;
                }
enum            {
                    if(printToken) {printConsole("ENUM");}
                    if(printFile) {printToFile("ENUM");}
                    colNum += yyleng;
                    return yy::parser::token::ENUM;
                }
elipsis         {
                    if(printToken) {printConsole("ELIPSIS");}
                    if(printFile) {printToFile("ELIPSIS");}
                    colNum += yyleng;
                    return yy::parser::token::ELIPSIS;
                }
case            {
                    if(printToken) {printConsole("CASE");}
                    if(printFile) {printToFile("CASE");}
                    colNum += yyleng;
                    return yy::parser::token::CASE;
                }
default         {
                    if(printToken) {printConsole("DEFAULT");}
                    if(printFile) {printToFile("DEFAULT");}
                    colNum += yyleng;
                    return yy::parser::token::DEFAULT;
                }
if              {
                    if(printToken) {printConsole("IF");}
                    if(printFile) {printToFile("IF");}
                    colNum += yyleng;
                    return yy::parser::token::IF;
                }
else            {
                    if(printToken) {printConsole("ELSE");}
                    if(printFile) {printToFile("ELSE");}
                    colNum += yyleng;
                    return yy::parser::token::ELSE;
                }
switch          {
                    if(printToken) {printConsole("SWITCH");}
                    if(printFile) {printToFile("SWITCH");}
                    colNum += yyleng;
                    return yy::parser::token::SWITCH;
                }
while           {
                    if(printToken) {printConsole("WHILE");}
                    if(printFile) {printToFile("WHILE");}
                    colNum += yyleng;
                    return yy::parser::token::WHILE;
                }
do              {
                    if(printToken) {printConsole("DO");}
                    if(printFile) {printToFile("DO");}
                    colNum += yyleng;
                    return yy::parser::token::DO;
                }
for             {
                    if(printToken) {printConsole("FOR");}
                    if(printFile) {printToFile("FOR");}
                    colNum += yyleng;
                    return yy::parser::token::FOR;
                }
goto            {
                    if(printToken) {printConsole("GOTO");}
                    if(printFile) {printToFile("GOTO");}
                    colNum += yyleng;
                    return yy::parser::token::GOTO;
                }
continue        {
                    if(printToken) {printConsole("CONTINUE");}
                    if(printFile) {printToFile("CONTINUE");}
                    colNum += yyleng;
                    return yy::parser::token::CONTINUE;
                }
break           {
                    if(printToken) {printConsole("BREAK");}
                    if(printFile) {printToFile("BREAK");}
                    colNum += yyleng;
                    return yy::parser::token::BREAK;
                }
return          {
                    if(printToken) {printConsole("return yy::parser::token::");}
                    if(printFile) {printToFile("return yy::parser::token::");}
                    colNum += yyleng;
                    return yy::parser::token::RETURN;
                }
{name}          {
                    if(printToken) {printConsole("IDENTIFIER");}
                    if(printFile) {printToFile("IDENTIFIER");}
                    colNum +=yyleng;
                    if (yyleng > 31)
                    {
                        std::cout << std::string(colNum,'-') << " ^ "<< "ID LENGTH LONGER THAN 31" << std::endl;
                        return yy::parser::token::ERROR;
                    }
                    return yy::parser::token::IDENTIFIER;
                }
.               {
                    if(printToken) {std::cout << "ERROR" << std::endl;}
                    printError(colNum,yytext);
                    return yy::parser::token::ERROR;
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
    srcFileP.close();
}

void printConsole (std::string token) {
    std::cout << token << std::endl;
}

void printToFile (std::string token) {
    std::ofstream fileP(outSrcFile,std::ios::app);
    fileP << token << std::endl;
    fileP.close();
}
