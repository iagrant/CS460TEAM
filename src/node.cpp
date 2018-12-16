//
// Name:    node.cpp
// Author:  Ian Grant
// Purpose: The symbol table is implemented as a stack of Binary Search Trees.
//
//          When the scanning begins a BST will be pushed onto the stack for the
//          main program.
//
//          Every time we enter a procedure a BST will be pushed onto the stack
//  		and all of the local variables will be stored there.
//
//          When a procedure is finished that level of the stack will be popped.
//

#define INT_SIZE_IN_BYTES 4
#define CHAR_SIZE_IN_BYTES 1
#define FLOAT_SIZE_IN_BYTES 4
#define DOUBLE_SIZE_IN_BYTES 8

#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>

enum signedEnum {signedE,unsignedE};
enum typeQualE {noneQ,constQ,volatileQ,bothQ};
enum storageSpecE {noneS,autoS,registerS,staticS,externS,typedefS};
enum typeSpecE {voidS,charS,shortS,intS,longS,floatS,doubleS,structS,stringS};
enum paramTypeE {signedPT,typeQualPT,typeSpecPT};
extern bool printSymbolNums;

class Node {
private:
    std::string name;
    std::string typeOut;
    int line;
    int signedB;
    int typeQual;
    int storageSpec;
    int typeSpec;
    int scope;
    int paramNum;
    int currentParam;
    std::list <int*> paramList;
    std::list <int*> :: iterator paramListIter;

public:
    int offset;
    bool isFunction;
    bool isArray;
    bool hasProto;
    bool hasImplementation;
    std::vector <int> boundVect;
    Node(){
        setName("");
        setLine(-1);
        setSigned(signedE);
        setTypeSpec(intS);
        setTypeQual(noneQ);
        setStorageSpec(noneS);
        setScope(-1);
        isFunction=false;
        isArray=false;
        hasProto=false;
        hasImplementation=false;
        paramNum=0;
        offset=-1;
    }

    void writeNode(std::string filename) {
        std::ofstream fileP(filename,std::ios::app);
        std::streambuf *coutbuf = std::cout.rdbuf();
        std::cout.rdbuf(fileP.rdbuf()); //changes cout to print to file stream
        printNode();
        std::cout << std::endl;
        std::cout.rdbuf(coutbuf); //resets cout to stdout
        fileP.close();
    }
    //following functions take in an int and compare it against
    //the type enums and print out the corosponding types
    void printSigned(int input){
        switch(input)
        {
            case signedE:
                break;
            case unsignedE:
                std::cout << "unsigned ";
                break;
        }
    }
    void printTypeQual(int input){
        switch(input)
        {
            case constQ:
                std::cout << "const ";
                break;
            case volatileQ:
                std::cout << "volatile ";
                break;
            case bothQ:
                std::cout << "const volatile";
                break;
        }
    }
    void printTypeSpec(int input) {
        switch(input)
        {
            case voidS:
                std::cout << "void ";
                break;
            case charS:
                std::cout << "char ";
                break;
            case shortS:
                std::cout << "short ";
                break;
            case intS:
                std::cout << "int ";
                break;
            case longS:
                std::cout << "long ";
                break;
            case floatS:
                std::cout << "float ";
                break;
            case doubleS:
                std::cout << "double ";
                break;
            case structS:
                std::cout << "struct ";
                break;
        }
    }
    void printStorageSpec(int input) {
        switch(input)
        {
            case autoS:
                std::cout << "auto ";
                break;
            case registerS:
                std::cout << "register ";
                break;
            case staticS:
                std::cout << "static ";
                break;
            case externS:
                std::cout << "extern ";
                break;
            case typedefS:
                std::cout << "typedef ";
                break;
        }
    }
    void printNode() {
        std::cout << "NAME: " << name << std::endl;
        std::cout << "SCOPE LEVEL: " << scope << std::endl;
        if (printSymbolNums)
            std::cout << "TYPE IN NUMS: " << signedB << typeQual << storageSpec << typeSpec << std::endl;
        std::cout << "TYPE: ";
        printType();
        std::cout << "LINE: " << line << std::endl;
        std::cout << "OFFSET: " << offset << std::endl;
        printFunction();
        std::cout << std::endl;
    }
    void printType(){
        printSigned(signedB);
        printTypeQual(typeQual);
        printStorageSpec(storageSpec);
        printTypeSpec(typeSpec);
        std::cout << std::endl;
    }
    void printFunction(){
        //prints out function types to file stream
        //std::cout << "IS AN ARRAY: " << std::boolalpha << isArray << std::endl;
        std::cout << "IS A FUNCTION: " << std::boolalpha << isFunction << std::endl;
        if (isFunction){
            std::cout << "HAS A PROTOTYPE: " << std::boolalpha << hasProto << std::endl;
            std::cout << "HAS A IMPLEMENTATION: " << std::boolalpha << hasImplementation << std::endl;
            std::cout << "Number of Function Parameters: " << paramNum << std::endl;
            if (paramNum > 0) {
                if (printSymbolNums) {
                    std::cout << "Function Parameters in Numbers: " << std::endl;;
                    paramListIter = paramList.begin();
                    currentParam = 1;
                    while (paramListIter != paramList.end()){
                        std::cout << "PARAM " << currentParam << " NUM TYPE: ";
                        int * ptr = *paramListIter;
                        int sign = *ptr;
                        ptr++;
                        int typeQ = *ptr;
                        ptr++;
                        int typeS = *ptr;
                        std::cout << sign << typeQ << typeS << std::endl;
                        paramListIter++;
                        currentParam++;
                    }
                }
                std::cout << "Function Parameters: " << std::endl;;
                paramListIter = paramList.begin();
                currentParam = 1;
                while (paramListIter != paramList.end()){
                    std::cout << "PARAM " << currentParam << " TYPE: ";
                    int * ptr = *paramListIter;
                    int sign = *ptr;
                    ptr++;
                    int typeQ = *ptr;
                    ptr++;
                    int typeS = *ptr;
                    printSigned(sign);
                    printTypeQual(typeQ);
                    printTypeSpec(typeS);
                    std::cout << std::endl;
                    paramListIter++;
                    currentParam++;
                }
            }
        }
    }
    void resetNode() {
        setName("");
        setLine(-1);
        setSigned(signedE);
        setTypeSpec(intS);
        setTypeQual(noneQ);
        setStorageSpec(noneS);
        setScope(-1);
        isFunction=false;
        //isArray=false;
        hasProto=false;
        hasImplementation=false;
        paramNum=0;
        offset=-1;
    }
    void setName(std::string nameIn) {name=nameIn;}
    std::string getName() {return name;}

