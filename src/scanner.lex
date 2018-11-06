
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

#include "symbolTable.cpp"
#include "ASTnode.cpp"
#include "C_grammar.tab.h"

#define POS_INT_MAX 2147483646
#define NEG_INT_MAX -2147483647
/*
#define POS_DOUBLE_MAX 1.7E+308
#define NEG_DOUBLE_MAX 2.3E-308
*/
extern int yylex();
extern int yyparse();

int lineNum = 1;
int tabNum = 0;
int colNum = 1;
bool printToken = false;
bool printSymbol = false;
bool printSymbolNums = false;
bool printProductions = false;
bool printFile = true;
bool printSource = false;
bool buildingFunction = false;
bool firstPrint = true;
std::string buffer = "";
std::string srcFile = "";
std::string outSrcFile = "output.txt";
SymbolTable globalSymbolTable; // construct Symbol Table
Node globalTempNode;           // temp ST node for pass around
std::ofstream scannerOut; 		// File pointer for scanner
std::ofstream productionOut;
std::string tokenFlag = "!!dl";
std::string symbolFlag = "!!ds";
std::string productionFlag = "!!dp";
Node * funcNode;
std::map<std::string,Node>::reverse_iterator funcPair = globalSymbolTable.currentScope->rend();

void printError (int colNum,std::string errorTok);
void printConsole (std::string token);
void printToFile (std::string token);
void printLine ();

%}

%option noyywrap
alpha   [A-Za-z]
dig     [0-9]
name    ({alpha}|{dig}|\$)({alpha}|{dig}|[_.\-/$])*
num1    [-+]?{dig}+\.?([eE][-+]?{dig}+)?
num2    [-+]?{dig}*\.{dig}+([eE][-+]?{dig}+)?
escaped \\[anrtbfv0]
number  {num1}|{num2}

%%
\n              {/*std::cout << "Line: " << lineNum << "   Col: " << colNum << std::endl;*/ lineNum++; colNum = 1; tabNum = 0;
                    //print the buffer
                    if(printSource){
						printLine();
						firstPrint = false;
					}
                    globalTempNode.resetNode(); //resets node to avoid any mess from getting multiline bois
                    buildingFunction=false; //resets flag that says wheter a flag is being buitl
                    funcPair=globalSymbolTable.getCurrentEnd(); //resets function pair
                }
\r
[ ]	        	{colNum++; /* skip white space */ }
\t		        {tabNum++;/* inc tab num for errMsg */}
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
                	if (tokenFlag.compare(yytext)==0)
                    {
                        if(printToken)
                            printToken = false;
                        else
                            printToken = true;
                    }
                    if (productionFlag.compare(yytext)==0)
                    {
                        if(printProductions)
                        {
                            printProductions = false;
                            printSource = false;
                        }
                        else
                        {
                            printLine();
                            printProductions = true;
                            printSource = true;

                        }
                    }
                    if (symbolFlag.compare(yytext)==0)
                    {
                        std::cout << "CURRENT SCOPE LEVEL: " << globalSymbolTable.currentScopeNum << std::endl;
                        globalSymbolTable.printST();
                    }
                }
[-]?[0-9]+      {
                    if(printToken) {printConsole("INTEGER_CONSTANT");}
                    if(printFile) {printToFile("INTEGER_CONSTANT");}
                    colNum += yyleng;
                    //std::cout << yytext << std::endl;
                    if (yyleng > 9)
                        std::cout << "\033[4;93mWARNING: POSSIBLE INT OVERFLOW\033[0m"<< std::endl;
                    return INTEGER_CONSTANT;
                }
[0-9]+\.?[0-9]* {
                    if(printToken) {printConsole("FLOATING_CONSTANT");}
                    if(printFile) {printToFile("FLOATING_CONSTANT");}
                    colNum += yyleng;
                    return FLOATING_CONSTANT;
                }
