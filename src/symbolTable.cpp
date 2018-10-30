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
extern bool printSymbolNums;
extern bool printFile;
extern std::string buffer;
extern std::string srcFile;
extern std::string outSrcFile;

class SymbolTable {

  private:
    std::list<std::map<std::string,Node>> symbolTable;
    std::list <std::map<std::string,Node>> :: iterator currentScope;
    std::list <std::map<std::string,Node>> :: iterator currentLooker;
    std::map<std::string,Node> :: iterator currentEntry;
  public:
    int currentScopeNum = 0;
    int mode = insert;
    bool globalSearch=false;

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
        currentScopeNum--;
        currentEntry = currentScope->begin();
        return ret;
    }

    // addNewScope
    // puts a tree on the top of the stack
    void addNewScope () {
        std::map <std::string,Node> newMap;
        symbolTable.push_back(newMap);
        currentScope++;
        currentScopeNum++;
        currentEntry = currentScope->begin();
    }

    void insertSymbol (Node symbol) {
        if (mode == insert) {
            if (!searchTopLevel(symbol)) {
                //checks if current symbol is in scope
                globalSearch = searchPrevScope(symbol);
                currentScope->insert(std::pair <std::string,Node> (symbol.getName(), symbol));
            }
        }
    }

    // writeFile
    // opens a file for writing writes the contents
    // of the symbol table to a file.
    void writeST (std::string filename) {
        // Create the file pointer
        // Open the file for writing
        std::ofstream myfile(filename,std::ios::app);
        for(currentLooker = symbolTable.begin(); currentLooker != symbolTable.end(); currentLooker++)
        {
            std::map<std::string,Node> currentScopeLoop = *currentLooker;
            for(std::map<std::string,Node> :: iterator iter = currentScopeLoop.begin(); iter != currentScopeLoop.end(); iter++)
            {
                Node treeNode = iter->second;
                treeNode.writeNode(filename);
            }
        }
        myfile.close();
    }

    void printST () {
        std::cout << "Symbol Table Output:" << std::endl << std::endl;
        for(currentLooker = symbolTable.begin(); currentLooker != symbolTable.end(); currentLooker++)
        {
            std::map<std::string,Node> currentScopeLoop = *currentLooker;
            std::cout << "SIZE OF ST SCOPE: " << currentScopeLoop.size() << std::endl;
            std::cout << std::endl;
            for(std::map<std::string,Node> :: iterator iter = currentScopeLoop.begin(); iter != currentScopeLoop.end(); iter++)
            {
                Node treeNode = iter->second;
                treeNode.printNode();
            }
        }
    }

    bool searchTopLevel (Node node) {
        return searchScope(node,currentScope); //searches top level scope which is currentScope
    }
    bool searchScope (Node node, std::list <std::map<std::string,Node>> :: iterator searchWindow){
        std::map<std::string,Node> currentScopeMap = *searchWindow;
        //if (searchWindow != currentScope)
            //std::cout << "NOT TOP LEVEL" << std::endl;
        //std::cout << "SEARCH WINDOW SIZE: " << currentScopeMap.size() << std::endl;
        int i = 1;
        if (mode == insert){
			for(std::map<std::string,Node> :: iterator iter = currentScopeMap.begin(); iter != currentScopeMap.end(); iter++)
			{
                //node is 2nd in map pair
                Node treeNode = iter->second;
                //redecl block
                //shadowing block
                //std::cout << i << " TREE NODE NAME: " << treeNode.getName() << std::endl;
                //std::cout << " INSERT NODE NAME: " << node.getName() << std::endl;
				if ((treeNode.getName().compare(node.getName())==0) && (treeNode.getScope() == node.getScope()) && (treeNode.getLine() != node.getLine()))
                {
                    std::cout << "\e[31;1m ERROR: \e[0m Redifinition of Variable: " << node.getName() << " previous declaration on line " << treeNode.getLine() << std::endl;
                    printError();
                    exit(1);
					return true;
                }
				if ((treeNode.getName().compare(node.getName())==0) && (node.getLine() != treeNode.getLine()))
                {
                    std::cout << "\e[33;1m WARNING: \e[0m Shadowing of Variable: " << node.getName() << " previous declaration on line " << treeNode.getLine() << std::endl;
					return true;
                }
                i++;
			}
            return false;
        }
		else if (mode == lookup)
		{
			for(std::map<std::string,Node> :: iterator iter = currentScopeMap.begin(); iter != currentScopeMap.end(); iter++)
			{
                Node treeNode = iter->second;
				if (treeNode.getName().compare(treeNode.getName())==0)
                {
					return true;
                }
            }
		}
      	return false;
    }

    // searchTree
    // Searches for a symbol on the top stack ie current scope
    // returns true if found a symbol already in ST
    bool searchTree (Node node){
        bool top = searchTopLevel(node);
        bool all = searchPrevScope(node);
        if (top || all)
            return true;
        return false;
    }
    void printError () {
        std::ifstream srcFileP(srcFile);
        std::string buffer="";
        for (int i = 0; i < lineNum; i++)
        {
            std::getline(srcFileP,buffer);
        }
        std::cout << buffer << std::endl;
        srcFileP.close();
    }
    //searches past scopes for symbols
    bool searchPrevScope(Node node)
    {
        //std::cout << "SEARCHING PREVIOUS SCOPE" << std::endl;
        currentLooker = currentScope;
        bool ret = false;
        while (currentLooker != symbolTable.begin())
        {
            currentLooker--;
            //std::cout << "SEARCHING PREVIOUS SCOPE" << std::endl;
            ret = searchScope(node,currentLooker);
            if (ret)
                return ret;
        }
        return ret;
    }
    std::list <std::map<std::string,Node>> :: iterator getCurrentScope() {return currentScope;}
    std::map<std::string,Node> :: iterator getCurrentEntry() {return currentEntry;}
    void nextEntry() {currentEntry++;}
};
