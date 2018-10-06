
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

#define POS_INT_MAX 2147483646
#define NEG_INT_MAX -2147483647
/*
#define POS_DOUBLE_MAX 1.7E+308
#define NEG_DOUBLE_MAX 2.3E-308
*/

int lineNum = 1;
int colNum = 1;
bool printToken = false;
bool printSymbol = false;
bool printProductions = false;
std::string buffer = "";
std::string srcFile = "";
std::string outSrcFile = "";

void printError (int colNum,std::string errorTok);
void printConsole (std::string token);
void printFile (std::string token);

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
                    if(printToken) {printConsole("DEBUG");}
                    if(printFile) {printFile("DEBUG");}
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
                    if(printToken) {printConsole("INTEGER_CONSTANT");}
                    if(printFile) {printFile("INTEGER_CONSTANT");}
                    colNum += yyleng;
                    std::cout << yytext << std::endl;
                    if (std::atoi(yytext) > POS_INT_MAX || std::atoi(yytext) < NEG_INT_MAX)
                        std::cout << "POSSIBLE INT OVERFLOW" << std::endl;
                    ////return INTEGER_CONSTANT;
                }
[0-9]+\.?[0-9]* {
                    if(printToken) {printConsole("FLOATING_CONSTANT");}
                    if(printFile) {printFile("FLOATING_CONSTANT");}
                    colNum += yyleng;
                    ////return FLOATING_CONSTANT;
                }
\'(\\.|.)\'     {
                    if(printToken) {printConsole("CHARACTER_CONSTANT");}
                    if(printFile) {printFile("CHARACTER_CONSTANT");}
                    colNum += yyleng;
                    ////return CHARACTER_CONSTANT;
                }
"ENUM"          {
                    if(printToken) {printConsole("ENUMERATION_CONSTANT");}
                    if(printFile) {printFile("ENUMERATION_CONSTANT");}
                    colNum += yyleng;
                    ////return ENUMERATION_CONSTANT;
                }
\"[A-z]+\"      {
                    if(printToken) {printConsole("STRING_LITERAL");}
                    if(printFile) {printFile("STRING_LITERAL");}
                    colNum += yyleng;
                    ////return STRING_LITERAL;
                }
sizeof          {
                    if(printToken) {printConsole("SIZEOF");}
                    if(printFile) {printFile("SIZEOF");}
                    colNum += yyleng;
                    ////return SIZEOF;
                }
\+\+            {
                    if(printToken) {printConsole("INC_OP");}
                    if(printFile) {printFile("INC_OP");}
                    colNum += yyleng;
                    ////return INC_OP;
                }
--              {
                    if(printToken) {printConsole("DEC_OP");}
                    if(printFile) {printFile("DEC_OP");}
                    colNum += yyleng;
                    ////return DEC_OP;
                }
\<\<            {
                    if(printToken) {printConsole("LEFT_OP");}
                    if(printFile) {printFile("LEFT_OP");}
                    colNum += yyleng;
                    ////return LEFT_OP;
                }
>>              {
                    if(printToken) {printConsole("RIGHT_OP");}
                    if(printFile) {printFile("RIGHT_OP");}
                    colNum += yyleng;
                    ////return RIGHT_OP;
                }
\<=             {
                    if(printToken) {printConsole("LE_OP");}
                    if(printFile) {printFile("LE_OP");}
                    colNum += yyleng;
                    ////return LE_OP;
                }
>=              {
                    if(printToken) {printConsole("GE_OP");}
                    if(printFile) {printFile("GE_OP");}
                    colNum += yyleng;
                    ////return GE_OP;
                }
==              {
                    if(printToken) {printConsole("EQ_OP");}
                    if(printFile) {printFile("EQ_OP");}
                    colNum += yyleng;
                    ////return EQ_OP;
                }
!=              {
                    if(printToken) {printConsole("NE_OP");}
                    if(printFile) {printFile("NE_OP");}
                    colNum += yyleng;
                    //return NE_OP;
                }
&&              {
                    if(printToken) {printConsole("AND_OP");}
                    if(printFile) {printFile("AND_OP");}
                    colNum += yyleng;
                    //return AND_OP;
                }
\|\|            {
                    if(printToken) {printConsole("OR_OP");}
                    if(printFile) {printFile("OR_OP");}
                    colNum += yyleng;
                    //return OR_OP;
                }
\*=             {
                    if(printToken) {printConsole("MUL_ASSIGN");}
                    if(printFile) {printFile("MUL_ASSIGN");}
                    colNum += yyleng;
                    //return MUL_ASSIGN;
                }
