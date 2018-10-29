//
// Name:    node.cpp
// Author:  Semantic Team (Franklin, Grant, Knutson)
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

#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include <string>

enum signedEnum {signedE,unsignedE};
enum typeQualE {noneQ,constQ,volatileQ,bothQ};
enum storageSpecE {noneS,autoS,registerS,staticS,externS,typedefS};
enum typeSpecE {voidS,charS,shortS,intS,longS,floatS,doubleS,structS};
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
    bool isFunction;
    std::list <int*> paramList;
    std::list <int*> :: iterator paramListIter;

public:
    Node(){
        setName("");
        setLine(-1);
        setSigned(0);
        setTypeSpec(intS);
        setTypeQual(noneQ);
        setStorageSpec(noneS);
        setScope(-1);
        isFunction=false;
        paramNum=0;
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
        std::cout << "IS A FUNCTION: " << std::boolalpha << isFunction << std::endl;
        if (isFunction){
            std::cout << "Number of Function Paramiters: " << paramNum << std::endl;
            if (printSymbolNums) {
                std::cout << "Function Paramiters in Numbers: " << std::endl;;
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
            std::cout << "Function Paramiters: " << std::endl;;
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
    void resetNode() {
        setName("");
        setLine(-1);
        setSigned(0);
        setTypeSpec(intS);
        setTypeQual(9);
        setStorageSpec(9);
        setScope(-1);
        isFunction=false;
        paramNum=0;
    }
    std::string getName() {return name;}
    int getLine() {return line;}
    int getTypeSpec() {return typeSpec;}
    int getTypeQual() {return typeQual;}
    int getSigned() {return signedB;}
    int getStorageSec() {return storageSpec;}
    int getScope() {return scope;}

    void setName(std::string nameIn) {name=nameIn;}
    void setTypeSpec(int typeSpecIn) {typeSpec=typeSpecIn;}
    void setScope(int scopeIn) {scope=scopeIn;}
    void setTypeQual(int typeQualIn) {typeQual=typeQualIn;}
    void setLine(int lineIn) {line=lineIn;}
    void setSigned(int signIn) {signedB=signIn;}
    void setStorageSpec(int storageSpecIn) {storageSpec=storageSpecIn;}
    void setFunction() {isFunction=true;}
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
};
