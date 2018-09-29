//
// Name:    symbolTable.cpp
// Author:  Semantic Team (Franklin, Grant, Knutson)
// Purpose: The symbol table is implemented as a stack of Binary Search Trees. When the scanning begins a BST will be pushed onto the stack for the main program. Every time we enter a procedure a BST will be pushed onto the stack and all of the local variables will be stored there. When a procedure is finished that level of the stack will be popped.
//

#include <iostream>
#include <stack>
#include <map>
#include <strings>
#include <iostream>
#include <fstream>

using namespace std;

class SymbolTable {

    private stack<map> my_stack;

    // Default Constructor
    SymbolTable (stack<map my_stack, map<int> initial_tree) {
        this.my_stack = my_stack;
        my_stack.push(initial_tree);
    }

    // removeSymbol
    // returns a tree from the top of the stack
    map<int> removeSymbol () {
        return my_stack.pop();
    }

    // insertSymbol
    // puts a tree on the top of the stack
    void insertSymbol (map<int> new_map) {
        my_stack.push(new_map);
    }

    // writeFile
    // opens a file for writing writes the contents
    // of the symbol table to a file.
    void writeFile (string filename) {
            // Create the file pointer
        ofstream myfile;
            // Open the file for writing
        myfile.open (filename);
            // Replace this with actual implementation
        myfile << "Writing this to a file.\n";
            // Close the file pointer
        myfile.close();
    }

    // searchTree
    // Searches for a symbol on the stack
    map<int>* searchTree () {


    }
}
