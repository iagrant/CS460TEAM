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
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
bool lookup = false;
bool declaration = true;

class Node {
public:
    std::string type;
    Node(string typeIn) {
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
    vector<map<string,Node>> stVector;
  public:

    // Paramitized Constructor LMAO
    SymbolTable (vector<map<string,Node>> inVector, map<string,Node> initialTree) {
        stVector = inVector;
        stVector.push_back(initialTree);
    }

    // removeSymbol
    // returns a tree from the top of the stack
    map<string,Node> removeSymbol () {
        return stVector.back();
    }

    // insertSymbol
    // puts a tree on the top of the stack
    void insertSymbol (map<string,Node> newMap) {
        stVector.push_back(newMap);
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


      return tree;

    }
    vector<map<string,Node>>* getStPtr() {return &stVector;}

};