'(\\.|[^\\'])+' {
                    if(printToken) {printConsole("CHARACTER_CONSTANT");}
                    if(printFile) {printToFile("CHARACTER_CONSTANT");}
                    colNum += yyleng;
                    return CHARACTER_CONSTANT;
                }
"ENUM"          {
                    if(printToken) {printConsole("ENUMERATION_CONSTANT");}
                    if(printFile) {printToFile("ENUMERATION_CONSTANT");}
                    colNum += yyleng;
                    return ENUMERATION_CONSTANT;
                }
\"(\\.|[^\\"])*\" {
                    if(printToken) {printConsole("STRING_LITERAL");}
                    if(printFile) {printToFile("STRING_LITERAL");}
                    colNum += yyleng;
                    return STRING_LITERAL;
                }
sizeof          {
                    if(printToken) {printConsole("SIZEOF");}
                    if(printFile) {printToFile("SIZEOF");}
                    colNum += yyleng;
                    return SIZEOF;
                }
\+\+            {
                    if(printToken) {printConsole("INC_OP");}
                    if(printFile) {printToFile("INC_OP");}
                    colNum += yyleng;
                    return INC_OP;
                }
--              {
                    if(printToken) {printConsole("DEC_OP");}
                    if(printFile) {printToFile("DEC_OP");}
                    colNum += yyleng;
                    return DEC_OP;
                }
\<\<            {
                    if(printToken) {printConsole("LEFT_OP");}
                    if(printFile) {printToFile("LEFT_OP");}
                    colNum += yyleng;
                    return LEFT_OP;
                }
>>              {
                    if(printToken) {printConsole("RIGHT_OP");}
                    if(printFile) {printToFile("RIGHT_OP");}
                    colNum += yyleng;
                    return RIGHT_OP;
                }
\<=             {
                    if(printToken) {printConsole("LE_OP");}
                    if(printFile) {printToFile("LE_OP");}
                    colNum += yyleng;
                    return LE_OP;
                }
>=              {
                    if(printToken) {printConsole("GE_OP");}
                    if(printFile) {printToFile("GE_OP");}
                    colNum += yyleng;
                    return GE_OP;
                }
==              {
                    if(printToken) {printConsole("EQ_OP");}
                    if(printFile) {printToFile("EQ_OP");}
                    colNum += yyleng;
                    return EQ_OP;
                }
!=              {
                    if(printToken) {printConsole("NE_OP");}
                    if(printFile) {printToFile("NE_OP");}
                    colNum += yyleng;
                    return NE_OP;
                }
&&              {
                    if(printToken) {printConsole("AND_OP");}
                    if(printFile) {printToFile("AND_OP");}
                    colNum += yyleng;
                    return AND_OP;
                }
\|\|            {
                    if(printToken) {printConsole("OR_OP");}
                    if(printFile) {printToFile("OR_OP");}
                    colNum += yyleng;
                    return OR_OP;
                }
\*=             {
                    if(printToken) {printConsole("MUL_ASSIGN");}
                    if(printFile) {printToFile("MUL_ASSIGN");}
                    colNum += yyleng;
                    return MUL_ASSIGN;
                }
\/=             {
                    if(printToken) {printConsole("DIV_ASSIGN");}
                    if(printFile) {printToFile("DIV_ASSIGN");}
                    colNum += yyleng;
                    return DIV_ASSIGN;
                }
%=              {
                    if(printToken) {printConsole("MOD_ASSIGN");}
                    if(printFile) {printToFile("MOD_ASSIGN");}
                    colNum += yyleng;
                    return MOD_ASSIGN;
                }
\+=             {
                    if(printToken) {printConsole("ADD_ASSIGN");}
                    if(printFile) {printToFile("ADD_ASSIGN");}
                    colNum += yyleng;
                    return ADD_ASSIGN;
                }