\/=             {
                    if(printToken) {printConsole("DIV_ASSIGN");}
                    if(printFile) {printFile("DIV_ASSIGN");}
                    colNum += yyleng;
                    //return DIV_ASSIGN;
                }
%=              {
                    if(printToken) {printConsole("MOD_ASSIGN");}
                    if(printFile) {printFile("MOD_ASSIGN");}
                    colNum += yyleng;
                    //return MOD_ASSIGN;
                }
\+=             {
                    if(printToken) {printConsole("ADD_ASSIGN");}
                    if(printFile) {printFile("ADD_ASSIGN");}
                    colNum += yyleng;
                    //return ADD_ASSIGN;
                }
-=              {
                    if(printToken) {printConsole("SUB_ASSIGN");}
                    if(printFile) {printFile("SUB_ASSIGN");}
                    colNum += yyleng;
                    //return SUB_ASSIGN;
                }
'<<='           {
                    if(printToken) {printConsole("LEFT_ASSIGN");}
                    if(printFile) {printFile("LEFT_ASSIGN");}
                    colNum += yyleng;
                    //return LEFT_ASSIGN;
                }
'>>='           {
                    if(printToken) {printConsole("RIGHT_ASSIGN");}
                    if(printFile) {printFile("RIGHT_ASSIGN");}
                    colNum += yyleng;
                    //return RIGHT_ASSIGN;
                }
&=              {
                    if(printToken) {printConsole("AND_ASSIGN");}
                    if(printFile) {printFile("AND_ASSIGN");}
                    colNum += yyleng;
                    //return AND_ASSIGN;
                }
\|=             {
                    if(printToken) {printConsole("OR_ASSIGN");}
                    if(printFile) {printFile("OR_ASSIGN");}
                    colNum += yyleng;
                    //return OR_ASSIGN;
                }
\;              {
                    if(printToken) {printConsole("SEMI");}
                    if(printFile) {printFile("SEMI");}
                    colNum += yyleng;
                    //return SEMI;
                }
\:              {
                    if(printToken) {printConsole("COLON");}
                    if(printFile) {printFile("COLON");}
                    colNum += yyleng;
                    //return COLON;
                }
\{              {
                    if(printToken) {printConsole("CURLYOPEN");}
                    if(printFile) {printFile("CURLYOPEN");}
                    colNum += yyleng;
                    //return CURLYOPEN;
                }
\}              {
                    if(printToken) {printConsole("CURLYCLOSE");}
                    if(printFile) {printFile("CURLYCLOSE");}
                    colNum += yyleng;
                    //return CURLYCLOSE;
                }
\[              {
                    if(printToken) {printConsole("BRACKETOPEN");}
                    if(printFile) {printFile("BRACKETOPEN");}
                    colNum += yyleng;
                    //return BRACKETOPEN;
                }
\]              {
                    if(printToken) {printConsole("BRACKETCLOSE");}
                    if(printFile) {printFile("BRACKETCLOSE");}
                    colNum += yyleng;
                    //return BRACKETCLOSE;
                }
\,              {
                    if(printToken) {printConsole("COMMA");}
                    if(printFile) {printFile("COMMA");}
                    colNum += yyleng;
                    //return COMMA;
                }
\.              {
                    if(printToken) {printConsole("PERIOD");}
                    if(printFile) {printFile("PERIOD");}
                    colNum += yyleng;
                    //return PERIOD;
                }
\=              {
                    if(printToken) {printConsole("EQUALS");}
                    if(printFile) {printFile("EQUALS");}
                    colNum += yyleng;
                    //return EQUALS;
                }
\(              {
                    if(printToken) {printConsole("OPEN");}
                    if(printFile) {printFile("OPEN");}
                    colNum += yyleng;
                    //return OPEN;
                }
\)              {
                    if(printToken) {printConsole("CLOSE");}
                    if(printFile) {printFile("CLOSE");}
                    colNum += yyleng;
                    //return CLOSE;
                }
\*              {
                    if(printToken) {printConsole("STAR");}
                    if(printFile) {printFile("STAR");}
                    colNum += yyleng;
                    //return STAR;
                }
\?              {
                    if(printToken) {printConsole("QUESTION");}
                    if(printFile) {printFile("QUESTION");}
                    colNum += yyleng;
                    //return QUESTION;
                }
\|              {
                    if(printToken) {printConsole("BAR");}
                    if(printFile) {printFile("BAR");}
                    colNum += yyleng;
                    //return BAR;
                }
