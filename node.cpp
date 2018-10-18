//
// Name:    symbolTable.cpp
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
#include <string>
#include <iostream>
#include <fstream>

enum typeSpecE {voidS,charS,shortS,intS,longS,floatS,doubleS,structS};
enum typeQualE {constQ,volatileQ};
enum signedE {signedE,unsignedE};
enum storageSpecE {noneSS, autoS,registerS,staticS,externS,typedefS};

class Node {
private:
    std::string name;
    int line;
    int typeSpec;
    int typeQual;
    int storageSpec;
    int signedB;
    int scope;
public:
    Node(){
        resetNode();
    }

    /*
    Node(std::string typeIn, std::string nameIn, int lineIn) {
      type=typeIn;
      name=nameIn;
      line=lineIn;
    }
    */
    void printNode() {
      std::cout << "NAME: " << name << std::endl;
      std::cout << "TYPE: " << signedB << typeQual << storageSpec << typeSpec << std::endl;
      std::cout << "LINE: " << line << std::endl;
      std::cout << std::endl;
    }
    void resetNode() {
        setName("");
        setLine(0);
        setSigned(signedE);
        setTypeSpec(9);
        setTypeQual(9);
        setStorageSpec(9);
        setScope(0);
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
    void setTypeQual(int typeQualIn) {typeSpec=typeQualIn;}
    void setLine(int lineIn) {line=lineIn;}
    void setSigned(int signIn) {signedB=signIn;}
    void setStorageSpec(int storageSpecIn) {storageSpec=storageSpecIn;}
};

/*
class stringVal: public Node{
public:
	std::string value;
    stringVal(std::string typeIn, std::string name, int lineIn):Node(typeIn,name,lineIn) {
        value = val;
    }
    void printNode() {
      std::cout << "NAME: " << name << std::endl;
      std::cout << "TYPE: " << type << std::endl;
    }
};

class intVal: public Node{
public:
	int value;
    intVal(std::string typeIn, std::string name, int lineIn):Node(typeIn,name,lineIn) {
        value = val;
    }
    void printNode() {
      std::cout << "NAME: " << name << std::endl;
      std::cout << "TYPE: " << type << std::endl;
      std::cout << "VALUE: " << value << std::endl << std::endl;
    }
};

class doubleVal: public Node{
public:
    double value;
    doubleVal(std::string typeIn, std::string name, int lineIn):Node(typeIn,name,lineIn) {
        value = val;
    }
    void printNode() {
      std::cout << "NAME: " << name << std::endl;
      std::cout << "TYPE: " << type << std::endl;
      std::cout << "VALUE: " << value << std::endl << std::endl;
    }
};

class charVal: public Node{
public:
	char value;
    charVal(std::string typeIn, std::string name, int lineIn):Node(typeIn,name,lineIn) {
        value = val;
    }
    void printNode() {
      std::cout << "NAME: " << name << std::endl;
      std::cout << "TYPE: " << type << std::endl;
      std::cout << "VALUE: " << value << std::endl << std::endl;
    }
};
*/
