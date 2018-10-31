
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

enum nodeType {idNodeE, ifNodeE, functionNodeE, forNodeE};

class ASTnode {
public:
    std::vector<ASTnode*> child;
    std::string production;
    int printLabel;
    ASTnode(){}
    ASTnode(std::string productionIn){
        production = productionIn;
    }
    virtual void printASTnode() {
        std::cout << "NODE: " << production << std::endl;
        std::cout << "TYPE: " << "GenericNode" << std::endl;
    }
    void addNode(ASTnode * newPointer) {
        child.push_back(newPointer);
    }
};


class idNode : public ASTnode {
    public:
        std::string name;
        idNode(std::string productionIn){production = productionIn;}
        void printASTnode() {
            std::cout << "NODE: " << production << std::endl;
            std::cout << "TYPE: " << "IDNode" << std::endl;
        }

};

class constantNode : public ASTnode {
    public:
        std::string name;
        int intConst;
        char charConst;
        double doubleConst;
        std::string stringConst = "";
        constantNode(std::string productionIn){production = productionIn;}
        void printASTnode() {
            std::cout << "NODE: " << production << std::endl;
            std::cout << "TYPE: " << "CONSTANTNode" << std::endl;
        }

};

class ifNode : public ASTnode {
    public:
    ifNode(std::string productionIn){production = productionIn;}
    void printASTnode() {
        std::cout << "NODE: " << production << std::endl;
        std::cout << "TYPE: " << "IFNode" << std::endl;
    }

};

class functionNode : public ASTnode {
    public:
    functionNode(std::string productionIn){production = productionIn;}
    void printASTnode() {
        std::cout << "NODE: " << production << std::endl;
        std::cout << "TYPE: " << "FunctionNode" << std::endl;
    }

};

class forNode : public ASTnode {
    public:
    forNode(std::string productionIn){production = productionIn;}
    void printASTnode() {
        std::cout << "NODE: " << production << std::endl;
        std::cout << "TYPE: " << "FORNode" << std::endl;
    }

};

class whileNode : public ASTnode {
    public:
    whileNode(std::string productionIn){production = productionIn;}
    void printASTnode() {
        std::cout << "NODE: " << production << std::endl;
        std::cout << "TYPE: " << "WHILENode" << std::endl;
    }

};
