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
void mathHandle(mathNode * math);
void idHandle(idNode * id);
void ifHandle(ifNode * ifnode);
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
int ifCount = 0;
int forCount = 0;
int whileCount = 0;
bool debug = true;
static int tempCounter = 1;
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
    }
    build3AC(parent);
}

void labelHandle (ASTnode * AST) {
    switch(AST->nodeType) {
        case funcN:
            {
            idNode * id = (idNode *) (AST->child[0]);
            tempString = "";
            tempString.append(id->name.append(":"));
            functionHandle(AST);
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
        return;
    }
    else if (currentNode->production.compare("EQUALS") == 0)
    {
        equalHandle(currentNode);
        // needs to assign "ASSIGN des src"
    }
    else if (currentNode->nodeType == mathN)
    {
        mathNode * math = (mathNode *) currentNode;
        mathHandle(math);
        return;
    }
    else if (currentNode->nodeType == forN)
    {

    }
    else if (currentNode->nodeType == ifN)
    {
        std::cout << "CUNT" << std::endl;
        ifNode * ifnode = (ifNode *) currentNode;
        ifHandle(ifnode);
        return;
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
    functionNode * func = (functionNode *) AST;
    tempString.append(" ");
    tempString.append(std::to_string(func->activationFrameSize));
}

// ASSIGN DST SRC
void equalHandle(ASTnode * AST) {
    if (AST->child.size() > 0){
        if (AST->child[0]->production.compare("IDENTIFIER") == 0){
            if (AST->child[1]->nodeType == constantN) {
                tempString.append("ASSIGN");
                tempString.append("\t");
                idNode * id = (idNode *) (AST->child[0]);
                tempString.append(id->name);
                tempString.append("\t");
                constantNode * cons = (constantNode *) (AST->child[1]);
                constantHandle(cons);
            } else if (AST->child[1]->nodeType == mathN){
                tempString.append("ASSIGN");
                tempString.append("\t");
                mathNode * math = (mathNode *) (AST->child[1]);
                idNode * id = (idNode *) (AST->child[0]);
                tempString.append(id->name);
                tempString.append("\t");
                std::string test = "iT_"+std::to_string(intTempCount);
                tempString.append(test);
            } else {
                std::cout << "Some thing else" << std::endl;
            }
        }
    }
    triACStruct.push_back(tempString);
    tempString = "";
}

void mathHandle(mathNode * math) {
    if (math->child[0]->nodeType == constantN && math->child[1]->nodeType == mathN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string test = "iT_"+std::to_string(intTempCount+1);
        tempString.append(test);
        tempString.append("\t");
        constantNode * cons = (constantNode *) (math->child[0]);
        constantHandle(cons);
        tempString.append("\t");
        test = "iT_"+std::to_string(intTempCount);
        tempString.append(test);
        intTempCount++;
    } else if (math->child[0]->nodeType == mathN && math->child[1]->nodeType == mathN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string test = "iT_"+std::to_string(intTempCount+1);
        tempString.append(test);
        test = "iT_"+std::to_string(intTempCount-1);
        tempString.append("\t");
        tempString.append(test);
        tempString.append("\t");
        test = "iT_"+std::to_string(intTempCount);
        tempString.append(test);
        intTempCount++;
    } else if (math->child[0]->nodeType == idN && math->child[1]->nodeType == mathN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string test = "iT_"+std::to_string(intTempCount+1);
        tempString.append(test);
        tempString.append("\t");
        idNode * id = (idNode *) (math->child[0]);
        idHandle(id);
        tempString.append("\t");
        test = "iT_"+std::to_string(intTempCount);
        tempString.append(test);
        intTempCount++;
    } else if (math->child[0]->nodeType == constantN && math->child[1]->nodeType == constantN)
    {
        tempString.append(math->production);
        std::string test = "iT_"+std::to_string(intTempCount+1);
        tempString.append("\t");
        tempString.append(test);
        constantNode * cons1 = (constantNode *) (math->child[0]);
        tempString.append("\t");
        constantHandle(cons1);
        tempString.append("\t");
        constantNode * cons2 = (constantNode *) (math->child[1]);
        constantHandle(cons2);
        intTempCount++;
    } else if (math->child[0]->nodeType == idN && math->child[1]->nodeType == idN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string test = "iT_"+std::to_string(intTempCount+1);
        tempString.append(test);
        tempString.append("\t");
        idNode * id1 = (idNode *) (math->child[0]);
        idHandle(id1);
        tempString.append("\t");
        idNode * id2 = (idNode *) (math->child[1]);
        idHandle(id2);
        intTempCount++;
    } else if (math->child[0]->nodeType == constantN && math->child[1]->nodeType == idN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string test = "iT_"+std::to_string(intTempCount+1);
        tempString.append(test);
        tempString.append("\t");
        constantNode * cons1 = (constantNode *) (math->child[0]);
        constantHandle(cons1);
        tempString.append("\t");
        idNode * id2 = (idNode *) (math->child[1]);
        idHandle(id2);
        intTempCount++;
    } else if (math->child[0]->nodeType == idN && math->child[1]->nodeType == constantN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string test = "iT_"+std::to_string(intTempCount+1);
        tempString.append(test);
        tempString.append("\t");
        idNode * id2 = (idNode *) (math->child[0]);
        idHandle(id2);
        tempString.append("\t");
        constantNode * cons1 = (constantNode *) (math->child[1]);
        constantHandle(cons1);
        intTempCount++;
    }
    triACStruct.push_back(tempString);
    tempString = "";
}
void ifHandle(ifNode * ifnode) {
    //LOGIC_OP DST SRC1 SRC2
    //ie LT DST SRC1 SRC2   store res of SRC1 < SRC2 inside DST
    ASTnode * logicOp = ifnode->child[0];
    tempString.append(ifnode->child[0]->production);
    tempString.append("\t");
    std::string test = "iT_"+std::to_string(intTempCount+1);
    tempString.append(test);
    if (logicOp->child[0]->nodeType == idN && logicOp->child[1]->nodeType == constantN) {
        idNode * id = (idNode *) logicOp->child[0];
        tempString.append("\t");
        tempString.append(id->name);
        constantNode * cons = (constantNode *) logicOp->child[1];
        tempString.append("\t");
        constantHandle(cons);
    }
    intTempCount++;
};

void idHandle(idNode * id) {
    tempString.append(id->name);
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
        //then push onto stack and set value of id on stack table to the addr of 1st
        //elem of the (int) char array on the stack
        //
        // ALERT! see below
        //
        //but def not this lmao or maybe mips has store string.
        //a boi can dream
        //aparently a boi can dream
        //https://stackoverflow.com/questions/7969565/mips-how-to-store-user-input-string
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
