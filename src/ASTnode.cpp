
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

std::ofstream astFileP("ASTnode.dot");

bool printGraphviz = false;

enum nodeTypes {genericN,mathN,idN,constantN,castN,ifN,funcN,forN,whileN,declN,exprN,arrayN};

class ASTnode {
public:
    std::vector<ASTnode*> child;
    std::string production;
    std::string infoString = "";
    int nodeType = genericN;
    int printLabel;
    int lineNum = -1;
    int size = 1;
    bool isArray = false;

    int signedB;
    int storageSpec;
    int typeQual;
    int typeSpec;

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
        static int inc = 0;
        parent->printLabel = inc;
        astFileP << parent->printLabel << " \[label=\"" << parent->printASTnode() << "\"\];" << std::endl;
        if (printGraphviz)
            std::cout << parent->printLabel << " \[label=\"" << parent->infoString << "\"\];" << std::endl;
        inc++;

        for (int i = 0; i < parent->child.size(); i++)
        {
            if (parent->child.size() != 0)
            {
                printSubTreeHelper(parent->child[i]);
                astFileP << parent->printLabel << " -> " << parent->child[i]->printLabel << std::endl;
                if (printGraphviz)
                    std::cout << parent->printLabel << " -> " << parent->child[i]->printLabel << std::endl;
            }
        }
    }

    void sumNode() {
        for (int i = 0; i < child.size(); i++) {
            size += child[i]->size;
        }
        size += -1;
    }


    int determineOffset() {
        static int currentOffset = 0;
        switch(typeSpec) {
            case intS: case longS: case shortS: case floatS:
                currentOffset += 4;
                return 4;
            case doubleS:
                currentOffset += 8;
                return 8;
            case charS:
                currentOffset += 1;
                return 1;
        }
    }
};

class declNode : public ASTnode {
    public:
        int offset = 0;
        declNode(std::string productionIn){production = productionIn;nodeType=declN;}

        void determineOffset() {
            static int currentOffset = 0;
            offset = currentOffset;
            switch(typeSpec) {
                case intS: case longS: case shortS: case floatS:
                    currentOffset += 4;
                    size += 4;
                    break;
                case doubleS:
                    currentOffset += 8;
                    size += 8;
                    break;
                case charS:
                    currentOffset += 1;
                    size += 1;
                    break;
            }
        }

        std::string printASTnode() {
            infoString.append(production);
            infoString.append("\nSIZE: ");
            infoString.append(std::to_string(size));
            return infoString;
        }

};

class idNode : public ASTnode {
    public:
        std::string name;
        int type = -1;
        int scope = -1;
        bool isArray = false;

        idNode(std::string productionIn, int scopeIn)
        {
            production = productionIn;
            scope = scopeIn;
            nodeType = idN;
        }

        std::string printASTnode() {
            infoString.append(production);
            infoString.append("\n");
            infoString.append("TYPE: ");
            infoString.append(printSigned(signedB));
            infoString.append(printStorageSpec(storageSpec));
            infoString.append(printTypeQual(typeQual));
            infoString.append(printTypeSpec(typeSpec));
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
        std::string printSigned(int input){
            switch(input)
            {
                case signedE:
                    return "";
                    break;
                case unsignedE:
                    return "unsigned";
                    break;
            }
            return "";
        }
        std::string printTypeQual(int input){
            switch(input)
            {
                case constQ:
                    return "const ";
                    break;
                case volatileQ:
                    return "volatile ";
                    break;
                case bothQ:
                    return "const volatile ";
                    break;
            }
            return "";
        }
        std::string printTypeSpec(int input) {
            switch(input)
            {
                case voidS:
                    return "void ";
                    break;
                case charS:
                    return "char ";
                    break;
                case shortS:
                    return "short ";
                    break;
                case intS:
                    return "int ";
                    break;
                case longS:
                    return "long ";
                    break;
                case floatS:
                    return "float ";
                    break;
                case doubleS:
                    return "double ";
                    break;
                case structS:
                    return "struct ";
                    break;
            }
            return "";
        }
        std::string printStorageSpec(int input) {
            switch(input)
            {
                case autoS:
                    return "auto ";
                    break;
                case registerS:
                    return "register ";
                    break;
                case staticS:
                    return "static ";
                    break;
                case externS:
                    return "extern ";
                    break;
                case typedefS:
                    return "typedef ";
                    break;
            }
            return "";
        }

};

class castNode : public ASTnode {
    public:
        int oldType, newType;
        castNode(std::string productionIn, int oldTypeIn, int newTypeIn){production = productionIn; newType = newTypeIn; oldType = oldTypeIn;nodeType = castN;}

