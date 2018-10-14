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

bool lookup = false;
bool declaration = true;

class Node {
public:
    std::string type;
    std::string name;

    Node(std::string typeIn, std::string nameIn) {
      type=typeIn;
      name=nameIn; 
    }
    void printNode() {
      std::cout << "NAME: " << name << std::endl;
      std::cout << "TYPE: " << type << std::endl;
    }
};

class stringVal: public Node{
public:
	std::string value;
    stringVal(std::string typeIn, std::string name, std::string val):Node(typeIn,name) {
        value = val;
    }
    void printNode() {
      std::cout << "NAME: " << name << std::endl;
      std::cout << "TYPE: " << type << std::endl;
      std::cout << "VALUE: " << value << std::endl << std::endl;
    }
};

class intVal: public Node{
public:
	int value;
    intVal(std::string typeIn, std::string name, int val):Node(typeIn,name) {
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
    doubleVal(std::string typeIn, std::string name, double val):Node(typeIn,name) {
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
    charVal(std::string typeIn, std::string name, char val):Node(typeIn,name) {
        value = val;
    }
    void printNode() {
      std::cout << "NAME: " << name << std::endl;
      std::cout << "TYPE: " << type << std::endl;
      std::cout << "VALUE: " << value << std::endl << std::endl;
    }
};