-=              {
                    if(printToken) {printConsole("SUB_ASSIGN");}
                    if(printFile) {printToFile("SUB_ASSIGN");}
                    colNum += yyleng;
                    return SUB_ASSIGN;
                }
"<<="           {
                    if(printToken) {printConsole("LEFT_ASSIGN");}
                    if(printFile) {printToFile("LEFT_ASSIGN");}
                    colNum += yyleng;
                    return LEFT_ASSIGN;
                }
">>="          {
                    if(printToken) {printConsole("RIGHT_ASSIGN");}
                    if(printFile) {printToFile("RIGHT_ASSIGN");}
                    colNum += yyleng;
                    return RIGHT_ASSIGN;
                }
&=              {
                    if(printToken) {printConsole("AND_ASSIGN");}
                    if(printFile) {printToFile("AND_ASSIGN");}
                    colNum += yyleng;
                    return AND_ASSIGN;
                }
\|=             {
                    if(printToken) {printConsole("OR_ASSIGN");}
                    if(printFile) {printToFile("OR_ASSIGN");}
                    colNum += yyleng;
                    return OR_ASSIGN;
                }
\;              {
                    if(printToken) {printConsole("SEMI");}
                    if(printFile) {printToFile("SEMI");}
                    colNum += yyleng;
                    return SEMI;
                }
\:              {
                    if(printToken) {printConsole("COLON");}
                    if(printFile) {printToFile("COLON");}
                    colNum += yyleng;
                    return COLON;
                }
\{              {
                    if(printToken) {printConsole("CURLYOPEN");}
                    if(printFile) {printToFile("CURLYOPEN");}
                    colNum += yyleng;
                    //globalSymbolTable.addNewScope();
                    globalSymbolTable.mode == lookup;
                    return CURLYOPEN;
                }
\}              {
                    if(printToken) {printConsole("CURLYCLOSE");}
                    if(printFile) {printToFile("CURLYCLOSE");}
                    colNum += yyleng;
                    if (lineNum != globalTempNode.getLine())
                        globalSymbolTable.removeScope();
                    return CURLYCLOSE;
                }
\[              {
                    if(printToken) {printConsole("BRACKETOPEN");}
                    if(printFile) {printToFile("BRACKETOPEN");}
                    colNum += yyleng;
                    std::map<std::string,Node>::reverse_iterator last = globalSymbolTable.currentScope->rend();
                    last = globalSymbolTable.getCurrentPair();
                    if (last != globalSymbolTable.getCurrentEnd()){
                        //std::cout << "BRACK: " << last->second.getName() << std::endl;
                        if (last->second.getLine() == lineNum){
                            last->second.isArray=true;
                        }
                    }
                    return BRACKETOPEN;
                }
\]              {
                    if(printToken) {printConsole("BRACKETCLOSE");}
                    if(printFile) {printToFile("BRACKETCLOSE");}
                    colNum += yyleng;
                    return BRACKETCLOSE;
                }
\,              {
                    if(printToken) {printConsole("COMMA");}
                    if(printFile) {printToFile("COMMA");}
                    colNum += yyleng;
                    //reset node on comma to fix func param types
                    if (buildingFunction)
                        globalTempNode.resetNode();
                    return COMMA;
                }
\.              {
                    if(printToken) {printConsole("PERIOD");}
                    if(printFile) {printToFile("PERIOD");}
                    colNum += yyleng;
                    return PERIOD;
                }
\=              {
                    if(printToken) {printConsole("EQUALS");}
                    if(printFile) {printToFile("EQUALS");}
                    colNum += yyleng;
                    return EQUALS;
                }
