#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <iterator>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>

void tempRHS();
void tempLHS();
void tempDST();
void tempInc();

void walkTree(ASTnode *AST);
void functionHandle(ASTnode * AST);
void functionCallHandle(ASTnode * AST);
void returnHandle(ASTnode * AST);
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
void array2DHandleBottom(arrayNode * equal);
void arrayGetHandle(arrayNode * arr);
void handleRHSArray(ASTnode * equal);
void exprHandle(exprNode * expr);
void constantHandle(constantNode * cons);
void constantHandleElec(constantNode * cons);
void print3ac();
void offHandle(ASTnode * AST);
void offHandleA(ASTnode * AST);
void printSrc();
void build3ACTop (ASTnode * currentNode);
void build3ACBot (ASTnode * currentNode);
void labelHandle (ASTnode * AST);

std::string filename = "3ac.output";
std::string tempReg = "";
int currentLineNum = 0;
int intTempCount = 0;
int last;
int floatTempCount = 0;
std::list <int> tempStack;
int tempUsage=0;
int tempUsage1=0;
//int ifCount = 0;
//int forCount = 0;
//int whileCount = 0;
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
            tempString.append(id->name);
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

void tempRHSArr() {
    tempUsage = tempStack.front();
    tempStack.pop_front();
    tempReg = "0(iT_"+std::to_string(tempUsage)+")";
    tempString.append(tempReg);
}

void tempRHS() {
    tempUsage = tempStack.front();
    tempStack.pop_front();
    tempReg = "iT_"+std::to_string(tempUsage);
    tempString.append(tempReg);
}

void tempLHS() {
    tempReg = "iT_"+std::to_string(intTempCount);
    tempString.append(tempReg);

    tempStack.push_front(intTempCount);
    intTempCount++;
}

void tempDST() {
    tempReg = "iT_"+std::to_string(intTempCount);
    tempString.append(tempReg);
}

void tempInc(){
    tempStack.push_front(intTempCount);
    intTempCount++;
}

void idInsideArrBrrk(idNode * id) {
        tempString.append("LOAD");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        idHandle(id);
}

// This function just does what it needs and then returns
void build3ACBot (ASTnode * currentNode)
{
    if (currentNode->nodeType == funcN)
    {
        // need to know the frame size
        // ticket counter for the function
        // return type?
    }
    else if (currentNode->nodeType == funcCallN)
    {
        functionCallHandle(currentNode);
    }
    else if (currentNode->nodeType == returnN)
    {
        returnHandle(currentNode);
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
        //lmao
    }
    else
        return;
}
void build3ACTop (ASTnode * currentNode){
    if (currentNode->lineNum != currentLineNum && currentNode->lineNum != -1){
        currentLineNum=currentNode->lineNum;
        printSrc();
    }
    labelHandle(currentNode);
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
    // ASSIGN INDEX
        // Array Index Cases
    if (arr->child[0]->child[0]->nodeType == constantN) {

        tempString.append("ADDR");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempString.append("A_"+std::to_string(arr->offset));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();

        tempString.append("ASSIGN");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
            constantNode * tmp = (constantNode *) arr->child[0]->child[0];
            tempString.append(std::to_string(tmp->intConst));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    }
    //FIXME append val of id
    else if (arr->child[0]->child[0]->nodeType == idN) {
        tempString.append("ADDR");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempString.append("A_"+std::to_string(arr->offset));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();

                idNode * tmp = (idNode *) arr->child[0]->child[0];
                idInsideArrBrrk(tmp);
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    }
    /*
    else if (arr->child[0]->child[0]->nodeType == mathN) {

    }
    */
    // MULT INDEX TYPESPEC
    tempString.append("MULT");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempString.append(std::to_string(arr->determineOffset()));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    // ADD ADDR LASTMULT
    tempString.append("ADD");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempRHS();
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
}

void arrayHandleBottom(ASTnode * equal ) {
    arrayNode * arr = (arrayNode *) equal->child[0];
    // ADDR OF ID
    // ASSIGN INDEX
    // Array Index Cases
    //this one fine
    //
    if (arr->child[0]->child[0]->nodeType == constantN) {
    tempString.append("ADDR");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempString.append("A_"+std::to_string(arr->offset));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();

    tempString.append("ASSIGN");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
        constantNode * tmp = (constantNode *) arr->child[0]->child[0];
        tempString.append(std::to_string(tmp->intConst));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();

    // MULT INDEX TYPESPEC
    tempString.append("MULT");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempString.append(std::to_string(arr->determineOffset()));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    // ADD ADDR LASTMULT
    tempString.append("ADD");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempRHS();
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();

    }
    //FIXME done i think
    else if (arr->child[0]->child[0]->nodeType == idN) {
    tempString.append("ADDR");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempString.append("A_"+std::to_string(arr->offset));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
        tempString.append("LOAD");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        idNode * tmp = (idNode *) arr->child[0]->child[0];
        idHandle(tmp);
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();

    // MULT INDEX TYPESPEC
    tempString.append("MULT");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempString.append(std::to_string(arr->determineOffset()));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    // ADD ADDR LASTMULT
    tempString.append("ADD");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempRHS();
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();

    }
    //FIXME done i belive
    else if (arr->child[0]->child[0]->nodeType == mathN) {

    // MULT INDEX TYPESPEC
    tempString.append("MULT");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempString.append(std::to_string(arr->determineOffset()));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();

        tempString.append("ADDR");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempReg = "A_"+std::to_string(arr->offset);
        tempString.append(tempReg);
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    // ADD ADDR LASTMULT
    tempString.append("ADD");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempRHS();
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    }

}


