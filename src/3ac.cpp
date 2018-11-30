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
void ifHandleTop(ifNode * ifnode);
void ifHandleBot(ifNode * ifnode);
void whileHandleTop(whileNode * wNode);
void whileHandleBot(whileNode * wNode);
void forHandleTop(forNode * fNode);
void forHandleBot(forNode * fNode);
void equalHandle(ASTnode * AST);
void arrayHandleTop(ASTnode * equal);
void arrayHandleBottom(ASTnode * equal );
void arrayGetHandle(arrayNode * arr);
void exprHandle(exprNode * expr);
void constantHandle(constantNode * cons);
void print3ac(std::string input);
void printSrc();
void build3ACTop (ASTnode * currentNode);
void build3ACBot (ASTnode * currentNode);
void labelHandle (ASTnode * AST);

std::string filename = "3ac.output";
int currentLineNum = 0;
int intTempCount = 0;
int last;
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
    build3ACTop(parent);
    for (int i = 0; i < parent->child.size(); i++)
    {
        if (parent->child.size() != 0)
        {
            walkTree(parent->child[i]);
        }
    }
    build3ACBot(parent);
}

//FIXME
//kill label handle and move func part into func handle
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
            /*
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
            */
            /*
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
            */
    }
}

// This function just does what it needs and then returns
void build3ACBot (ASTnode * currentNode)
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
        forNode * fNode = (forNode *) currentNode;
        forHandleBot(fNode);
        return;
    }
    else if (currentNode->nodeType == ifN)
    {
        ifNode * ifnode = (ifNode *) currentNode;
        ifHandleBot(ifnode);
        return;
    }
    else if (currentNode->nodeType == whileN)
    {
        whileNode * wNode = (whileNode *) currentNode;
        whileHandleBot(wNode);
        return;
    }
    else if (currentNode->nodeType == constantN)
    {

    }
    else
        return;
}
void build3ACTop (ASTnode * currentNode){
    labelHandle(currentNode);
    /*  FIXME kindof work but mostly no work lol
    if (currentNode->lineNum != currentLineNum && currentNode->lineNum != -1){
        currentLineNum=AST->lineNum;
        printSrc();
    }
    */
    if (currentNode->nodeType == funcN)
    {
        // ticket counter for the function
        // return type?
    }
    else if (currentNode->nodeType == idN)
    {
        // should just return because will be handled errythang else
    }
    else if (currentNode->production.compare("EQUALS") == 0) {
        if (currentNode->child[0]->nodeType == arrayN && currentNode->child[1]->nodeType == mathN) {
            arrayHandleTop(currentNode);
        }
    }
    else if (currentNode->nodeType == forN)
    {
        forNode * fNode = (forNode *) currentNode;
        forHandleTop(fNode);
        return;
    }
    else if (currentNode->nodeType == ifN)
    {
        ifNode * ifnode = (ifNode *) currentNode;
        ifHandleTop(ifnode);
        return;
    }
    else if (currentNode->nodeType == whileN)
    {
        whileNode * wNode = (whileNode *) currentNode;
        whileHandleTop(wNode);
        return;
    }
    else
        return;
}

void arrayHandleTop(ASTnode * equal) {
    arrayNode * arr = (arrayNode *) equal->child[0];
    // ADDR OF ID
    tempString.append("ADDR");
    tempString.append("\t");
    std::string tempReg = "iT_"+std::to_string(intTempCount);
    intTempCount++;
    tempString.append(tempReg);
    tempString.append("\t");
    tempString.append(arr->id);
    triACStruct.push_back(tempString);
    tempString = "";
    // ASSIGN INDEX
    tempString.append("ASSIGN");
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    intTempCount++;
    tempString.append(tempReg);
    tempString.append("\t");
    constantNode * tmp = (constantNode *) arr->child[0]->child[0];
    tempString.append(std::to_string(tmp->intConst));
    triACStruct.push_back(tempString);
    tempString = "";
    // MULT INDEX TYPESPEC
    tempString.append("MULT");
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    tempString.append(tempReg);
    intTempCount++;
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount-2);
    tempString.append(tempReg);
    tempString.append("\t");
    tempString.append(std::to_string(arr->determineOffset()));
    triACStruct.push_back(tempString);
    tempString = "";
    // ADD ADDR LASTMULT
    tempString.append("ADD");
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    tempString.append(tempReg);
    last = intTempCount;
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount-1);
    tempString.append(tempReg);
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount-3);
    tempString.append(tempReg);
    triACStruct.push_back(tempString);
    tempString = "";


}

