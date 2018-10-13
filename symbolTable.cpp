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
#include <list>
#include <iterator>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
bool lookup = false;
bool insert = true;

class Node {
public:
    std::string type;
    Node(std::string typeIn) {
      type=typeIn;
    }
    void printNode() {
      std::cout << type << std::endl;
      std::cout << value << std::endl;
    }
};

class stringVal: public Node{
public:
	std::string value;
};

class intVal: public Node{
public:
	int value;
}

class doubleVal: public Node{
public:
     double value;
};

class charVal: public Node{
public:
	char value;
}


/*
class idNode : public Node {
  public:
  string identifier;
  idNode (string id) {identifier=id;}

};
class forNode : public Node {
  public:
    //not sure what  to have it contain
};
*/

class SymbolTable {

  private:
    list<map<string,Node>> symbolTable;
  public:
    list <int> :: iterator currentScope;
    list <int> :: iterator currentLooker;
    SymbolTable () {
        map <string,Node> map1;
        symbolTable.push_back(map1);
    }

    // removeScope
    // returns a tree from the top of the stack
    map<string,Node> removeScope () {
        map<string,Node> ret = symbolTable.back();
        symbolTable.pop_back();
        currentScope--;
        return ret;
    }

    // insertScope
    // puts a tree on the top of the stack
    void insertScope (map<string,Node> newMap) {
        symbolTable.push_back(newMap);
        currentScope++;
    }

    void insertSymbol (Node symbol) {
        if (insert)
            *currentScope.insert(symbol->Name, symbol);
        else
            std::cout << "Syntax Error Declared var outside declaration block" << std:: endl;
    }

    // writeFile
    // opens a file for writing writes the contents
    // of the symbol table to a file.
    // why?
    void writeFile (string filename) {
            // Create the file pointer
        ofstream myfile;
            // Open the file for writing
        myfile.open(filename);
            // Replace this with actual implementation
        myfile << "Writing this to a file.\n";
            // Close the file pointer
        myfile.close();
    }

    // searchTree
    // Searches for a symbol on the stack
    map<string,Node>* searchTree (Node node) {

		for(auto iter = map.begin(); iter != map.end(); iter++)
		{
			if (*iter -> value == node-> value)
		}

      return tree;

    }
    vector<map<string,Node>>* getStPtr() {return &stVector;}

};
