#include <stdio.h>
#include <string.h>
#include <list>
#include <iterator>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>

void walk(ASTnode *AST);
void walkChild(ASTnode * parent);
void functionHandle(ASTnode * AST);
void equalHandle(ASTnode * AST);
void constantHandle(constantNode * cons);
void print3ac(std::string input);
void printSrc();

std::string filename = "3ac.output";
int currentLineNum = 0;
int intTempCount = 0;
int floatTempCount = 0;
bool debug = true;
extern std::string buffer;
extern std::string srcFile;
extern std::string outSrcFile;
std::list<std::string> triACStruct;
std::string tempString = "";

void walk(ASTnode *AST) {
    if (AST->lineNum != currentLineNum && AST->lineNum != -1){
        currentLineNum=AST->lineNum;
        printSrc();
    }
    //function node
    if (AST->nodeType == funcN) {
        functionHandle(AST);
        walkChild(AST->child[0]);
    }
    //id node
    if (AST->nodeType == idN) {
        walkChild(AST);
        //idHandle(AST);
    }
    if (AST->production.compare("EQUALS") == 0) {
        equalHandle(AST);
    }
    //math Node
    if (AST->nodeType == mathN) {
        //addHandle(AST);
    }
    if (AST->nodeType == forN) {
        //go all the way through the statement node
        //then implement the check of the for below it
    }
    if (AST->nodeType == ifN) {
    }
    if (AST->nodeType == whileN) {
    }
    if (AST->nodeType == constantN) {
        //constantHandle(AST);
    }
    else
        walkChild(AST);
}

void walkChild(ASTnode * parent){
    for (int i = 0; i < parent->child.size(); i++)
    {
        if (parent->child.size() != 0)
        {
            walk(parent->child[i]);
        }
    }
}
void functionHandle(ASTnode * AST) {
    idNode * id = (idNode *) (AST->child[0]);
    tempString = "";
    tempString.append(id->name.append(":"));
    triACStruct.push_back(tempString);
    tempString = "";
}
void equalHandle(ASTnode * AST) {
    if (AST->child.size() > 0){
        walkChild(AST);
        if (AST->child[0]->production.compare("IDENTIFIER") == 0){
            idNode * id = (idNode *) (AST->child[0]);
            tempString = id->name;
            tempString.append(" = ");
            if (AST->child[1]->nodeType == constantN) {
                constantNode * cons = (constantNode *) (AST->child[1]);
                constantHandle(cons);
            }
            if (AST->child.size() > 2) {
                if (AST->child[2]->nodeType == mathN) {
                    mathNode * math = (mathNode *) (AST->child[2]);
                    tempString.append(math->production);
                    intTempCount++;
                    std::string test = "iT"+std::to_string(intTempCount);
                    tempString.append(test);
                }
            }
        }
        triACStruct.push_back(tempString);
        tempString = "";
    }
}
void constantHandle(constantNode * cons) {
    //prbly won't use this lol
    if (cons->intConst != NULL) {
        tempString.append(std::to_string(cons->intConst));
    }
    if (cons->doubleConst != NULL) {
        //show that the tempReg is a float
        tempString.append(std::to_string(cons->doubleConst));
    }
    if (cons->charConst != NULL) {
        tempString.append(std::to_string((int)cons->charConst));
    }
    if (cons->production.compare("STRING_LITERAL") == 0) {
        //break each letter up and load the int val of the letter into a temp
        //then? idk
        //but def not this lmao
        //tempString.append(std::to_string(cons->stringConst));
    }
}

//change this from printing to adding src code lines to triACStruct
void printSrc () {
    std::ifstream srcFileP(srcFile);
    std::string buffer="";
    std::string out="##";
    for (int i = 0; i < currentLineNum; i++)
    {
        std::getline(srcFileP,buffer);
    }
    out.append(buffer);
    srcFileP.close();
    triACStruct.push_back(out);
}
void clear3ac(std::string input) {
    std::ofstream fileP(filename);
    fileP.close();
}
void print3ac() {
    //std::ofstream fileP(filename,std::ios::app);
    std::ofstream fileP(filename);
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(fileP.rdbuf()); //changes cout to print to file stream
    std::string buff = ""; //it's a strong string :)
    for (int i =0; i < triACStruct.size(); i++) {
        buff = triACStruct.front();
        triACStruct.pop_front();
    }
    std::cout << buff << std::endl;
    fileP.close();
    std::cout.rdbuf(coutbuf); //resets cout to stdout
    if (debug) {
        for (int i =0; i < triACStruct.size(); i++) {
            buff = triACStruct.front();
            triACStruct.pop_front();
        }
    }
}
        /*
        std::ofstream fileP(filename,std::ios::app);
        std::streambuf *coutbuf = std::cout.rdbuf();
        std::cout.rdbuf(fileP.rdbuf()); //changes cout to print to file stream
        printNode();
        printer(std::endl;
        std::cout.rdbuf(coutbuf); //resets cout to stdout
        fileP.close();
        */
