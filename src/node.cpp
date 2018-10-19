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
#include <string>
#include <iostream>
#include <fstream>

enum signedEnum {signedE,unsignedE};
enum typeQualE {constQ,volatileQ,bothQ};
enum storageSpecE {autoS,registerS,staticS,externS,typedefS};
enum typeSpecE {voidS,charS,shortS,intS,longS,floatS,doubleS,structS};

class Node {
private:
    std::string name;
    std::string typeOut;
    int line;
    int typeSpec;
    int typeQual;
    int storageSpec;
    int signedB;
    int scope;
public:
    Node(){
        setName("");
        setLine(0);
        setSigned(0);
        setTypeSpec(9);
        setTypeQual(9);
        setStorageSpec(9);
        setScope(0);
    }

    /*
    Node(std::string typeIn, std::string nameIn, int lineIn) {
      type=typeIn;
      name=nameIn;
      line=lineIn;
    }
    */
    void printNode() {
        //typeOut = makeTypeString();
        std::cout << "NAME: " << name << std::endl;
        std::cout << "SCOPE LEVEL: " << scope << std::endl;
        std::cout << "TYPE: " << signedB << typeQual << storageSpec << typeSpec << std::endl;
        std::cout << "LINE: " << line << std::endl;
        std::cout << std::endl;
    }
    /*
    void writeNode(std::string filename) {
        //typeOut = makeTypeString();
        std::ofstream myfileP(filename,std::ios::app);
        myfileP << "NAME: " << name << std::endl;
        myfileP << "SCOPE LEVEL: " << scope << std::endl;
        myfileP << "TYPE: ";
        myfileP << typeOut << std::endl;
        myfileP << "LINE: " << line << std::endl;
        myfileP << std::endl;
        myfileP.close();
    }
    */
    /*
    std::string makeTypeString() {
        if (storageSpec == externS)
          typeOut.append("extern");
        if (signedB == unsignedE) //checks if unsigned
          typeOut.append("unsigned");
        if (typeQual == constQ)
          typeOut.append("unsigned");
        if (typeQual == volatileQ)
          typeOut.append("volatile");
        if (typeQual == bothQ)
          typeOut.append("volatile unsigned");
        if (storageSpec == autoS)
          typeOut.append("auto");
        if (storageSpec == registerS)
          typeOut.append("register");
        if (storageSpec == staticS)
          typeOut.append("static");
        if (storageSpec == typedefS)
          typeOut.append("typedef");
        if (storageSpec == voidS)
          typeOut.append("void");
        if (storageSpec == charS)
          typeOut.append("char");
        if (storageSpec == shortS)
          typeOut.append("short");
        if (storageSpec == shortS)
          typeOut.append("short");
        if (storageSpec == intS)
          typeOut.append("int");
        if (storageSpec == longS)
          typeOut.append("long");
        if (storageSpec == floatS)
          typeOut.append("float");
        if (storageSpec == doubleS)
          typeOut.append("double");
        if (storageSpec == structS)
          typeOut.append("struct");
        else
          typeOut.append("empty");

    }
    */
    void resetNode() {
        setName("");
        setLine(-1); //-1 is error if line is neg 1
        setSigned(0);
        setTypeSpec(9);
        setTypeQual(9);
        setStorageSpec(9);
        setScope(-1); //-1 is error if scope is -1
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