        std::string printASTnode() {
            infoString.append(production);
            infoString.append("\n");
            infoString.append("TYPE CONVERSION: ");
            infoString.append("\n");
            infoString.append(printTypeSpec(oldType));
            infoString.append(" -> ");
            infoString.append(printTypeSpec(newType));
            return infoString;
        }

        std::string printTypeSpec(int input) {
            switch(input)
            {
                case voidS:
                    return "void ";
                    break;
                case charS:
                    return "char ";
                    break;
                case shortS:
                    return "short ";
                    break;
                case intS:
                    return "int ";
                    break;
                case longS:
                    return "long ";
                    break;
                case floatS:
                    return "float ";
                    break;
                case doubleS:
                    return "double ";
                    break;
                case structS:
                    return "struct ";
                    break;
            }
            return "";
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
        constantNode(std::string productionIn, int typeIn){production = productionIn; type = typeIn; nodeType = constantN;}

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
            else if(type == floatS) {
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
    ifNode(std::string productionIn){production = productionIn;nodeType=ifN;}

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
        int activationFrameSize;
        functionNode(std::string productionIn){production = productionIn;nodeType = funcN;}

        std::string printASTnode() {
            infoString.append(production);
            infoString.append("\nFRAME SIZE: ");
            infoString.append(std::to_string(activationFrameSize));
            return infoString;
        }
};

class forNode : public ASTnode {
    public:

    // CONSTRUCTOR
    forNode(std::string productionIn)
    {
        production = productionIn;
        nodeType = forN;
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
    whileNode(std::string productionIn){production = productionIn;nodeType = whileN;}
    std::string printASTnode() {
        infoString.append(production);
        infoString.append("\n");
        infoString.append("LINE: ");
        infoString.append(std::to_string(lineNum));
        return infoString;
    }
};

class exprNode : public ASTnode {
    public:
        enum exprTypeEnum {lessOp,greatOp,eqOp,notEqOp,lessEpOp,greatEqOp, orOp, andOp, notOp};
        int exprType;
        exprNode(std::string productionIn){production = productionIn;nodeType=exprN;}
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
        enum operationE {addOp, subOp, mulOp, divOp, incOp, decOp, modOp, shlOp, shrOp, xorOp};
        int operation;
        mathNode(std::string productionIn){production = productionIn;nodeType=mathN;}
        std::string printASTnode() {
            infoString.append(production);
            infoString.append("\n");
            infoString.append("LINE: ");
            infoString.append(std::to_string(lineNum));
            return infoString;
    }
};

class arrayNode : public ASTnode {
    public:
        int bound = 1;
        int dimentions;
        int type = -1;
        std::string id;
        arrayNode(std::string productionIn){production = productionIn;nodeType=arrayN;}

        std::string printASTnode() {
            infoString.append(production);
            infoString.append("\n");
            infoString.append("IDENTIFIER: ");
            infoString.append(id);
            infoString.append("\n");
            if (bound != 1) {
                infoString.append("BOUNDS: ");
                infoString.append(std::to_string(bound));
                infoString.append("\n");
                infoString.append("SIZE: ");
                infoString.append(std::to_string(size));
            }
            return infoString;
        }

};
