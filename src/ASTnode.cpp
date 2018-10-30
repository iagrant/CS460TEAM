
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

enum nodeType {idNodeE, ifNodeE, functionNodeE, forNodeE};

class ASTnode {
protected:
    std::string production; 
    std::vector<ASTnode*> pointers;
public:
    ASTnode(){}
    ASTnode(std::string productionIn){
        production = productionIn;
        printASTnode();
    }
    virtual void printASTnode() {
        std::cout << "NODE: " << production << std::endl;
        std::cout << "TYPE: " << "GenericNode" << std::endl;
    }
    void addNode(ASTnode * newPointer) {
        pointers.push_back(newPointer);
    }
};


class idNode : public ASTnode {
    public:
        std::string name;
        idNode(std::string productionIn){production = productionIn; printASTnode();}
        void printASTnode() {
            std::cout << "NODE: " << production << std::endl;
            std::cout << "TYPE: " << "IDNode" << std::endl;
        }
    
};

class ifNode : public ASTnode {
    public:
    ifNode(std::string productionIn){production = productionIn; printASTnode();}
    void printASTnode() {
        std::cout << "NODE: " << production << std::endl;
        std::cout << "TYPE: " << "IFNode" << std::endl;
    }

};

class functionNode : public ASTnode {
    public:
    functionNode(std::string productionIn){production = productionIn; printASTnode();}
    void printASTnode() {
        std::cout << "NODE: " << production << std::endl;
        std::cout << "TYPE: " << "FunctionNode" << std::endl;
    }

};

class forNode : public ASTnode {
    public:
    forNode(std::string productionIn){production = productionIn; printASTnode();}
    void printASTnode() {
        std::cout << "NODE: " << production << std::endl;
        std::cout << "TYPE: " << "FORNode" << std::endl;
    }

};