void arrayHandleBottom(ASTnode * equal ) {
    arrayNode * arr = (arrayNode *) equal->child[0];
    // ADDR OF ID
    tempString.append("ADDR");
    tempString.append("\t");
    std::string tempReg = "iT_"+std::to_string(intTempCount);
    intTempCount++;
    tempString.append(tempReg);
    tempString.append("\t");
    tempString.append(arr->id);
    triACStruct.push_back(tempString);
    tempString = "";
    // ASSIGN INDEX
    tempString.append("ASSIGN");
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    intTempCount++;
    tempString.append(tempReg);
    tempString.append("\t");
    constantNode * tmp = (constantNode *) arr->child[0]->child[0];
    tempString.append(std::to_string(tmp->intConst));
    triACStruct.push_back(tempString);
    tempString = "";
    // MULT INDEX TYPESPEC
    tempString.append("MULT");
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    tempString.append(tempReg);
    intTempCount++;
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount-2);
    tempString.append(tempReg);
    tempString.append("\t");
    tempString.append(std::to_string(arr->determineOffset()));
    triACStruct.push_back(tempString);
    tempString = "";
    // ADD ADDR LASTMULT
    tempString.append("ADD");
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    tempString.append(tempReg);
    intTempCount++;
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount-4);
    tempString.append(tempReg);
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount-2);
    tempString.append(tempReg);
    triACStruct.push_back(tempString);
    tempString = "";
    // ASSIGN VALUE O(LASTSUM)
    // RHS OF EQ IS CONSTANT VALUE
    if (equal->child[1]->nodeType == constantN) {
        tempString.append("ASSIGN");
        tempString.append("\t");
        constantNode * val = (constantNode *) equal->child[1];
        tempString.append(std::to_string(val->intConst));
        tempString.append("\t");
        tempReg = "O(iT_"+std::to_string(intTempCount-1)+")";
        tempString.append(tempReg);
    }
    else if (equal->child[1]->nodeType == arrayN) {
        arrayNode * arr = (arrayNode *) equal->child[1];
        // ADDR OF ID
        tempString.append("ADDR");
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount);
        intTempCount++;
        tempString.append(tempReg);
        tempString.append("\t");
        tempString.append(arr->id);
        triACStruct.push_back(tempString);
        tempString = "";
        // ASSIGN INDEX
        tempString.append("ASSIGN");
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        intTempCount++;
        tempString.append(tempReg);
        tempString.append("\t");
        constantNode * tmp = (constantNode *) arr->child[0]->child[0];
        tempString.append(std::to_string(tmp->intConst));
        triACStruct.push_back(tempString);
        tempString = "";
        // MULT INDEX TYPESPEC
        tempString.append("MULT");
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        intTempCount++;
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount-2);
        tempString.append(tempReg);
        tempString.append("\t");
        tempString.append(std::to_string(arr->determineOffset()));
        triACStruct.push_back(tempString);
        tempString = "";
        // ADD ADDR LASTMULT
        tempString.append("ADD");
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        intTempCount++;
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount-4);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount-2);
        tempString.append(tempReg);
        triACStruct.push_back(tempString);
        tempString = "";
        tempString.append("ASSIGN");
        tempString.append("\t");
        tempReg = "O(iT_"+std::to_string(intTempCount-1)+")";
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "O(iT_"+std::to_string(intTempCount-5)+")";
        tempString.append(tempReg);

    }

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
                std::string tempReg = "iT_"+std::to_string(intTempCount);
                tempString.append(tempReg);
            } else {
            }
        }
        // ARRAY ASIGNMENT
        else if (AST->child[0]->production.compare("ARRAY_NODE") == 0 && AST->child[1]->nodeType != mathN) {
            arrayHandleBottom(AST);       
        }
        else if (AST->child[1]->nodeType == mathN) {
            tempString = "";
            tempString.append("ASSIGN");
            tempString.append("\t");
            std::string tempReg = "iT_"+std::to_string(intTempCount);
            tempString.append(tempReg);
            tempString.append("\t");
            tempReg = "O(iT_"+std::to_string(last)+")";
            tempString.append(tempReg);
        }
    }
    triACStruct.push_back(tempString);
    tempString = "";
}

