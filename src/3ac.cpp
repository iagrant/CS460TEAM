#include <stdio.h>
#include <string.h>
#include <vector>
#include <iterator>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>

void walkTree(ASTnode *AST);
void functionHandle(ASTnode * AST);
void equalHandle(ASTnode * AST);
void constantHandle(constantNode * cons);
void print3ac(std::string input);
void printSrc();
void build3AC (ASTnode * currentNode);
void labelHandle (ASTnode * AST);

std::string filename = "3ac.output";
int currentLineNum = 0;
int intTempCount = 0;
int floatTempCount = 0;
int forCount = 0;
int whileCount = 0;
bool debug = true;
extern std::string buffer;
extern std::string srcFile;
extern std::string outSrcFile;
std::vector<std::string> triACStruct;
std::string tempString = "";

void walkTree (ASTnode * parent)
{
    labelHandle(parent);
    for (int i = 0; i < parent->child.size(); i++)
    {
        if (parent->child.size() != 0)
        {
            walkTree(parent->child[i]);
        }
        build3AC(parent);
    }
}
void mathHandle (mathNode * math) {
    enum operationE {addOp, subOp, mulOp, divOp, incOp, decOp, modOp, shlOp, shrOp, andOp, orOp, xorOp, notOp};
    switch (math->operation) {
        case addOp:
            break;
        case subOp:
            break;
        case mulOp:
            break;
        case divOp:
            break;
        case incOp:
            break;
        case decOp:
            break;
        case modOp:
            break;
        case shlOp:
            break;
        case shrOp:
            break;
        case andOp:
            break;
        case orOp:
            break;
        case xorOp:
            break;
        case notOp:
            break;
    }

}

void labelHandle (ASTnode * AST) {
    switch(AST->nodeType) {
        case funcN:
            {
            idNode * id = (idNode *) (AST->child[0]);
            tempString = "";
            tempString.append(id->name.append(":"));
            triACStruct.push_back(tempString);
            tempString = "";
            break;
            }
        case forN:
            {
            tempString = "";
            tempString.append("FOR");
            tempString.append(std::to_string(forCount));
            tempString.append(":");
            triACStruct.push_back(tempString);
            tempString = "";
            break;
            }
        case whileN:
            {
            tempString = "";
            tempString.append("WHILE");
            tempString.append(std::to_string(whileCount));
            tempString.append(":");
            triACStruct.push_back(tempString);
            tempString = "";
            break;
            }
    }
}

// This function just does what it needs and then returns
void build3AC (ASTnode * currentNode)
{
    /*  FIXME kindof work but mostly no work lol
    if (currentNode->lineNum != currentLineNum && currentNode->lineNum != -1){
        currentLineNum=AST->lineNum;
        printSrc();
    }
    */
    if (currentNode->nodeType == funcN)
    {
        // need to know the frame size
        // ticket counter for the function
        // return type?
    }
    else if (currentNode->nodeType == idN)
    {
        // should just return because will be handled by the operator node
    }
    else if (currentNode->production.compare("EQUALS") == 0)
    {
        // needs to assign "ASSIGN des src"
        equalHandle(currentNode);
    }
    else if (currentNode->nodeType == mathN)
    {
        // This side executes before the equals
        // Create temp var for each operator
        // T0 = 4
        // T1 = 5 - T0
        // T2 = 6 * T1
        //mathHandle(currentNode); forgot i accidentally killed this whoops :shrug:
    }
    else if (currentNode->nodeType == forN)
    {
        // create label for iterative statement
        // label has to go above
    }
    else if (currentNode->nodeType == ifN)
    {

    }
    else if (currentNode->nodeType == whileN)
    {

    }
    else if (currentNode->nodeType == constantN)
    {

    }
    else
        return;
}

void functionHandle(ASTnode * AST) {
    //might kill this moved entire thing into labelHandle
}

void equalHandle(ASTnode * AST) {
    if (AST->child.size() > 0){
        if (AST->child[0]->production.compare("IDENTIFIER") == 0){
            idNode * id = (idNode *) (AST->child[0]);
            tempString = ""
            tempString.append(id->name);
            tempString.append(" = ");
            if (AST->child[1]->nodeType == constantN) {
                constantNode * cons = (constantNode *) (AST->child[1]);
                constantHandle(cons);
            }
            if (AST->child.size() > 2) {
                if (AST->child[2]->nodeType == mathN) {
                    mathNode * math = (mathNode *) (AST->child[2]);
                    tempString.append(math->production);
                    if (math->typeSpec == floatS || math->typeSpec == doubleS){
                        intTempCount++;
                        std::string tempName = "fTEMP"+std::to_string(floatTempCount);
                        tempString.append(tempName);
                    }
                    else {
                        intTempCount++;
                        std::string tempName = "iTEMP"+std::to_string(intTempCount);
                        tempString.append(tempName);
                    }
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
        buff = triACStruct[i];
        std::cout << buff << std::endl;
    }
    fileP.close();
    std::cout.rdbuf(coutbuf); //resets cout to stdout
    if (debug) {
        for (int i =0; i < triACStruct.size(); i++) {
            buff = triACStruct[i];
            std::cout << buff << std::endl;
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