\(              {
                    if(printToken) {printConsole("OPEN");}
                    if(printFile) {printToFile("OPEN");}
                    colNum += yyleng;
                    std::map<std::string,Node>::reverse_iterator last = globalSymbolTable.currentScope->rend();
                    last = globalSymbolTable.getCurrentPair();
                    if (last != globalSymbolTable.currentScope->rend()){
                        //std::cout << "PER: " << last->second.getName() << std::endl;
                        if (last->second.getLine() == lineNum){
                            last->second.setFunction();
                            buildingFunction=true;
                            funcPair=last;
                            globalSymbolTable.addNewScope();
                        }
                    }
                    return OPEN;
                }
\)              {
                    if(printToken) {printConsole("CLOSE");}
                    if(printFile) {printToFile("CLOSE");}
                    colNum += yyleng;
                    return CLOSE;
                    //if proto pop scope here
                }
\*              {
                    if(printToken) {printConsole("STAR");}
                    if(printFile) {printToFile("STAR");}
                    colNum += yyleng;
                    return STAR;
                }
\?              {
                    if(printToken) {printConsole("QUESTION");}
                    if(printFile) {printToFile("QUESTION");}
                    colNum += yyleng;
                    return QUESTION;
                }
\|              {
                    if(printToken) {printConsole("BAR");}
                    if(printFile) {printToFile("BAR");}
                    colNum += yyleng;
                    return BAR;
                }
\^              {
                    if(printToken) {printConsole("CARROT");}
                    if(printFile) {printToFile("CARROT");}
                    colNum += yyleng;
                    return CARROT;
                }
\&              {
                    if(printToken) {printConsole("AMP");}
                    if(printFile) {printToFile("AMP");}
                    colNum += yyleng;
                    return AMP;
                }
\<              {
                    if(printToken) {printConsole("LESS_OP");}
                    if(printFile) {printToFile("LESS_OP");}
                    colNum += yyleng;
                    return LESS_OP;
                }
\>              {
                    if(printToken) {printConsole("GREAT_OP");}
                    if(printFile) {printToFile("GREAT_OP");}
                    colNum += yyleng;
                    return GREAT_OP;
                }
\+              {
                    if(printToken) {printConsole("PLUS");}
                    if(printFile) {printToFile("PLUS");}
                    colNum += yyleng;
                    return PLUS;
                }
\-              {
                    if(printToken) {printConsole("MINUS");}
                    if(printFile) {printToFile("MINUS");}
                    colNum += yyleng;
                    return MINUS;
                }
\/              {
                    if(printToken) {printConsole("FORSLASH");}
                    if(printFile) {printToFile("FORSLASH");}
                    colNum += yyleng;
                    return FORSLASH;
                }
\%              {
                    if(printToken) {printConsole("PERCENT");}
                    if(printFile) {printToFile("PERCENT");}
                    colNum += yyleng;
                    return PERCENT;
                }
\!              {
                    if(printToken) {printConsole("BANG");}
                    if(printFile) {printToFile("BANG");}
                    colNum += yyleng;
                    return BANG;
                }
\~              {
                    if(printToken) {printConsole("TILDA");}
                    if(printFile) {printToFile("TILDA");}
                    colNum += yyleng;
                    return TILDA;
                }
typedef         {
                    if(printToken) {printConsole("TYPEDEF");}
                    if(printFile) {printToFile("TYPEDEF");}
                    colNum += yyleng;
                    return TYPEDEF;
                }
extern          {
                    if(printToken) {printConsole("EXTERN");}
                    if(printFile) {printToFile("EXTERN");}
                    colNum += yyleng;
                    return EXTERN;
                }
static          {
                    if(printToken) {printConsole("STATIC");}
                    if(printFile) {printToFile("STATIC");}
                    colNum += yyleng;
                    return STATIC;
                }
auto            {
                    if(printToken) {printConsole("AUTO");}
                    if(printFile) {printToFile("AUTO");}
                    colNum += yyleng;
                    return AUTO;
                }
register        {
                    if(printToken) {printConsole("REGISTER");}
                    if(printFile) {printToFile("REGISTER");}
                    colNum += yyleng;
                    return REGISTER;
                }