void handleRHSArray(ASTnode * equal)
{
    std::cout << "HELLO" << std::endl;
    // ASSIGN VALUE O(LASTSUM)
    // RHS OF EQ IS CONSTANT VALUE
    if (equal->child[1]->nodeType == constantN) {
        constantNode * val = (constantNode *) equal->child[1];
        tempString.append("ASSIGN");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        constantHandle(val);
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
        tempString.append("STORE");
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHSArr();
    }
    // RHS IS ID NODE
    if (equal->child[1]->nodeType == idN) {
        offHandle(equal->child[1]);
        tempString.append("STORE");
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHSArr();
    }
    // RHS IS ARRAY NODE
    else if (equal->child[1]->nodeType == arrayN) {
        arrayNode * arr = (arrayNode *) equal->child[1];
        // ADDR OF ID
        //offHandleA(equal->child[1]);

        // ASSIGN INDEX
        // Array Index Cases
        // aka the stuff inside the brackets
        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);


            /*
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();
            tempInc();
            */

            tempString.append("STORE");
            tempString.append("\t");
            tempRHS();
            tempString.append("\t");
            if (equal->child[0]->nodeType == idN)
            {
                idNode * id = (idNode *) equal->child[0];
               tempString.append("A_"+std::to_string(id->offset));
            }
            else
                tempRHSArr();
        }
        else
        {
            if (arr->child[0]->child[0]->nodeType == constantN) {
            tempString.append("ADDR");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempString.append("A_"+std::to_string(arr->offset));
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();
            tempString.append("ASSIGN");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
                constantNode * tmp = (constantNode *) arr->child[0]->child[0];
                tempString.append(std::to_string(tmp->intConst));
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();

            tempString.append("MULT");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHS();
            tempString.append("\t");
            tempString.append(std::to_string(arr->determineOffset()));
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();
            // ADD ADDR LASTMULT
            tempString.append("ADD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHS();
            tempString.append("\t");
            tempRHS();
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();
            }
            // Possibly the source of the error
            else if (arr->child[0]->child[0]->nodeType == idN) {
            tempString.append("ADDR");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempString.append("A_"+std::to_string(arr->offset));
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
                idNode * tmp = (idNode *) arr->child[0]->child[0];
                idHandle(tmp);
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();


            tempString.append("MULT");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHS();
            tempString.append("\t");
            tempString.append(std::to_string(arr->determineOffset()));
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();
            // ADD ADDR LASTMULT
            tempString.append("ADD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHS();
            tempString.append("\t");
            tempRHS();
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();

            }
            //FIXEME possible broken array on rhs of equal
            else if (arr->child[0]->child[0]->nodeType == mathN) {

            tempUsage1 = tempStack.front();
//            tempStack.pop_front();

            tempString.append("MULT");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHS();
            tempString.append("\t");
            tempString.append(std::to_string(arr->determineOffset()));
            triACStruct.push_back(tempString);
            tempString = "";
            tempStack.push_front(tempUsage1);
            tempInc();

            tempString.append("ADDR");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempString.append("A_"+std::to_string(arr->offset));
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();
            // ADD ADDR LASTMULT
            tempString.append("ADD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHS();
            tempString.append("\t");
            tempRHS();
            triACStruct.push_back(tempString);
            tempString = "";
            tempInc();
            }
            if (equal->child[0]->nodeType == arrayN && equal->child[1]->nodeType == arrayN)
            {
                tempUsage1 = tempStack.front();
                tempStack.pop_front();
                tempString.append("LOAD");
                tempString.append("\t");
                tempDST();
                tempString.append("\t");
                tempRHSArr();
                triACStruct.push_back(tempString);
                tempString = "";
                tempInc();


                tempString.append("STORE");
                tempString.append("\t");
                tempRHS();
                tempStack.push_front(tempUsage1);
                tempString.append("\t");
                tempRHSArr();
            }
            else if (equal->child[0]->nodeType == idN)//LHS is ID
            {
                idNode * id = (idNode *) equal->child[0]; 
                tempString.append("LOAD");
                tempString.append("\t");
                tempDST();
                tempString.append("\t");
                tempRHSArr();
                triACStruct.push_back(tempString);
                tempString = "";
                tempInc();


                tempString.append("STORE");
                tempString.append("\t");
                tempRHS();
                tempString.append("\t");
                tempString.append("A_"+std::to_string(id->offset));
                //triACStruct.push_back(tempString);
                //tempString = "";
            }
        }
    }
}

// FUNCTION CALLS
void functionCallHandle(ASTnode * AST) {
    funcCallNode * func = (funcCallNode *) AST;

    for (int i = 0; i < func->child.size(); i++)
    {
        // Cases for the args
        // Is Constant
        if (func->child[i]->nodeType == constantN)
        {
            constantNode * temp = (constantNode *) func->child[i];
            constantHandleElec(temp);
        }

        // Is ID
        else if (func->child[i]->nodeType == idN)
        {
            idNode * temp = (idNode *) func->child[i];
            offHandle(temp);
        }

        else if (func->child[i]->nodeType == arrayN)
        {
            arrayNode * temp = (arrayNode *) func->child[i];
            if (temp->boundVect.size() == 2)
                array2DHandleBottom(temp);
            else
            {
                arrayGetHandle(temp);
            }
        }
        tempString.append("ARGLOAD");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    }
    tempString.append("CALL");
    tempString.append("\t");
    tempString.append(func->name);
    triACStruct.push_back(tempString);
    tempString = "";
}

void returnHandle(ASTnode * AST)
{
    returnNode * ret = (returnNode*) AST;
    // RETLOAD
    if (ret->child[0]->nodeType == constantN)
    {
        constantNode * temp = (constantNode *) ret->child[0];
        constantHandleElec(temp);
    }

    // Is ID
    else if (ret->child[0]->nodeType == idN)
    {
        idNode * temp = (idNode *) ret->child[0];
        offHandle(temp);
    }

    else if (ret->child[0]->nodeType == arrayN)
    {
        arrayNode * temp = (arrayNode *) ret->child[0];
        if (temp->boundVect.size() == 2)
            array2DHandleBottom(temp);
        else
        {
            arrayGetHandle(temp);
        }
    }

    tempString.append("RETLOAD");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    triACStruct.push_back(tempString);
    tempString = "";

    // RET
    tempString.append("RET");
    triACStruct.push_back(tempString);
    tempString = "";

}

void functionHandle(ASTnode * AST) {
    //might kill this moved entire thing into labelHandle
    functionNode * func = (functionNode *) AST;
    tempString.append("\t");
    tempString.append(std::to_string(func->activationFrameSize));
}

// ASSIGN DST SRC
void equalHandle(ASTnode * AST) {
    if (AST->child.size() > 0){
        // IDNODE LHS
        if (AST->child[0]->production.compare("IDENTIFIER") == 0){
            if (AST->child[1]->nodeType == constantN) {
                idNode * id = (idNode *) AST->child[0];
                constantNode * cons = (constantNode *) (AST->child[1]);

                tempString.append("ASSIGN");
                tempString.append("\t");
                tempDST();
                tempString.append("\t");
                constantHandle(cons);
                triACStruct.push_back(tempString);
                tempString = "";
                tempInc();

                tempString.append("STORE");
                tempString.append("\t");
                tempRHS();
                tempString.append("\t");
                idHandle(id);
            }
            if (AST->child[1]->nodeType == idN) {
                idNode * id = (idNode *) AST->child[0];
                idNode * id1 = (idNode *) AST->child[1];
                offHandle(id1);

                /*
                tempString.append("LOAD");
                tempString.append("\t");
                tempDST();
                tempString.append("\t");
                tempRHS();
                tempString = "";
                tempInc();
                */

                tempString.append("STORE");
                tempString.append("\t");
                tempRHS();
                tempString.append("\t");
                idHandle(id);
            }
            else if (AST->child[1]->nodeType == mathN){
                idNode * id = (idNode *) AST->child[0];
                tempString.append("STORE");
                tempString.append("\t");
                tempRHS();
                tempString.append("\t");
                idHandle(id);
            }
        }
        // INITIALIZER LIST
		else if (AST->child[1]->production.compare("INITIALIZER_LIST") == 0)
		{
			arrayNode * arr = (arrayNode *) AST->child[0];
			if(arr->boundVect.size() == 1)
			{
				ASTnode * temp = AST->child[1];
				for(int i = 0; i < arr->boundVect[0]; i++)
				{
					//Getting the base address of the array
					tempString = "";
					tempString.append("ADDR");
					tempString.append("\t");
					tempDST();
					tempString.append("\t");
					tempString.append("A_"+std::to_string(arr->offset));
					triACStruct.push_back(tempString);
					tempString = "";
					tempInc();

					//Putting the value from initializer list into a temp
					tempString = "";
					tempString.append("ASSIGN");
					tempString.append("\t");
					tempDST();
					tempString.append("\t");
					tempString.append(std::to_string(i));
					triACStruct.push_back(tempString);
					tempString = "";
					tempInc();

					// Getting the offset for putting in the values
					tempString = "";
					tempString.append("MUL");
					tempString.append("\t");
					tempDST();
					tempString.append("\t");
					tempRHS();
					tempString.append("\t");
					tempString.append(std::to_string(arr->determineOffset()));
					triACStruct.push_back(tempString);
					tempString = "";
					tempInc();

					//Add the base address
					tempString = "";
					tempString.append("ADD");
					tempString.append("\t");
					tempDST();
					tempString.append("\t");
					tempRHS();
					tempString.append("\t");
					tempRHS();
					triACStruct.push_back(tempString);
					tempString = "";
					tempInc();

					//Putting the value from initializer list into a temp
					tempString = "";
					tempString.append("ASSIGN");
					tempString.append("\t");
					tempDST();
					tempString.append("\t");
					//Getting the value from the initalizer list
					constantNode * cons = (constantNode *) AST->child[1]->child[i];
					constantHandle(cons);
					triACStruct.push_back(tempString);
					tempString = "";

					//Putting the value into the array
					tempString = "";
					tempString.append("STORE");
					tempString.append("\t");
					tempDST();
					tempString.append("\t");
					tempString.append("0(");
					tempRHS();
					tempString.append(")");
					triACStruct.push_back(tempString);
					tempString = "";
					tempInc();
				}
			}
			else if(arr->boundVect.size() == 2)
			{
				int k = 0;
				for(int i = 0; i < arr->boundVect[0]; i++)
				{
					for(int j = 0; j < arr->boundVect[1]; j++)
					{
						//Get Base Address for Array
						tempString.append("ADDR");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						tempString.append("A_"+std::to_string(arr->offset));
						triACStruct.push_back(tempString);
						tempString = "";
						tempInc();

						//Assign first bound
						tempString.append("ASSIGN");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						tempString.append(std::to_string(i));
						triACStruct.push_back(tempString);
						tempString = "";
						tempInc();

						//Assign Second Bound
						tempString.append("ASSIGN");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						tempString.append(std::to_string(j));
						triACStruct.push_back(tempString);
						tempString = "";
						tempInc();

						//Calculate the offset
						tempString.append("ADD");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						tempRHS();
						tempString.append("\t");
						tempRHS();
						triACStruct.push_back(tempString);
						tempString = "";
						tempInc();

						//Assign max column size
						tempString.append("ASSIGN");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						tempString.append(std::to_string(arr->boundVect[1]));
						triACStruct.push_back(tempString);
						tempString = "";
						tempInc();

						// Getting the offset for putting in the values
						tempString.append("MUL");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						tempRHS();
						tempString.append("\t");
						tempRHS();
						triACStruct.push_back(tempString);
						tempString = "";
						tempInc();

						// Getting the offset for putting in the values
						tempString.append("MUL");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						tempRHS();
						tempString.append("\t");
						tempString.append(std::to_string(arr->determineOffset()));
						triACStruct.push_back(tempString);
						tempString = "";
						tempInc();

						// Add the offset to the base address
						tempString.append("ADD");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						tempRHS();
						tempString.append("\t");
						tempRHS();
						triACStruct.push_back(tempString);
						tempString = "";
						tempInc();

						//Putting the value from initializer list into a temp
						tempString.append("ASSIGN");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						//Getting the value from the initalizer list
						constantNode * cons = (constantNode *) AST->child[1]->child[k];
						k++;
						constantHandle(cons);
						triACStruct.push_back(tempString);
						tempString = "";

						//Putting the value into the array
						tempString.append("STORE");
						tempString.append("\t");
						tempDST();
						tempString.append("\t");
						tempString.append("0(");
						tempRHS();
						tempString.append(")");
						triACStruct.push_back(tempString);
						tempString = "";
						tempInc();
					}
				}
			}
			else
			{
				std::cout << "Compiler does not support arrays larger than 2-D" << std::endl;
                exit(1);
			}

		}

        // ARRAY ASIGNMENT
        else if (AST->child[0]->production.compare("ARRAY_NODE") == 0) {
            arrayNode * arr = (arrayNode *) AST->child[0];
            // LHS 1D ARRAY
            if (arr->boundVect.size() == 1)
            {
                std::cout << "HELLLLLL" << std::endl;
                arrayHandleBottom(AST);
            }
            // LHS 2D ARRAY
            else if (arr->boundVect.size() == 2)
            {
                arrayNode * arr = (arrayNode *) AST->child[0];
                array2DHandleBottom(arr);
            }
            else
            {
                std::cout << "Compiler does not support arrays larger than 2-D" << std::endl;
                exit(1);
            }
            // Necessary when ID on LHS
            if (arr->child[0]->child[0]->nodeType == idN)
                std::cout << "HELLLLLL" << std::endl;
                handleRHSArray(AST);
        }
        else if (AST->child[1]->nodeType == mathN) {
            idNode * id = (idNode *) AST->child[0];
            tempString = "";
            tempString.append("STORE");
            tempString.append("\t");
            tempRHS();
            tempString.append("\t");
            tempRHSArr();
        }
        if (AST->child[1]->nodeType == arrayN)
        {
            arrayNode * arr = (arrayNode *) AST;
            handleRHSArray(arr);

        }
    }
    triACStruct.push_back(tempString);
    tempString = "";
}

void array2DHandleBottom(arrayNode * arr)
{
    // ADDR OF ID
    tempString.append("ADDR");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    //tempString.append(arr->id);
    tempString.append("A_"+std::to_string(arr->offset));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    // ASSIGN FIRST INDEX
        // Array Index Cases
    if (arr->child[0]->child[0]->nodeType == constantN) {


        tempString.append("ASSIGN");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        constantNode * tmp = (constantNode *) arr->child[0]->child[0];
        tempString.append(std::to_string(tmp->intConst));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();

    }
    // IDNODE IN THE FIRST INDEX
    //FIXME 1st child should be 0 i think could be wrong
    else if (arr->child[0]->child[0]->nodeType == idN) {
        offHandle(arr->child[1]->child[0]);
    }
    // MATHNODE IN THE FIRST INDEX
    // MULT IS HANDLED A LITTLE DIFFERENTLY WHEN MATHNODE
    if (arr->child[0]->child[0]->nodeType == mathN) {
        // MULT INDEX TYPESPEC
        tempUsage1 = tempStack.front();
        tempStack.pop_front();
        tempString.append("MULT");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append(std::to_string(arr->boundVect[0]));
        triACStruct.push_back(tempString);
        tempString = "";
        tempStack.push_front(tempUsage1);
        tempInc();

    }
    else {
        // MULT INDEX TYPESPEC
        tempString.append("MULT");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append(std::to_string(arr->boundVect[0]));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    }
    // MULT BY FIRST MAX BOUND
    tempString.append("MULT");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempString.append(std::to_string(arr->determineOffset()));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    // ADD ADDR LASTMULT
    tempString.append("ADD");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempRHS();
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    //tempStack.push_front(tempUsage1);
    //SECOND INDEX CASES
    // CONSTANT IN 2ND INDEX OF LHS
    if (arr->child[1]->child[0]->nodeType == constantN) {
        // ASSIGN SECOND INDEX
        tempString.append("ASSIGN");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        constantNode * tmp = (constantNode *) arr->child[1]->child[0];
        tempString.append(std::to_string(tmp->intConst));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();

        // MULT INDEX TYPESPEC
        tempString.append("MULT");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append(std::to_string(arr->determineOffset()));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();

        // ADD ADDR LASTMULT
        tempString.append("ADD");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    }
    // IDNODE IN 2ND INDEX OF LHS
    else if (arr->child[1]->child[0]->nodeType == idN) {
        offHandle(arr->child[1]->child[0]);
        // MULT INDEX TYPESPEC
        tempString.append("MULT");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append(std::to_string(arr->determineOffset()));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();

        tempUsage1 = tempStack.front();
        // ADD ADDR LASTMULT
        tempString.append("ADD");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    }
    // MATHNODE IN 2ND INDEX OF LHS
    else if (arr->child[1]->child[0]->nodeType == mathN) {
        // MULT INDEX TYPESPEC
        tempUsage1 = tempStack.front();
        tempStack.pop_front();
        tempString.append("MULT");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append(std::to_string(arr->determineOffset()));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();

        tempStack.push_front(tempUsage1);
        // ADD ADDR LASTMULT
        tempString.append("ADD");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    }
    tempString.append("LOAD");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHSArr();
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
}

void arrayGetHandle(arrayNode * arr) {
    // ADDR OF ID
    tempString = "";
    tempString.append("ADDR");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempString.append("A_"+std::to_string(arr->offset));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    // ASSIGN INDEX
    // Array Index Cases
    //FIXME
    if (arr->child[0]->child[0]->nodeType == mathN) {
        mathNode * math = (mathNode *) arr->child[0]->child[0];
        mathHandle(math);
    }
    else if (arr->child[0]->child[0]->nodeType == constantN) {
        tempString.append("ASSIGN");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        constantNode * tmp = (constantNode *) arr->child[0]->child[0];
        tempString.append(std::to_string(tmp->intConst));
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    }
    //FIXME
    else if (arr->child[0]->child[0]->nodeType == idN) {
        idNode * tmp = (idNode *) arr->child[0]->child[0];
        idInsideArrBrrk(tmp);
        triACStruct.push_back(tempString);
        tempString = "";
        tempInc();
    }
    // MULT INDEX TYPESPEC
    tempString.append("MULT");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempString.append(std::to_string(arr->determineOffset()));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    // ADD ADDR LASTMULT
    tempString.append("ADD");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHS();
    tempString.append("\t");
    tempRHS();
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();

    tempString.append("LOAD");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");
    tempRHSArr();
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
}

void mathHandle(mathNode * math) {
    enum operationE {addOp, subOp, mulOp, divOp, incOp, decOp, modOp, shlOp, shrOp, xorOp};
    if (math->child[0]->nodeType == constantN && math->child[1]->nodeType == mathN)
    {
        constantNode * cons = (constantNode *) (math->child[0]);
        constantHandleElec(cons);

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        tempInc();
    }
    if (math->child[0]->nodeType == mathN && math->child[1]->nodeType == constantN)
    {
        constantNode * cons = (constantNode *) (math->child[1]);
        constantHandleElec(cons);
        tempUsage = tempStack.front();
        tempStack.pop_front();
        tempUsage1 = tempStack.front();
        tempStack.pop_front();

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(tempUsage1));
        tempString.append("\t");
        tempString.append("iT_"+std::to_string(tempUsage));

        tempInc();
    }
    else if (math->child[0]->nodeType == mathN && math->child[1]->nodeType == mathN)
    {
        tempUsage = tempStack.front();
        tempStack.pop_front();
        tempUsage1 = tempStack.front();
        tempStack.pop_front();

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(tempUsage1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(tempUsage);
        tempString.append(tempReg);
        tempInc();
    }
    else if (math->child[0]->nodeType == idN && math->child[1]->nodeType == mathN)
    {
        offHandle(math->child[0]);
        tempUsage = tempStack.front();
        tempStack.pop_front();
        tempUsage1 = tempStack.front();
        tempStack.pop_front();

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(tempUsage1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(tempUsage);
        tempString.append(tempReg);

        tempInc();
    }
    else if (math->child[0]->nodeType == mathN && math->child[1]->nodeType == idN)
    {
        offHandle(math->child[1]);

        tempUsage = tempStack.front();
        tempStack.pop_front();
        tempUsage1 = tempStack.front();
        tempStack.pop_front();

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(tempUsage1);
        tempString.append(tempReg);
        tempString.append("\t");
        tempReg = "iT_"+std::to_string(tempUsage);
        tempString.append(tempReg);

        tempInc();
    }
    else if (math->child[0]->nodeType == constantN && math->child[1]->nodeType == constantN)
    {
        constantNode * cons1 = (constantNode *) (math->child[0]);
        constantNode * cons2 = (constantNode *) (math->child[1]);

        constantHandleElec(cons2);
        constantHandleElec(cons1);

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();

        tempInc();
    }
    else if (math->child[0]->nodeType == idN && math->child[1]->nodeType == idN)
    {
        idNode * id1 = (idNode *) (math->child[0]);
        offHandle(math->child[1]);
        offHandle(math->child[0]);

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();

        tempInc();
    }
    else if (math->child[0]->nodeType == constantN && math->child[1]->nodeType == idN)
    {
        constantNode * cons1 = (constantNode *) (math->child[0]);
        offHandle(math->child[1]);
        constantHandleElec(cons1);

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();

        tempInc();
    }
    else if (math->child[0]->nodeType == idN && math->child[1]->nodeType == constantN)
    {
        constantNode * cons1 = (constantNode *) (math->child[1]);
        constantHandleElec(cons1);
        offHandle(math->child[0]);

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();

        tempInc();
    } else if (math->child[0]->nodeType == mathN && math->child[1]->nodeType == constantN)
    {
        constantNode * cons1 = (constantNode *) (math->child[1]);
        constantHandle(cons1);
        tempUsage1 = tempStack.front();
        tempStack.pop_front();

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempStack.push_front(tempUsage1);
        tempString.append("\t");
        tempRHS();

        tempInc();

    }
    else if (math->child[0]->nodeType == arrayN &&
               math->child[1]->nodeType == constantN)
    {
        arrayNode * arr = (arrayNode *) math->child[0];
        constantNode * cons1 = (constantNode *) (math->child[1]);

        // Case that works for 2D Arith
        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        constantHandle(cons1);
        tempInc();
    } else if (math->child[0]->nodeType == arrayN &&
               math->child[1]->nodeType == idN)
    {
        arrayNode * arr = (arrayNode *) math->child[0];
        offHandle(math->child[1]);

        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }
        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        tempInc();
        // CONSTANT - ARRAY
    } else if (math->child[0]->nodeType == constantN &&
               math->child[1]->nodeType == arrayN)
    {
        arrayNode * arr = (arrayNode *) math->child[1];
        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }
        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        constantNode * cons1 = (constantNode *) (math->child[0]);
        constantHandle(cons1);
        tempInc();
    }
    else if (math->child[0]->nodeType == idN &&
               math->child[1]->nodeType == arrayN)
    {
        arrayNode * arr = (arrayNode *) math->child[1];
        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }
        offHandle(math->child[0]);
        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        tempInc();
    }
    else if (math->child[0]->nodeType == arrayN &&
               math->child[1]->nodeType == arrayN)
    {
        arrayNode * arr = (arrayNode *) math->child[0];
        arrayNode * arr1 = (arrayNode *) math->child[1];
        if (arr1->boundVect.size() == 2)
        {
            array2DHandleBottom(arr1);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr1);
        }

        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }

        tempString.append(math->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        tempInc();
    }
    else if (math->operation == incOp) {
        //inc by 1
        idNode * id = (idNode *) (math->child[0]);
        offHandle(math->child[0]);

        tempString.append("ADD");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append("1");

        tempInc();

        triACStruct.push_back(tempString);
        tempString = "";

        //storing res
        tempString.append("STORE");
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        idHandle(id);
    }
    else if (math->operation == decOp) {
        idNode * id = (idNode *) (math->child[0]);
        offHandle(math->child[0]);

        tempString.append("SUB");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append("1");

        tempInc();

        triACStruct.push_back(tempString);
        tempString = "";

        //storing res
        tempString.append("STORE");
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        idHandle(id);
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
        tempString.append("FI_"+std::to_string(ifnode->counter));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    }
    else if (ifnode->child[0]->nodeType == idN) {
        idNode * id = (idNode *) (ifnode->child[0]);
        tempString.append("LOAD");
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        idHandle(id);

    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();

        tempString.append("BREQ");
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("FI_"+std::to_string(ifnode->counter));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    }
    else { //it's an expr node
        exprNode * expr = (exprNode *) ifnode->child[0];
        exprHandle(expr);
        ASTnode * logicOp = ifnode->child[0];
        tempString.append("BREQ");
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("FI_"+std::to_string(ifnode->counter));
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
    }
};

