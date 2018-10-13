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
#include "node.cpp"
bool lookup = false;
bool insert = true;

class SymbolTable {

  private:
    std::list<std::map<std::string,Node>> symbolTable;
    std::list <int> :: iterator currentScope;
  public:
    std::list <int> :: iterator currentLooker;
    SymbolTable () {
        std::map <std::string,Node> map1;
        symbolTable.push_back(map1);
    }

    // removeScope
    // returns a tree from the top of the stack
    std::map<std::string,Node> removeScope () {
        std::map<std::string,Node> ret = symbolTable.back();
        symbolTable.pop_back();
        currentScope--;
        return ret;
    }

    // insertScope
    // puts a tree on the top of the stack
    void insertScope (std::map<std::string,Node> newMap) {
        symbolTable.push_back(newMap);
        currentScope++;
    }

    void insertSymbol (Node symbol) {
        if (insert)
            *currentScope.insert(std::pair <string,Node> (symbol -> name, symbol));
        else
            std::cout << "Syntax Error: Declared variable outside declaration block" << std::endl;
    }

    // writeFile
    // opens a file for writing writes the contents
    // of the symbol table to a file.
    // why?
    void writeFile (std::string filename) {
        // Create the file pointer
        std::ofstream myfile(outSrcFile,std::ios::app);
        // Open the file for writing
        currentLooker = symbolTable.start();
        myfile.open(filename);
        currentLooker--;
        while (currentLooker != symbolTable.end())
        {
			for(auto iter = std::map.begin(); iter != std::map.end(); iter++)
            {
                myfile << "Writing this to a file.\n";
                myfile << *iter.printNode();
            }
        }
        myfile.close();
    }

    // searchTree
    // Searches for a symbol on the stack
    bool searchTree (Node *node) {
        if (insert)
		{
			for(auto iter = std::map.begin(); iter != std::map.end(); iter++)
			{
				if (*iter.name == node.name)
                {
                    std::cout << "Warning shadowing variable " << node->name << std::endl;
					return true;
                }
			}
        }
		else if (lookup)
		{
			for(auto iter = std::map.begin(); iter != std::map.end(); iter++)
			{
				if (*iter -> name == node -> name)
                {
                    node -> value = *iter -> value;
                    return true;
                }
			}
		}
      	return false;
    }
    void searchPrevScope(Node node)
    {
        currentLooker = getCurrentScope();
        currentLooker--;
        bool ret = false;
        while (currentLooker != symbolTable.start())
        {
            searchTree(node);
        }
    }

    std::list <int> :: iterator getCurrentScope() {return currentScope;}
};
