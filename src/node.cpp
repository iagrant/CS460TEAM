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
enum typeQualE {constQ,volatileQ,bothQ};
enum storageSpecE {autoS,registerS,staticS,externS,typedefS};
enum typeSpecE {voidS,charS,shortS,intS,longS,floatS,doubleS,structS};
enum paramType {signedPT,typeQualPT,typeSpecPT};

class Node {
private:
    std::string name;
    std::string typeOut;
    int line;
    int signedB;
    int typeSpec;
    int typeQual;
    int storageSpec;
    int scope;
    int paramNum;
    bool isFunction;
    //std::list <int [3]> paramList;
    //std::list <int [3]> :: iterator paramListIter;

public:
    Node(){
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

    void writeNode(std::string filename) {
        std::ofstream fileP(filename,std::ios::app);
        fileP << "NAME: " << name << std::endl;
        fileP << "SCOPE LEVEL: " << scope << std::endl;
        fileP << "TYPE: ";
        switch(signedB)
        {
            case signedE:
                break;
            case unsignedE:
                fileP << "unsigned ";
                break;
        }
        switch(typeQual)
        {
            case constQ:
                fileP << "const ";
                break;
            case volatileQ:
                fileP << "volatile ";
                break;
            case bothQ:
                fileP << "const volatile";
                break;
        }
        switch(typeSpec)
        {
            case voidS:
                fileP << "void ";
                break;
            case charS:
                fileP << "char ";
                break;
            case shortS:
                fileP << "short ";
                break;
            case intS:
                fileP << "int ";
                break;
            case longS:
                fileP << "long ";
                break;
            case floatS:
                fileP << "float ";
                break;
            case doubleS:
                fileP << "double ";
                break;
            case structS:
                fileP << "struct ";
                break;
        }
        switch(storageSpec)
        {
            case autoS:
                fileP << "auto ";
                break;
            case registerS:
                fileP << "register ";
                break;
            case staticS:
                fileP << "static ";
                break;
            case externS:
                fileP << "extern ";
                break;
            case typedefS:
                fileP << "typedef ";
                break;
        }
        fileP << std::endl;
        fileP << "LINE: " << line << std::endl;
        fileP << std::endl;
        fileP.close();
    }
    void printNode() {
        std::cout << "NAME: " << name << std::endl;
        std::cout << "SCOPE LEVEL: " << scope << std::endl;
        std::cout << "TYPE: ";
        switch(signedB)
        {
            case signedE:
                break;
            case unsignedE:
                std::cout << "unsigned ";
                break;
        }
        switch(typeQual)
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
        switch(typeSpec)
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
        switch(storageSpec)
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
        std::cout << std::endl;
        std::cout << "LINE: " << line << std::endl;
        std::cout << std::endl;
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
    void setFunction(bool funcExsistIn) {isFunction=funcExsistIn;}
    /*
    void addParam(){
        int paramType [3] = {signedE,9,intS};     //each param is a array of size 3
                               //signed,type qualifier, and type specifier
        //paramType[0]=signedE;  //defaults to signed variable
        //paramType[1]=9;        //defaults to 9 which is nothing in the enum
        //paramType[2]=intS;     //always default the type to int cuz C
        paramList.push_back(paramType);

    }
    //typeOfTypes designates weather you are inserting signed,type qualifier, or
    //type specifier
    void addParamValue(int typeOfTypes,int type){
            //paramListIter = paramList.end();
            //*paramListIter[typeOfTypes] = type;
    }
    */
};