void arrayGetHandle(arrayNode * arr) {
    // ADDR OF ID
    tempString.append("ADDR");
    tempString.append("\t");
    intTempCount++;
    std::string tempReg = "iT_"+std::to_string(intTempCount);
    intTempCount++;
    tempString.append(tempReg);
    tempString.append("\t");
    tempString.append(arr->id);
    triACStruct.push_back(tempString);
    tempString = "";
    // ASSIGN INDEX
    tempString.append("ASSIGN");
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    intTempCount++;
    tempString.append(tempReg);
    tempString.append("\t");
    constantNode * tmp = (constantNode *) arr->child[0]->child[0];
    tempString.append(std::to_string(tmp->intConst));
    triACStruct.push_back(tempString);
    tempString = "";
    // MULT INDEX TYPESPEC
    tempString.append("MULT");
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    tempString.append(tempReg);
    intTempCount++;
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount-2);
    tempString.append(tempReg);
    tempString.append("\t");
    tempString.append(std::to_string(arr->determineOffset()));
    triACStruct.push_back(tempString);
    tempString = "";
    // ADD ADDR LASTMULT
    tempString.append("ADD");
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    tempString.append(tempReg);
    intTempCount++;
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount-4);
    tempString.append(tempReg);
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount-2);
    tempString.append(tempReg);
    triACStruct.push_back(tempString);
    tempString = "";
    tempString.append("ASSIGN");
    tempString.append("\t");
    tempReg = "O(iT_"+std::to_string(intTempCount-1)+")";
    tempString.append(tempReg);
    tempString.append("\t");
    tempReg = "iT_"+std::to_string(intTempCount);
    tempString.append(tempReg);
    triACStruct.push_back(tempString);
    tempString = "";
    
}

