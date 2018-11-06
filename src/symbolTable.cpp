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
extern bool buildingFunction;
extern std::string buffer;
extern std::string srcFile;
extern std::string outSrcFile;

class SymbolTable {

  private:
    std::list<std::map<std::string,Node>> symbolTable;
    std::list <std::map<std::string,Node>> :: iterator currentLooker;
    std::map<std::string,Node> :: iterator currentEntry;
  public:
    std::list <std::map<std::string,Node>> :: iterator currentScope;
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
            std::pair<bool,Node> searchRes = searchTopLevel(symbol.getName());
            if (!searchRes.first) {
                //checks if current symbol is in scope
                /*
                std::map<std::string,Node>::reverse_iterator last = getCurrentPair();
                bool test = last->second.getFunction();
                globalSearch = searchPrevScope(symbol);
                int tempScope = last->second.getScope();
                if (test)
                    tempScope++;
                symbol.setScope(tempScope);
                */
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
            if (currentScopeLoop.size() > 0){
                std::cout << "SIZE OF ST SCOPE: " << currentScopeLoop.size() << std::endl;
                std::cout << std::endl;
            }
            for(std::map<std::string,Node> :: iterator iter = currentScopeLoop.begin(); iter != currentScopeLoop.end(); iter++)
            {
                Node treeNode = iter->second;
                treeNode.printNode();
            }
        }
    }

    std::pair<bool,Node> searchTopLevel (std::string name) {
        return searchScope(name,currentScope); //searches top level scope which is currentScope
    }
    std::pair<bool,Node> searchScope (std::string name, std::list <std::map<std::string,Node>> :: iterator searchWindow){
        Node retNode;
        std::pair<bool,Node> ret = std::pair<bool,Node>(false,retNode);
        std::map<std::string,Node> currentScopeMap = *searchWindow;
        if (mode == insert){
			for(std::map<std::string,Node> :: iterator iter = currentScopeMap.begin(); iter != currentScopeMap.end(); iter++)
			{
                //
                //node is 2nd in map pair
                Node treeNode = iter->second;
                //function proto block
                /*
                if (treeNode.isProto && node.isImplementation){
                    ret.second = treeNode;
                    ret.first = true;
                    return ret;
                }
                */

				if ((treeNode.getName().compare(name)==0) && searchWindow == currentScope)
                {
                    ret.second = treeNode;
                    ret.first = true;
                    std::cout << "\e[31;1m ERROR: \e[0m Redifinition of Variable: " << name << " previous declaration on line " << treeNode.getLine() << std::endl;
                    printError();
                    exit(1);
					return ret;
                }
				if ((treeNode.getName().compare(name)==0) && searchWindow != currentScope)
                {
                    ret.second = treeNode;
                    ret.first = true;
                    std::cout << "\e[33;1m WARNING: \e[0m Shadowing of Variable: " << name << " previous declaration on line " << treeNode.getLine() << std::endl;
					return ret;
                }
			}
            return ret;
        }
		else if (mode == lookup)
		{
			for(std::map<std::string,Node> :: iterator iter = currentScopeMap.begin(); iter != currentScopeMap.end(); iter++)
			{
                Node treeNode = iter->second;
				if (treeNode.getName().compare(name)==0)
                {
                    ret.second = treeNode;
                    ret.first = true;
					return ret;
                }
            }
		}
      	return ret;
    }

    // searchTree
    // Searches for a symbol on the top stack ie current scope
    // returns true if found a symbol already in ST
    std::pair<bool,Node>searchTree (std::string name){
        Node retNode;
        std::pair<bool,Node> ret = std::pair<bool,Node>(false,retNode);
        std::pair<bool,Node> top = searchTopLevel(name);
        std::pair<bool,Node> all = searchPrevScope(name);
        if (top.first)
            return top;
        if (all.first)
            return all;
        return ret;
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
    std::pair<bool,Node> searchPrevScope(std::string name)
    {
        Node retNode;
        std::pair<bool,Node> ret = std::pair<bool,Node>(false,retNode);
        //std::cout << "SEARCHING PREVIOUS SCOPE" << std::endl;
        currentLooker = currentScope;
        while (currentLooker != symbolTable.begin())
        {
            currentLooker--;
            //std::cout << "SEARCHING PREVIOUS SCOPE" << std::endl;
            ret = searchScope(name,currentLooker);
            if (ret.first)
                return ret;
        }
        return ret;
    }
    std::list <std::map<std::string,Node>> :: iterator getCurrentScope() {return currentScope;}
    //std::map<std::string,Node> :: iterator getCurrentPair() {return currentScope->rbegin();}
    std::map<std::string,Node>::reverse_iterator getCurrentEnd(){
        return currentScope->rend();
    }
    std::map<std::string,Node>::reverse_iterator getCurrentPair(){
        std::map<std::string,Node>::reverse_iterator ret = currentScope->rend();
        if (!currentScope->empty())
            return currentScope->rbegin();
        return ret;
    }
    Node * getLatestNode() {
        //pointer to last map
        std::map<std::string,Node> * currentScopeMap = &symbolTable.back();
        return &(currentScopeMap->rbegin()->second);
    }
};