char            {
                    if(printToken) {printConsole("CHAR");}
                    if(printFile) {printToFile("CHAR");}
                    colNum += yyleng;
                    return CHAR;
                }
short           {
                    if(printToken) {printConsole("SHORT");}
                    if(printFile) {printToFile("SHORT");}
                    colNum += yyleng;
                    return SHORT;
                }
int             {
                    if(printToken) {printConsole("INT");}
                    if(printFile) {printToFile("INT");}
                    colNum += yyleng;
                    return INT;
                }
long            {

                    if(printToken) {printConsole("LONG");}
                    if(printFile) {printToFile("LONG");}
                    colNum += yyleng;
                    return LONG;
                }
signed          {
                    if(printToken) {printConsole("SIGNED");}
                    if(printFile) {printToFile("SIGNED");}
                    colNum += yyleng;
                    return SIGNED;
                }
unsigned        {
                    if(printToken) {printConsole("UNSIGNED");}
                    if(printFile) {printToFile("UNSIGNED");}
                    colNum += yyleng;
                    return UNSIGNED;
                }
float           {
                    if(printToken) {printConsole("FLOAT");}
                    if(printFile) {printToFile("FLOAT");}
                    colNum += yyleng;
                    return FLOAT;
                }
double          {
                    if(printToken) {printConsole("DOUBLE");}
                    if(printFile) {printToFile("DOUBLE");}
                    colNum += yyleng;
                    return DOUBLE;
                }
const           {
                    if(printToken) {printConsole("CONST");}
                    if(printFile) {printToFile("CONST");}
                    colNum += yyleng;
                    return CONST;
                }
volatile        {
                    if(printToken) {printConsole("VOLATILE");}
                    if(printFile) {printToFile("VOLATILE");}
                    colNum += yyleng;
                    return VOLATILE;
                }
void            {
                    if(printToken) {printConsole("VOID");}
                    if(printFile) {printToFile("VOID");}
                    colNum += yyleng;
                    return VOID;
                }
struct          {
                    if(printToken) {printConsole("STRUCT");}
                    if(printFile) {printToFile("STRUCT");}
                    colNum += yyleng;
                    return STRUCT;
                }
union           {
                    if(printToken) {printConsole("UNION");}
                    if(printFile) {printToFile("UNION");}
                    colNum += yyleng;
                    return UNION;
                }
enum            {
                    if(printToken) {printConsole("ENUM");}
                    if(printFile) {printToFile("ENUM");}
                    colNum += yyleng;
                    return ENUM;
                }
elipsis         {
                    if(printToken) {printConsole("ELIPSIS");}
                    if(printFile) {printToFile("ELIPSIS");}
                    colNum += yyleng;
                    return ELIPSIS;
                }
case            {
                    if(printToken) {printConsole("CASE");}
                    if(printFile) {printToFile("CASE");}
                    colNum += yyleng;
                    return CASE;
                }
default         {
                    if(printToken) {printConsole("DEFAULT");}
                    if(printFile) {printToFile("DEFAULT");}
                    colNum += yyleng;
                    return DEFAULT;
                }
if              {
                    if(printToken) {printConsole("IF");}
                    if(printFile) {printToFile("IF");}
                    colNum += yyleng;
                    globalSymbolTable.addNewScope();
                    return IF;
                }
else            {
                    if(printToken) {printConsole("ELSE");}
                    if(printFile) {printToFile("ELSE");}
                    colNum += yyleng;
                    globalSymbolTable.addNewScope();
                    return ELSE;
                }
switch          {
                    if(printToken) {printConsole("SWITCH");}
                    if(printFile) {printToFile("SWITCH");}
                    colNum += yyleng;
                    return SWITCH;
                }
while           {
                    if(printToken) {printConsole("WHILE");}
                    if(printFile) {printToFile("WHILE");}
                    colNum += yyleng;
                    globalSymbolTable.addNewScope();
                    return WHILE;
                }