void mathHandle(mathNode * math) {
    enum operationE {addOp, subOp, mulOp, divOp, incOp, decOp, modOp, shlOp, shrOp, xorOp};
    if (math->child[0]->nodeType == constantN && math->child[1]->nodeType == mathN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        constantNode * cons = (constantNode *) (math->child[0]);
        constantHandle(cons);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        intTempCount++;
    }
    if (math->child[0]->nodeType == mathN && math->child[1]->nodeType == constantN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        tempString.append("\t");
        constantNode * cons = (constantNode *) (math->child[1]);
        constantHandle(cons);
        intTempCount++;
    }
    else if (math->child[0]->nodeType == mathN && math->child[1]->nodeType == mathN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempReg = "iT_"+std::to_string(intTempCount-1);
        tempString.append("\t");
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        intTempCount++;
    }
    else if (math->child[0]->nodeType == idN && math->child[1]->nodeType == mathN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        idNode * id = (idNode *) (math->child[0]);
        idHandle(id);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        intTempCount++;
    }
    else if (math->child[0]->nodeType == mathN && math->child[1]->nodeType == idN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        tempString.append("\t");
        idNode * id = (idNode *) (math->child[1]);
        idHandle(id);
        intTempCount++;
    }
    else if (math->child[0]->nodeType == constantN && math->child[1]->nodeType == constantN)
    {
        tempString.append(math->production);
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append("\t");
        tempString.append(tempReg);
        constantNode * cons1 = (constantNode *) (math->child[0]);
        tempString.append("\t");
        constantHandle(cons1);
        tempString.append("\t");
        constantNode * cons2 = (constantNode *) (math->child[1]);
        constantHandle(cons2);
        intTempCount++;
    }
    else if (math->child[0]->nodeType == idN && math->child[1]->nodeType == idN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        idNode * id1 = (idNode *) (math->child[0]);
        idHandle(id1);
        tempString.append("\t");
        idNode * id2 = (idNode *) (math->child[1]);
        idHandle(id2);
        intTempCount++;
    }
    else if (math->child[0]->nodeType == constantN && math->child[1]->nodeType == idN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        constantNode * cons1 = (constantNode *) (math->child[0]);
        constantHandle(cons1);
        tempString.append("\t");
        idNode * id2 = (idNode *) (math->child[1]);
        idHandle(id2);
        intTempCount++;
    }
    else if (math->child[0]->nodeType == idN && math->child[1]->nodeType == constantN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        idNode * id2 = (idNode *) (math->child[0]);
        idHandle(id2);
        tempString.append("\t");
        constantNode * cons1 = (constantNode *) (math->child[1]);
        constantHandle(cons1);
        intTempCount++;
    } else if (math->child[0]->nodeType == mathN && math->child[1]->nodeType == constantN)
    {
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        tempString.append("\t");
        constantNode * cons1 = (constantNode *) (math->child[1]);
        constantHandle(cons1);
        intTempCount++;
        
    } else if (math->child[0]->nodeType == arrayN && 
               math->child[1]->nodeType == constantN)
    {
        arrayNode * arr = (arrayNode *) math->child[0];
        arrayGetHandle(arr);
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        tempString.append("\t");
        constantNode * cons1 = (constantNode *) (math->child[1]);
        constantHandle(cons1);
        intTempCount++;
    } else if (math->child[0]->nodeType == arrayN && 
               math->child[1]->nodeType == idN)
    {
        arrayNode * arr = (arrayNode *) math->child[0];
        arrayGetHandle(arr);
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        tempString.append("\t");
        idNode * id1 = (idNode *) (math->child[1]);
        idHandle(id1);
        intTempCount++;
    } else if (math->child[0]->nodeType == constantN && 
               math->child[1]->nodeType == arrayN)
    {
        arrayNode * arr = (arrayNode *) math->child[0];
        arrayGetHandle(arr);
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        tempString.append("\t");
        constantNode * cons1 = (constantNode *) (math->child[1]);
        constantHandle(cons1);
        intTempCount++;
    } else if (math->child[0]->nodeType == arrayN && 
               math->child[1]->nodeType == idN)
    {
        arrayNode * arr = (arrayNode *) math->child[0];
        arrayGetHandle(arr);
        tempString.append(math->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
        tempString.append("\t");
        idNode * id1 = (idNode *) (math->child[1]);
        idHandle(id1);
        intTempCount++;
    }
    else if (math->operation == incOp) {
        //inc by 1
        tempString.append("ADD");
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        idNode * id2 = (idNode *) (math->child[0]);
        idHandle(id2);
        tempString.append("\t");
        tempString.append("1");
        intTempCount++;
        triACStruct.push_back(tempString);
        tempString = "";
        //storing res
        tempString.append("ASSIGN");
        tempString.append("\t");
        idHandle(id2);
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(intTempCount));

    }
    else if (math->operation == decOp) {
        tempString.append("SUB");
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        idNode * id2 = (idNode *) (math->child[0]);
        idHandle(id2);
        tempString.append("\t");
        tempString.append("1");
        intTempCount++;
    }
    triACStruct.push_back(tempString);
    tempString = "";
}
void ifHandleTop(ifNode * ifnode) {
    //BRANCHES in MIPS the label comes last
    //BREQ SRC1 SRC2 LABEL
    if (ifnode->child[0]->nodeType ==constantN) {
        tempString.append("BREQ");
        tempString.append("\t");
        constantNode * cons = (constantNode *) (ifnode->child[0]);
        constantHandle(cons);
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("FI_"+std::to_string(ifCount));
    }
    else {
        exprNode * expr = (exprNode *) ifnode->child[0];
        exprHandle(expr);
        ASTnode * logicOp = ifnode->child[0];
        tempString.append("BREQ");
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(intTempCount));
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("FI_"+std::to_string(ifCount));
    }
    //uncomment for nested if fix
    //tho breaks concurent ifs
    //ifCount++;
    triACStruct.push_back(tempString);
    tempString = "";
};