void ifHandleBot(ifNode * ifnode) {
    //uncomment for nested if fix
    //tho breaks concurent ifs
    //tempString.append("IF_"+std::to_string(ifCount-1)+":");
    tempString.append("FI_"+std::to_string(ifnode->counter)+":");
    triACStruct.push_back(tempString);
    tempString = "";
};
void idHandle(idNode * id) {
    tempString.append("A_"+std::to_string(id->offset));
}
void offHandle(ASTnode * AST){
    idNode * id = (idNode *) AST;
    tempString.append("LOAD");
    tempString.append("\t");
    tempString.append("iT_"+std::to_string(intTempCount));
    tempString.append("\t");
    idHandle(id);
    tempInc();
    triACStruct.push_back(tempString);
    tempString = "";
}
void offHandleA(ASTnode * AST){
    arrayNode * arr = (arrayNode *) AST;
    tempString.append("LOAD");
    tempString.append("\t");
    tempString.append("iT_"+std::to_string(intTempCount));
    tempString.append("\t");
    tempString.append("A_"+std::to_string(arr->offset));
    tempInc();
    triACStruct.push_back(tempString);
    tempString = "";
}
//{{{

void exprHandle(exprNode * expr){
    //LOGIC_OP DST SRC1 SRC2
    //ie LT DST SRC1 SRC2   store res of SRC1 < SRC2 inside DST
    //1 if SRC 1 < SRC2 else 0
    // ID - CONSTANT
    if (expr->child[0]->nodeType == idN && expr->child[1]->nodeType == constantN) {
        idNode * id = (idNode *) expr->child[0];
        constantNode * cons = (constantNode *) expr->child[1];
        constantHandleElec(cons);
        offHandle(expr->child[0]);

        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        triACStruct.push_back(tempString);
        tempString="";
        tempInc();
    }
    // CONSTANT - ID
    else if (expr->child[0]->nodeType == constantN && expr->child[1]->nodeType == idN){
        constantNode * cons = (constantNode *) expr->child[0];
        offHandle(expr->child[1]);
        constantHandleElec(cons);

        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        triACStruct.push_back(tempString);
        tempString="";
        tempInc();
    }
    // CONSTANT - EXPR
    else if (expr->child[0]->nodeType == constantN && expr->child[1]->nodeType == exprN){
        constantNode * cons = (constantNode *) expr->child[0];
        exprNode * expr1 = (exprNode *) expr->child[1];

        exprHandle(expr1);
        constantHandleElec(cons);
        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
    triACStruct.push_back(tempString);
    tempString="";
        tempInc();
    }
    // EXPR - CONSTANT
    else if (expr->child[0]->nodeType == exprN && expr->child[1]->nodeType == constantN){
        exprNode * expr1 = (exprNode *) expr->child[0];
        constantNode * cons = (constantNode *) expr->child[1];

        constantHandle(cons);
        exprHandle(expr1);
        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        triACStruct.push_back(tempString);
        tempString="";
        tempInc();
    }
    // EXPR - EXPR
    else if (expr->child[0]->nodeType == exprN && expr->child[1]->nodeType == exprN){
        exprNode * expr2 = (exprNode *) expr->child[1];
        exprHandle(expr2);
        exprNode * expr1 = (exprNode *) expr->child[0];
        exprHandle(expr1);

        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
    triACStruct.push_back(tempString);
    tempString="";
        tempInc();
    }
    // ID - EXPR
    else if (expr->child[0]->nodeType == idN && expr->child[1]->nodeType == exprN){
        exprNode * expr1 = (exprNode *) expr->child[1];
        idNode * id = (idNode *) expr->child[0];

        exprHandle(expr1);
        offHandle(expr->child[0]);
        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
    triACStruct.push_back(tempString);
    tempString="";
        tempInc();
    }
    // EXPR - ID
    else if (expr->child[0]->nodeType == exprN && expr->child[1]->nodeType == idN){
        exprNode * expr1 = (exprNode *) expr->child[0];
        idNode * id = (idNode *) expr->child[1];
        offHandle(expr->child[1]);
        exprHandle(expr1);

        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
    triACStruct.push_back(tempString);
    tempString="";
        tempInc();
    }
    else if (expr->child[0]->nodeType == constantN && expr->child[1]->nodeType == constantN)
    {
        constantNode * cons = (constantNode *) expr->child[0];
        constantNode * cons1 = (constantNode *) expr->child[1];
        constantHandle(cons1);
        constantHandle(cons);
        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
    triACStruct.push_back(tempString);
    tempString="";
        tempInc();
    }
    // ID - ID
    else if (expr->child[0]->nodeType == idN && expr->child[1]->nodeType == idN) {
        idNode * id = (idNode *) expr->child[0];
        id = (idNode *) expr->child[1];
        offHandle(expr->child[1]);
        offHandle(expr->child[0]);

        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        triACStruct.push_back(tempString);
        tempString="";
        tempInc();
    }

    // ID - ARRAY X
    else if (expr->child[0]->nodeType == idN && expr->child[1]->nodeType == arrayN) {
        arrayNode * arr = (arrayNode *) expr->child[1];
        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }
        offHandle(expr->child[0]);
        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        tempInc();
        triACStruct.push_back(tempString);
        tempString = "";

    }

    // CONSTANT - ARRAY X
    else if (expr->child[0]->nodeType == constantN && expr->child[1]->nodeType == arrayN) {
        arrayNode * arr = (arrayNode *) expr->child[1];
        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }
        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        constantNode * cons1 = (constantNode *) (expr->child[0]);
        constantHandle(cons1);
        tempString.append("\t");
        tempRHS();
        tempInc();
        triACStruct.push_back(tempString);
        tempString = "";

    }

    // ARRAY - ID X
    else if (expr->child[0]->nodeType == arrayN && expr->child[1]->nodeType == idN) {
        arrayNode * arr = (arrayNode *) expr->child[0];
        offHandle(expr->child[1]);

        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }
        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        tempInc();
        triACStruct.push_back(tempString);
        tempString = "";

    }

    // ARRAY - CONSTANT X
    else if (expr->child[0]->nodeType == arrayN && expr->child[1]->nodeType == constantN) {
        arrayNode * arr = (arrayNode *) expr->child[0];
        constantNode * cons1 = (constantNode *) (expr->child[1]);

        // Case that works for 2D Arith
        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }

        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        constantHandle(cons1);
        tempInc();
        triACStruct.push_back(tempString);
        tempString = "";

    }
    // ARRAY - ARRAY X
    else if (expr->child[0]->nodeType == arrayN && expr->child[1]->nodeType == arrayN) {
        arrayNode * arr = (arrayNode *) expr->child[0];
        arrayNode * arr1 = (arrayNode *) expr->child[1];
        if (arr1->boundVect.size() == 2)
        {
            array2DHandleBottom(arr1);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr1);
        }

        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }

        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        tempInc();
        triACStruct.push_back(tempString);
        tempString = "";
    }

    // ARRAY - EXPR
    else if (expr->child[0]->nodeType == arrayN && expr->child[1]->nodeType == exprN){
        arrayNode * arr = (arrayNode *) expr->child[0];
        exprNode * expr1 = (exprNode *) expr->child[1];
        //arrayhandle
        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }
        exprHandle(expr1);

        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
        triACStruct.push_back(tempString);
        tempString="";
        tempInc();
    }

    // EXPR - ARRAY
    else if (expr->child[0]->nodeType == exprN && expr->child[1]->nodeType == arrayN){
        exprNode * expr1 = (exprNode *) expr->child[0];
        arrayNode * arr = (arrayNode *) expr->child[1];
        //arrayhandle
        if (arr->boundVect.size() == 2)
        {
            array2DHandleBottom(arr);
            tempString.append("LOAD");
            tempString.append("\t");
            tempDST();
            tempString.append("\t");
            tempRHSArr();
            tempInc();
            triACStruct.push_back(tempString);
            tempString = "";

        }

        else
        {
            arrayGetHandle(arr);
        }
        exprHandle(expr1);

        tempString.append(expr->production);
        tempString.append("\t");
        tempDST();
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempRHS();
    triACStruct.push_back(tempString);
    tempString="";
        tempInc();
    }
}
//}}}
void constantHandleElec(constantNode * cons){

    tempString = "";
    tempString.append("ASSIGN");
    tempString.append("\t");
    tempDST();
    tempString.append("\t");

    if (cons->typeSpec == intS) {
        tempString.append(std::to_string(cons->intConst));
    }
    else if (cons->typeSpec == floatS || cons->typeSpec == doubleS) {
        //show that the tempReg is a float
        tempString.append(std::to_string(cons->doubleConst));
    }
    else if (cons->typeSpec == charS) {
        tempString.append(std::to_string((int)cons->charConst));
    }
    triACStruct.push_back(tempString);
    tempString = "";
    tempInc();
}

