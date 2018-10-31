
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
};


class idNode : public ASTnode {
    public:
        std::string name;
        idNode(std::string productionIn){production = productionIn;}

        std::string printASTnode() {
            infoString.append(production);
            infoString.append("\n");
            infoString.append(name);
            return infoString;
        }

};

class constantNode : public ASTnode {
    public:
        std::string name;
        int intConst = NULL;
        char charConst = NULL;
        double doubleConst = NULL;
        std::string stringConst = ""; 
        constantNode(std::string productionIn){production = productionIn;}

        std::string printASTnode() {
            if (intConst != NULL) {
                infoString.append(production);
                infoString.append("\n");
                infoString.append(std::to_string(intConst));
            }
            else if(doubleConst != NULL) {
                infoString.append(production);
                infoString.append("\n");
                infoString.append(std::to_string(doubleConst));
            }
            else if(stringConst != "") {
                infoString.append(production);
                infoString.append("\n");
                infoString.append(stringConst);
            }
            else {
                infoString.append(production);
                infoString.append("\n");
                infoString.push_back(charConst);
            }

            return infoString;
        }

};

class ifNode : public ASTnode {
    public:
    ifNode(std::string productionIn){production = productionIn;}

    std::string printASTnode() {
        infoString.append(production);
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
    forNode(std::string productionIn){production = productionIn;}

    std::string printASTnode() {
        infoString.append(production);
        return infoString;
    }

};

class whileNode : public ASTnode {
    public:
    whileNode(std::string productionIn){production = productionIn;}
    std::string printASTnode() {
        infoString.append(production);
        return infoString;
    }

};

class mathNode : public ASTnode {
    public:
        enum int operationE {addOp, subOp, mulOp, divOp, incOp, decOp, modOp, shlOp, shrOp, andOp, orOp, xorOp, notOp};
        int operation;
        mathNode(std::string productionIn){production = productionIn;}
        std::string printASTnode() {
            infoString.append(production);
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