do              {
                    if(printToken) {printConsole("DO");}
                    if(printFile) {printToFile("DO");}
                    colNum += yyleng;
                    return DO;
                }
for             {
                    if(printToken) {printConsole("FOR");}
                    if(printFile) {printToFile("FOR");}
                    colNum += yyleng;
                    globalSymbolTable.addNewScope();
                    return FOR;
                }
goto            {
                    if(printToken) {printConsole("GOTO");}
                    if(printFile) {printToFile("GOTO");}
                    colNum += yyleng;
                    return GOTO;
                }
continue        {
                    if(printToken) {printConsole("CONTINUE");}
                    if(printFile) {printToFile("CONTINUE");}
                    colNum += yyleng;
                    return CONTINUE;
                }
break           {
                    if(printToken) {printConsole("BREAK");}
                    if(printFile) {printToFile("BREAK");}
                    colNum += yyleng;
                    return BREAK;
                }
return          {
                    if(printToken) {printConsole("return ");}
                    if(printFile) {printToFile("return ");}
                    colNum += yyleng;
                    return RETURN;
                }
{name}          {
                    if(printToken) {printConsole("IDENTIFIER");}
                    if(printFile) {printToFile("IDENTIFIER");}
					if (printSource && firstPrint)
						printLine();
                    colNum += yyleng;
                    if (yyleng > 31)
                    {
                        std::cout << std::string(colNum,'-') << " ^ "<< "ID LENGTH LONGER THAN 31" << std::endl;
                        return ERROR;
                    }
                    return IDENTIFIER;
                }
.               {
                    if(printToken) {std::cout << "ERROR" << std::endl;}
                    printError(colNum,yytext);
                    return ERROR;
                }
%%
void printError (int colNum, std::string errorTok) {
    std::ifstream srcFileP(srcFile);
    for (int i = 0; i < lineNum; i++)
    {
        std::getline(srcFileP,buffer);
    }
    std::cout << buffer << std::endl;
    std::cout << std::string(tabNum, '\t') << std::string(colNum - 1,'-') << "\033[1;91m^ Unidentifed Token: \033[0m\033[4;33m"
    		  << errorTok << "\033[0m on Line: " << lineNum
    		  << " and Column: " << colNum <<std::endl;
    srcFileP.close();
}

void printLine () {
    std::ifstream srcFileP(srcFile);
    for (int i = 0; i < lineNum; i++) {
        std::getline(srcFileP,buffer);
    }
    std::cout << lineNum << " " << buffer << std::endl;
	productionOut << lineNum << " " << buffer << std::endl;
    srcFileP.close();
}

void printConsole (std::string token) {
    std::cout << token << std::endl;
}

/*
void printSubTree (ASTnode * parent) {
    if (printGraphviz)
    {
        static int inc = 0;
        parent->printLabel = inc;
        astFileP << parent->printLabel << " \[label=\"" << parent->printASTnode() << "\"\];" << std::endl;
        std::cout << parent->printLabel << " \[label=\"" << parent->printASTnode() << "\"\];" << std::endl;
        inc++;

        for (int i = 0; i < parent->child.size(); i++)
        {
            if (parent->child.size() != 0)
            {
                printSubTree(parent->child[i]);
                astFileP << parent->printLabel << " -> " << parent->child[i]->printLabel << std::endl;
                std::cout << parent->printLabel << " -> " << parent->child[i]->printLabel << std::endl;
            }
        }
    }
}
*/

void printToFile (std::string token) {
    scannerOut.open("ScannerOutput.txt",std::ofstream::app);
    scannerOut << token << std::endl;
    scannerOut.close();
}

void unleash () {
//    string file = "";
  std::ifstream in("secret/secret_w_colorcodes.txt");

    std::string line;
    while(getline(in, line)) {
        std::cout << "\033[1;30;47m";
        std::cout << line << std::endl;
        std::cout << "\033[0m";
    }
    in.close();
}