\^              {
                    if(printToken) {printConsole("CARROT");}
                    if(printFile) {printFile("CARROT");}
                    colNum += yyleng;
                    //return CARROT;
                }
\&              {
                    if(printToken) {printConsole("AMP");}
                    if(printFile) {printFile("AMP");}
                    colNum += yyleng;
                    //return AMP;
                }
\<              {
                    if(printToken) {printConsole("LESS_OP");}
                    if(printFile) {printFile("LESS_OP");}
                    colNum += yyleng;
                    //return LESS_OP;
                }
\>              {
                    if(printToken) {printConsole("GREAT_OP");}
                    if(printFile) {printFile("GREAT_OP");}
                    colNum += yyleng;
                    //return GREAT_OP;
                }
\+              {
                    if(printToken) {printConsole("PLUS");}
                    if(printFile) {printFile("PLUS");}
                    colNum += yyleng;
                    //return PLUS;
                }
\-              {
                    if(printToken) {printConsole("MINUS");}
                    if(printFile) {printFile("MINUS");}
                    colNum += yyleng;
                    //return MINUS;
                }
\/              {
                    if(printToken) {printConsole("FORSLASH");}
                    if(printFile) {printFile("FORSLASH");}
                    colNum += yyleng;
                    //return FORSLASH;
                }
\%              {
                    if(printToken) {printConsole("PERCENT");}
                    if(printFile) {printFile("PERCENT");}
                    colNum += yyleng;
                    //return PERCENT;
                }
\!              {
                    if(printToken) {printConsole("BANG");}
                    if(printFile) {printFile("BANG");}
                    colNum += yyleng;
                    //return BANG;
                }
\~              {
                    if(printToken) {printConsole("TILDA");}
                    if(printFile) {printFile("TILDA");}
                    colNum += yyleng;
                    //return TILDA;
                }
typedef         {
                    if(printToken) {printConsole("TYPEDEF");}
                    if(printFile) {printFile("TYPEDEF");}
                    colNum += yyleng;
                    //return TYPEDEF;
                }
extern          {
                    if(printToken) {printConsole("EXTERN");}
                    if(printFile) {printFile("EXTERN");}
                    colNum += yyleng;
                    //return EXTERN;
                }
static          {
                    if(printToken) {printConsole("STATIC");}
                    if(printFile) {printFile("STATIC");}
                    colNum += yyleng;
                    //return STATIC;
                }
auto            {
                    if(printToken) {printConsole("AUTO");}
                    if(printFile) {printFile("AUTO");}
                    colNum += yyleng;
                    //return AUTO;
                }
register        {
                    if(printToken) {printConsole("REGISTER");}
                    if(printFile) {printFile("REGISTER");}
                    colNum += yyleng;
                    //return REGISTER;
                }
char            {
                    if(printToken) {printConsole("CHAR");}
                    if(printFile) {printFile("CHAR");}
                    colNum += yyleng;
                    //return CHAR;
                }
short           {
                    if(printToken) {printConsole("SHORT");}
                    if(printFile) {printFile("SHORT");}
                    colNum += yyleng;
                    //return SHORT;
                }
int             {
                    if(printToken) {printConsole("INT");}
                    if(printFile) {printFile("INT");}
                    colNum += yyleng;
                    //return INT;
                }
main            {
                    if(printToken) {printConsole("MAIN");}
                    if(printFile) {printFile("MAIN");}
                    colNum += yyleng;
                    //return MAIN;
                }
long            {
                    if(printToken) {printConsole("LONG");}
                    if(printFile) {printFile("LONG");}
                    colNum += yyleng;
                    //return LONG;
                }
signed          {
                    if(printToken) {printConsole("SIGNED");}
                    if(printFile) {printFile("SIGNED");}
                    colNum += yyleng;
                    //return SIGNED;
                }
unsigned        {
                    if(printToken) {printConsole("UNSIGNED");}
                    if(printFile) {printFile("UNSIGNED");}
                    colNum += yyleng;
                    //return UNSIGNED;
                }
float           {
                    if(printToken) {printConsole("FLOAT");}
                    if(printFile) {printFile("FLOAT");}
                    colNum += yyleng;
                    //return FLOAT;
                }
double          {
                    if(printToken) {printConsole("DOUBLE");}
                    if(printFile) {printFile("DOUBLE");}
                    colNum += yyleng;
                    //return DOUBLE;
                }
const           {
                    if(printToken) {printConsole("CONST");}
                    if(printFile) {printFile("CONST");}
                    colNum += yyleng;
                    //return CONST;
                }