void constantHandle(constantNode * cons) {
    //FIXME add cons or fcons infront of it
    //to desinate between int const and float const
    //prbly won't use this lol
    if (cons->typeSpec == intS) {
        tempString.append(std::to_string(cons->intConst));
    }
    else if (cons->typeSpec == floatS || cons->typeSpec == doubleS) {
        //show that the tempReg is a float
        tempString.append(std::to_string(cons->doubleConst));
    }
    else if (cons->typeSpec == charS) {
        tempString.append(std::to_string((int)cons->charConst));
    }
    else if (cons->production.compare("STRING_LITERAL") == 0) {
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
    tempString.append("BEGWHILE_"+std::to_string(whilenode->counter)+":");
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
        tempString.append("ENDWHILE_"+std::to_string(whilenode->counter));
    }
    else {
        exprNode * expr = (exprNode *) whilenode->child[0];
        exprHandle(expr);
        ASTnode * logicOp = whilenode->child[0];
        tempString.append("BREQ");
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("ENDWHILE_"+std::to_string(whilenode->counter));
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
    tempString.append("BEGWHILE_"+std::to_string(whilenode->counter));
    triACStruct.push_back(tempString);
    tempString = "";
    tempString.append("ENDWHILE_"+std::to_string(whilenode->counter)+":");
    triACStruct.push_back(tempString);
    tempString = "";
    //whileCount++;
};


void forHandleTop(forNode * fornode) {
    if (fornode->exprs[0]!= NULL){
        equalHandle(fornode->exprs[0]->child[0]);
    }
    tempString.append("BEGFOR_"+std::to_string(fornode->counter)+":");
    triACStruct.push_back(tempString);
    tempString = "";
    //BRANCHES in MIPS the label comes last
    //BREQ SRC1 SRC2 LABEL
    if (fornode->exprs[1]!=NULL) {
        exprNode * expr = (exprNode *) fornode->exprs[1];
        exprHandle(expr);
        tempString.append("BREQ");
        tempString.append("\t");
        tempRHS();
        tempString.append("\t");
        tempString.append("0");
        tempString.append("\t");
        tempString.append("ENDFOR_"+std::to_string(fornode->counter));
        triACStruct.push_back(tempString);
        tempString = "";
    }
    //uncomment for nested for fix
    //tho breaks concurent fors
    //forCount++;
};

void forHandleBot(forNode * fornode) {
    //uncomment for nested for fix
    //tho breaks concurent fors
    //tempString.append("IF_"+std::to_string(forCount-1)+":");
    if (fornode->exprs[2]!=NULL) {
        mathNode * math = (mathNode *) fornode -> exprs[2];
        mathHandle(math);
    }
    tempString.append("BR");
    tempString.append("\t");
    tempString.append("BEGFOR_"+std::to_string(fornode->counter));
    triACStruct.push_back(tempString);
    tempString = "";
    tempString.append("ENDFOR_"+std::to_string(fornode->counter)+":");
    triACStruct.push_back(tempString);
    tempString = "";
    //forCount++;
};
//change this from printing to adding src code lines to triACStruct
void printSrc () {
    std::ifstream srcFileP(srcFile);
    std::string buffer="";
    std::string out="##\t";
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