void ifHandleBot(ifNode * ifnode) {
    //uncomment for nested if fix
    //tho breaks concurent ifs
    //tempString.append("IF_"+std::to_string(ifCount-1)+":");
    tempString.append("FI_"+std::to_string(ifCount)+":");
    triACStruct.push_back(tempString);
    ifCount++;
    tempString = "";
};
void idHandle(idNode * id) {
    tempString.append(id->name);
}
//{{{

void exprHandle(exprNode * expr){
    //LOGIC_OP DST SRC1 SRC2
    //ie LT DST SRC1 SRC2   store res of SRC1 < SRC2 inside DST
    //1 if SRC 1 < SRC2 else 0
    if (expr->child[0]->nodeType == idN && expr->child[1]->nodeType == constantN) {
        tempString.append(expr->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        idNode * id = (idNode *) expr->child[0];
        tempString.append("\t");
        tempString.append(id->name);
        constantNode * cons = (constantNode *) expr->child[1];
        tempString.append("\t");
        constantHandle(cons);
    }
    else if (expr->child[0]->nodeType == constantN && expr->child[1]->nodeType == idN){
        tempString.append(expr->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        constantNode * cons = (constantNode *) expr->child[0];
        tempString.append("\t");
        constantHandle(cons);
        idNode * id = (idNode *) expr->child[1];
        tempString.append("\t");
        tempString.append(id->name);
    }
    else if (expr->child[0]->nodeType == constantN && expr->child[1]->nodeType == exprN){
        exprNode * expr1 = (exprNode *) expr->child[1];
        exprHandle(expr1);
        tempString.append(expr->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        constantNode * cons = (constantNode *) expr->child[0];
        tempString.append("\t");
        constantHandle(cons);
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(intTempCount));
    }
    else if (expr->child[0]->nodeType == exprN && expr->child[1]->nodeType == constantN){
        exprNode * expr1 = (exprNode *) expr->child[0];
        exprHandle(expr1);
        tempString.append(expr->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(intTempCount));
        constantNode * cons = (constantNode *) expr->child[1];
        tempString.append("\t");
        constantHandle(cons);
    }
    else if (expr->child[0]->nodeType == exprN && expr->child[1]->nodeType == exprN){
        exprNode * expr1 = (exprNode *) expr->child[0];
        exprHandle(expr1);
        exprNode * expr2 = (exprNode *) expr->child[1];
        exprHandle(expr2);
        tempString.append(expr->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount-1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(intTempCount);
        tempString.append(tempReg);
    }
    else if (expr->child[0]->nodeType == idN && expr->child[1]->nodeType == exprN){
        exprNode * expr1 = (exprNode *) expr->child[1];
        exprHandle(expr1);
        tempString.append(expr->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        idNode * id = (idNode *) expr->child[0];
        tempString.append("\t");
        tempString.append(id->name);
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(intTempCount+1));
    }
    else if (expr->child[0]->nodeType == exprN && expr->child[1]->nodeType == idN){
        exprNode * expr1 = (exprNode *) expr->child[0];
        exprHandle(expr1);
        tempString.append(expr->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(intTempCount+1));
        idNode * id = (idNode *) expr->child[1];
        tempString.append("\t");
        tempString.append(id->name);
    }
    else if (expr->child[0]->nodeType == constantN && expr->child[1]->nodeType == constantN){
        tempString.append(expr->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        constantNode * cons = (constantNode *) expr->child[0];
        tempString.append("\t");
        constantHandle(cons);
        cons = (constantNode *) expr->child[1];
        tempString.append("\t");
        constantHandle(cons);
    }
    else if (expr->child[0]->nodeType == idN && expr->child[1]->nodeType == idN) {
        tempString.append(expr->production);
        tempString.append("\t");
        std::string tempReg = "iT_"+std::to_string(intTempCount+1);
        tempString.append(tempReg);
        idNode * id = (idNode *) expr->child[0];
        tempString.append("\t");
        tempString.append(id->name);
        id = (idNode *) expr->child[1];
        tempString.append("\t");
        tempString.append(id->name);
    }
    triACStruct.push_back(tempString);
    tempString="";
    intTempCount++;
};
//}}}
void constantHandle(constantNode * cons) {
    //FIXME add cons or fcons infront of it
    //to desinate between int const and float const
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

void whileHandleTop(whileNode * whilenode) {
    tempString.append("BEGWHILE_"+std::to_string(whileCount)+":");
    triACStruct.push_back(tempString);
    tempString = "";
    //BRANCHES in MIPS the label comes last
    //BREQ SRC1 SRC2 LABEL
    if (whilenode->child[0]->nodeType ==constantN) {
        tempString.append("BREQ");
        tempString.append("\t");
        constantNode * cons = (constantNode *) (whilenode->child[0]);
        constantHandle(cons);
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("ENDWHILE_"+std::to_string(whileCount));
    }
    else {
        exprNode * expr = (exprNode *) whilenode->child[0];
        exprHandle(expr);
        ASTnode * logicOp = whilenode->child[0];
        tempString.append("BREQ");
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(intTempCount));
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("ENDWHILE_"+std::to_string(whileCount));
    }
    //uncomment for nested while fix
    //tho breaks concurent whiles
    //whileCount++;
    triACStruct.push_back(tempString);
    tempString = "";
};

void whileHandleBot(whileNode * whilenode) {
    //uncomment for nested while fix
    //tho breaks concurent whiles
    //tempString.append("IF_"+std::to_string(whileCount-1)+":");
    tempString.append("BR");
    tempString.append("\t");
    tempString.append("BEGWHILE_"+std::to_string(whileCount));
    triACStruct.push_back(tempString);
    tempString = "";
    tempString.append("ENDWHILE_"+std::to_string(whileCount)+":");
    triACStruct.push_back(tempString);
    tempString = "";
    whileCount++;
};


void forHandleTop(forNode * fornode) {
    tempString.append("BEGFOR_"+std::to_string(forCount)+":");
    triACStruct.push_back(tempString);
    tempString = "";
    //BRANCHES in MIPS the label comes last
    //BREQ SRC1 SRC2 LABEL
    if (fornode->child[0]->nodeType ==constantN) {
        tempString.append("BREQ");
        tempString.append("\t");
        constantNode * cons = (constantNode *) (fornode->child[0]);
        constantHandle(cons);
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("ENDFOR_"+std::to_string(forCount));
    }
    else {
        exprNode * expr = (exprNode *) fornode->child[1];
        exprHandle(expr);
        ASTnode * logicOp = fornode->child[0];
        tempString.append("BREQ");
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(intTempCount));
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("ENDFOR_"+std::to_string(forCount));
    }
    //uncomment for nested for fix
    //tho breaks concurent fors
    //forCount++;
    triACStruct.push_back(tempString);
    tempString = "";
};

void forHandleBot(forNode * fornode) {
    //uncomment for nested for fix
    //tho breaks concurent fors
    //tempString.append("IF_"+std::to_string(forCount-1)+":");
    tempString.append("BR");
    tempString.append("\t");
    tempString.append("BEGFOR_"+std::to_string(forCount));
    triACStruct.push_back(tempString);
    tempString = "";
    tempString.append("ENDFOR_"+std::to_string(forCount)+":");
    triACStruct.push_back(tempString);
    tempString = "";
    forCount++;
};
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
