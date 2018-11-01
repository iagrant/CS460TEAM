
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

std::ofstream astFileP("ASTnode.dot");

bool printGraphviz = false;

class ASTnode {
public:
    std::vector<ASTnode*> child;
    std::string production;
    std::string infoString = "";
    int printLabel;
    int lineNum;
    ASTnode(){}

    ASTnode(std::string productionIn){
        production = productionIn;
    }

    virtual std::string printASTnode() {
        infoString.append(production);
        return infoString;
    }

    void addNode(ASTnode * newPointer) {
        child.push_back(newPointer);
    }

    void printSubTree () {
        printSubTreeHelper(this);
    }

    void printSubTreeHelper (ASTnode * parent) {
        if (printGraphviz)
        {
            static int inc = 0;
            parent->printLabel = inc;
            astFileP << parent->printLabel << " \[label=\"" << parent->printASTnode() << "\"\];" << std::endl;
            std::cout << parent->printLabel << " \[label=\"" << parent->infoString << "\"\];" << std::endl;
            inc++;

            for (int i = 0; i < parent->child.size(); i++) 
            {
                if (parent->child.size() != 0) 
                {
                    printSubTreeHelper(parent->child[i]);
                    astFileP << parent->printLabel << " -> " << parent->child[i]->printLabel << std::endl;
                    std::cout << parent->printLabel << " -> " << parent->child[i]->printLabel << std::endl;
                }
            }
        }
    }
};


class idNode : public ASTnode {
    public:
        std::string name;
        int type = -1;
        int scope = -1;
        idNode(std::string productionIn, int scopeIn)
        {
            production = productionIn;
            scope = scopeIn;
        }

        std::string printASTnode() {
            infoString.append(production);
            infoString.append("\n");
            infoString.append("NAME: ");
            infoString.append(name);
            infoString.append("\n");
            infoString.append("LINE: ");
            infoString.append(std::to_string(lineNum));
            infoString.append("\n");
            infoString.append("SCOPE: ");
            infoString.append(std::to_string(scope));
            return infoString;
        }

};

class constantNode : public ASTnode {
    public:
        std::string name;
        int type;
        int intConst = NULL;
        char charConst = NULL;
        double doubleConst = NULL;
        std::string stringConst = ""; 
        constantNode(std::string productionIn, int typeIn){production = productionIn; type = typeIn;}

        std::string printASTnode() {
            if (type == intS) {
                infoString.append(production);
                infoString.append("\n");
                infoString.append("VALUE: ");
                infoString.append(std::to_string(intConst));
            }
            else if(type == doubleS) {
                infoString.append(production);
                infoString.append("\n");
                infoString.append("VALUE: ");
                infoString.append(std::to_string(doubleConst));
            }
            else if(type == stringS) {
                infoString.append(production);
                infoString.append("\n");
                infoString.append("VALUE: ");
                infoString.append(stringConst);
            }
            else if(type == charS){
                infoString.append(production);
                infoString.append("\n");
                infoString.append("VALUE: ");
                infoString.push_back(charConst);
            }

            infoString.append("\n");
            infoString.append("LINE: ");
            infoString.append(std::to_string(lineNum));

            return infoString;
        }
};

class ifNode : public ASTnode {
    public:
    ifNode(std::string productionIn){production = productionIn;}

    std::string printASTnode() {
        infoString.append(production);
        infoString.append("\n");
        infoString.append("LINE: ");
        infoString.append(std::to_string(lineNum));
        return infoString;
    }
};

class functionNode : public ASTnode {
    public:
    functionNode(std::string productionIn){production = productionIn;}

    std::string printASTnode() {
        infoString.append(production);
        return infoString;
    }
};

class forNode : public ASTnode {
    public:

    // CONSTRUCTOR
    forNode(std::string productionIn)
    {
        production = productionIn; 
    }

    // PRINT ASTNODE
    std::string printASTnode() {
        infoString.append(production);
        infoString.append("\n");
        infoString.append("LINE: ");
        infoString.append(std::to_string(lineNum));
        return infoString;
    }
};

class whileNode : public ASTnode {
    public:
    whileNode(std::string productionIn){production = productionIn;}
    std::string printASTnode() {
        infoString.append(production);
        infoString.append("\n");
        infoString.append("LINE: ");
        infoString.append(std::to_string(lineNum));
        return infoString;
    }
};

class mathNode : public ASTnode {
    public:
        enum operationE {addOp, subOp, mulOp, divOp, incOp, decOp, modOp, shlOp, shrOp, andOp, orOp, xorOp, notOp};
        int operation;
        mathNode(std::string productionIn){production = productionIn;}
        std::string printASTnode() {
            infoString.append(production);
            infoString.append("\n");
            infoString.append("LINE: ");
            infoString.append(std::to_string(lineNum));
            return infoString;
    }
        /* FOR USE WITH MATH OPERATIONS
            switch (operation) {
                case addOp:
                    break;
                case subOp:
                    break;
                case mulOp:
                    break;
                case divOp:
                    break;
                case incOp:
                    break;
                case decOp:
                    break;
                case modOp:
                    break;
                case shlOp:
                    break;
                case shrOp:
                    break;
                case andOp:
                    break;
                case orOp:
                    break;
                case xorOp:
                    break;
                case notOp:
                    break;
            }
            */

};
