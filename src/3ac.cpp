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
void constantHandle(ASTnode * AST);
void print3ac(std::string input);
void printSrc();

std::string filename = "3ac.output";
int currentLineNum = 0;
int tempCount = 0;
bool debug = true;
extern std::string buffer;
extern std::string srcFile;
extern std::string outSrcFile;
std::list<std::string> triACStruct;
std::string tempString = "";

void walk(ASTnode *AST) {
    if (AST->production.compare("FUNCTION") == 0) {
        functionHandle(AST);
        walkChild(AST->child[0]);
    }
    if (AST->production.compare("IDENTIFIER") == 0) {
        walkChild(AST);
        //idHandle(AST);
    }
    if (AST->production.compare("DECLARATION") == 0) {
    }
    if (AST->production.compare("EQUALS") == 0) {
        equalHandle(AST);
    }
    if (AST->production.compare("+") == 0) {
        //addHandle(AST);
    }
    if (AST->production.compare("FOR") == 0) {
        //go all the way through the statement node
        //then implement the check of the for below it
    }
    if (AST->production.compare("IF") == 0) {
    }
    if (AST->production.compare("WHILE") == 0) {
    }
    if (AST->production.find("CONSTANT") != std::string::npos) {
        constantHandle(AST);
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
    print3ac(tempString);
    tempString = "";
}
void equalHandle(ASTnode * AST) {
    if (AST->child.size() > 0){
        walkChild(AST);
        if (AST->child[0]->production.compare("IDENTIFIER") == 0){
            idNode * id = (idNode *) (AST->child[0]);
            tempString = id->name;
            tempString.append(" = ");
            if (AST->child[1]->production.find("CONSTANT") != std::string::npos) {
                constantNode * cons = (constantNode *) (AST->child[1]);
                if (AST->child[1]->production.compare("INTEGER_CONSTANT") == 0) {
                    tempString.append(std::to_string(cons->intConst));
                }
                if (AST->child[1]->production.compare("FLOATING_CONSTANT") == 0) {
                    //show that the tempReg is a float
                    tempString.append(std::to_string(cons->doubleConst));
                }
                if (AST->child[1]->production.compare("CHARACTER_CONSTANT") == 0) {
                    tempString.append(std::to_string((int)cons->charConst));
                }
            }
        }
        print3ac(tempString);
        tempString = "";
    }
}
void constantHandle(ASTnode * AST) {

}

void printSrc () {
    std::ifstream srcFileP(srcFile);
    std::string buffer="";
    for (int i = 0; i < currentLineNum; i++)
    {
        std::getline(srcFileP,buffer);
    }
    print3ac(buffer);
    srcFileP.close();
}
void print3ac(std::string input) {
    std::ofstream fileP(filename,std::ios::app);
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(fileP.rdbuf()); //changes cout to print to file stream
    std::cout << input << std::endl;
    fileP.close();
    std::cout.rdbuf(coutbuf); //resets cout to stdout
    if (debug) {
        std::cout << input << std::endl;
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
