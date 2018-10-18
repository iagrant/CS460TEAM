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

enum modeE {lookup,insert};

extern int lineNum;
extern int tabNum;
extern int colNum;
extern bool printToken;
extern bool printProductions;
extern bool printSymbol;
extern bool printFile;
extern std::string buffer;
extern std::string srcFile;
extern std::string outSrcFile;
int mode = insert;

class SymbolTable {

  private:
    std::list<std::map<std::string,Node>> symbolTable;
    std::list <std::map<std::string,Node>> :: iterator currentScope;
    std::list <std::map<std::string,Node>> :: iterator currentLooker;
    std::map<std::string,Node> :: iterator currentEntry;
  public:

    //Default Constructor
    SymbolTable () {
        std::map <std::string,Node> map1;
        symbolTable.push_back(map1);
        currentScope = symbolTable.begin();
        currentEntry = currentScope->begin();
    }

    // removeScope
    // returns a tree from the top of the stack
    std::map<std::string,Node> removeScope () {
        std::map<std::string,Node> ret = symbolTable.back();
        symbolTable.pop_back();
        currentScope--;
        currentEntry = currentScope->begin();
        return ret;
    }

    // addNewScope
    // puts a tree on the top of the stack
    void addNewScope () {
        std::map <std::string,Node> newMap;
        symbolTable.push_back(newMap);
        currentScope++;
        currentEntry = currentScope->begin();
    }

    void insertSymbol (Node symbol) {
        if (mode == insert) {
            if (!searchTree(symbol))
                currentScope->insert(std::pair <std::string,Node> (symbol.getName(), symbol));
            else
                std:: cout << "Warning Shadowing Variable: " << symbol.getName() << "on line: " << symbol.getLine() << std::endl;
        }
        else
            std::cout << "Syntax Error: Declared variable outside declaration block" << std::endl;
    }

    /*
    // writeFile
    // opens a file for writing writes the contents
    // of the symbol table to a file.
    void writeFile (std::string filename) {
        // Create the file pointer
        std::ofstream myfile(outSrcFile,std::ios::app);
        // Open the file for writing
        currentLooker = symbolTable.begin();
        myfile.open(filename);
        currentLooker--;
        while (currentLooker != symbolTable.end())
        {
           std::map<std::string,Node> m = *currentScope;
			for(std::map<std::string,Node> :: iterator iter = m.begin(); iter != m.end(); iter++)
            {
                myfile << "Writing this to a file.\n";
                myfile << *iter.printNode();
            }
        }
        myfile.close();
    }

    */
    void printST () {
        for(currentLooker = symbolTable.begin(); currentLooker != symbolTable.end(); currentLooker++)
        {
            std::map<std::string,Node> m = *currentLooker;
            std::cout << m.size() << std::endl;
            std::cout << "NEW SCOPE" << std::endl;
            for(std::map<std::string,Node> :: iterator iter = m.begin(); iter != m.end(); iter++)
            {
                Node n = iter->second;
                n.printNode();
            }
        }
    }

    // searchTree
    // Searches for a symbol on the stack
    bool searchTree (Node node) {
        if (insert){
            std::map<std::string,Node> m = *currentScope;
			for(std::map<std::string,Node> :: iterator iter = m.begin(); iter != m.end(); iter++)
			{
                Node n = iter->second;
				if (n.getName().compare(node.getName()))
                {
                    std::cout << "Warning shadowing variable " << node.getName() << std::endl;
					return true;
                }
			}
        }
		else if (lookup)
		{
            std::map<std::string,Node> m = *currentScope;
			for(std::map<std::string,Node> :: iterator iter = m.begin(); iter != m.end(); iter++)
			{
                Node n = iter->second;
				if (n.getName().compare(node.getName()))
                {
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
        while (currentLooker != symbolTable.begin())
        {
            searchTree(node);
        }
    }
    std::list <std::map<std::string,Node>> :: iterator getCurrentScope() {return currentScope;}
    std::map<std::string,Node> :: iterator getCurrentEntry() {return currentEntry;}
    void nextEntry() {currentEntry++;}
};