    void setLine(int lineIn) {line=lineIn;}
    int getLine() {return line;}

    void setTypeSpec(int typeSpecIn) {typeSpec=typeSpecIn;}
    int getTypeSpec() {return typeSpec;}

    void setTypeQual(int typeQualIn) {typeQual=typeQualIn;}
    int getTypeQual() {return typeQual;}

    void setSigned(int signIn) {signedB=signIn;}
    int getSigned() {return signedB;}

    void setScope(int scopeIn) {scope=scopeIn;}
    int getScope() {return scope;}

    void setStorageSpec(int storageSpecIn) {storageSpec=storageSpecIn;}
    int getStorageSpec() {return storageSpec;}

    void setFunction() {isFunction=true;}
    bool getFunction() {return isFunction;}

    void setProto() {hasProto=true;}
    void setImplementation() {hasImplementation=true;}

    void addParam(){
        paramNum++;
        int * paramType;
        paramType = new int [3];
        //signed,type qualifier, and type specifier
        paramType[0]=signedE;  //defaults to signed variable
        paramType[1]=9;        //defaults to 9 which is nothing in the enum
        paramType[2]=intS;     //always default the type to int cuz C
        paramList.push_back(paramType);

    }
    //typeOfTypes designates weather you are inserting signed,type qualifier, or
    //type specifier
    void addParamValue(int typeOfTypes,int type){
            int * ptr = paramList.back();
            paramList.pop_back();
            ptr[typeOfTypes]=type;
            paramList.push_back(ptr);
    }
    int getOffset(){return offset;}
    //if not an array input arrayBounds as 1
    void setOffset(int * currentOffset, bool isArray,int arrayBounds,bool fstTime) {
        if (!isArray) {
            arrayBounds = 1; //just in case;
        }
        else {
            *currentOffset -= offset;
        }
        if (fstTime)
            offset = *currentOffset;
        std::cout << name << ": " << offset << std::endl;
        std::cout << "Current Offset: " << *currentOffset << std::endl;
        switch(typeSpec){
            case floatS:
                *currentOffset = 8*arrayBounds;
                break;
            case doubleS:
                *currentOffset = 8*arrayBounds;
                break;
            case charS:
                *currentOffset = 1*arrayBounds;
                break;
            default:
                *currentOffset = 4*arrayBounds;
                break;
        }
    }
};