volatile        {
                    if(printToken) {printConsole("VOLATILE");}
                    if(printFile) {printFile("VOLATILE");}
                    colNum += yyleng;
                    //return VOLATILE;
                }
void            {
                    if(printToken) {printConsole("VOID");}
                    if(printFile) {printFile("VOID");}
                    colNum += yyleng;
                    //return VOID;
                }
struct          {
                    if(printToken) {printConsole("STRUCT");}
                    if(printFile) {printFile("STRUCT");}
                    colNum += yyleng;
                    //return STRUCT;
                }
union           {
                    if(printToken) {printConsole("UNION");}
                    if(printFile) {printFile("UNION");}
                    colNum += yyleng;
                    //return UNION;
                }
enum            {
                    if(printToken) {printConsole("ENUM");}
                    if(printFile) {printFile("ENUM");}
                    colNum += yyleng;
                    //return ENUM;
                }
elipsis         {
                    if(printToken) {printConsole("ELIPSIS");}
                    if(printFile) {printFile("ELIPSIS");}
                    colNum += yyleng;
                    //return ELIPSIS;
                }
case            {
                    if(printToken) {printConsole("CASE");}
                    if(printFile) {printFile("CASE");}
                    colNum += yyleng;
                    //return CASE;
                }
default         {
                    if(printToken) {printConsole("DEFAULT");}
                    if(printFile) {printFile("DEFAULT");}
                    colNum += yyleng;
                    //return DEFAULT;
                }
if              {
                    if(printToken) {printConsole("IF");}
                    if(printFile) {printFile("IF");}
                    colNum += yyleng;
                    //return IF;
                }
else            {
                    if(printToken) {printConsole("ELSE");}
                    if(printFile) {printFile("ELSE");}
                    colNum += yyleng;
                    //return ELSE;
                }
switch          {
                    if(printToken) {printConsole("SWITCH");}
                    if(printFile) {printFile("SWITCH");}
                    colNum += yyleng;
                    //return SWITCH;
                }
while           {
                    if(printToken) {printConsole("WHILE");}
                    if(printFile) {printFile("WHILE");}
                    colNum += yyleng;
                    //return WHILE;
                }
do              {
                    if(printToken) {printConsole("DO");}
                    if(printFile) {printFile("DO");}
                    colNum += yyleng;
                    //return DO;
                }
for             {
                    if(printToken) {printConsole("FOR");}
                    if(printFile) {printFile("FOR");}
                    colNum += yyleng;
                    //return FOR;
                }
goto            {
                    if(printToken) {printConsole("GOTO");}
                    if(printFile) {printFile("GOTO");}
                    colNum += yyleng;
                    //return GOTO;
                }
continue        {
                    if(printToken) {printConsole("CONTINUE");}
                    if(printFile) {printFile("CONTINUE");}
                    colNum += yyleng;
                    //return CONTINUE;
                }
break           {
                    if(printToken) {printConsole("BREAK");}
                    if(printFile) {printFile("BREAK");}
                    colNum += yyleng;
                    //return BREAK;
                }
return          {
                    if(printToken) {printConsole("RETURN");}
                    if(printFile) {printFile("RETURN");}
                    colNum += yyleng;
                    //return RETURN;
                }
{name}          {
                    if(printToken) {printConsole("IDENTIFIER");}
                    if(printFile) {printFile("IDENTIFIER");}
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

void printConsole (std::string token) {
    std::cout << token << std::endl;
}


void printFile (std::string token) {
    std::cout << token << std::endl;
}

int main (int argc, char** argv)
{
    std::string tokenFlag = "-dl";
	std::string symbolFlag = "-ds";
	std::string fhFlag = "-fh";
	std::string productionFlag = "-p";
    std::string inputFlag = "-i";
    std::string outputFlag = "-o";
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
            if (i+1 < argc)
                srcFile = argv[i++];
            else
            {
                std::cout << "ERROR: PLEASE SPECIFIY A SRC CODE FILE AFTER -i" << std::endl;
                return 0;
            }
        }
        if ((outputFlag.compare(argv[i]))==0)
        {
            if (i+1 < argc)
                outSrcFile = argv[i++];
            else
            {
                std::cout << "ERROR: PLEASE SPECIFIY A SRC CODE FILE AFTER -o" << std::endl;
                return 0;
            }
        }
    }

    FlexLexer* lexer = new yyFlexLexer;
    while(lexer->yylex() != 0)
    ;
    return 0;
}
