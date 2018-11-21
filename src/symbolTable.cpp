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
#include <fstream>
#include "node.cpp"

enum modeE {lookup,insert};

extern int lineNum;
extern int tabNum;
extern int colNum;
extern bool buildingFunction;
extern std::string srcFile;

class SymbolTable {

  private:
    std::list<std::map<std::string,Node>> symbolTable;
    std::list <std::map<std::string,Node>> :: iterator currentLooker;
    std::list <std::map<std::string,Node>> :: iterator currentScope;
    int currentScopeNum = 0;
    int mode = lookup;
  public:
    bool proto = true;
    std::pair<std::string,int> lastId = std::pair<std::string,int> ("",-1);
    std::pair<std::string,int> lastFunc = std::pair<std::string,int> ("",-1);

    //Default Constructor
    SymbolTable () {
        std::map <std::string,Node> scope0;
        symbolTable.push_back(scope0);
        currentScope = symbolTable.begin();
    }
    // removeScope
    // returns a tree from the top of the stack
    std::map<std::string,Node> removeScope () {
        std::map<std::string,Node> ret = symbolTable.back();
        symbolTable.pop_back();
        currentScope--;
        currentScopeNum--;
        return ret;
    }
    // addNewScope
    // puts a tree on the top of the stack
    void addNewScope () {
        //std::cout << "NEW SCOPE AT LINE: " << lineNum << std::endl;
        std::map <std::string,Node> newScope;
        symbolTable.push_back(newScope);
        currentScope++;
        currentScopeNum++;
        //mode = insert;
    }

    void insertSymbol (Node symbol) {
        if (mode == insert) {
            bool protoFound = false; //so protos don't falsely trigger a redecl or shadow msg
            //the result of top level gets stored in pair
            //cuz only redecl matters for insertion
            //the pair is of a bool if found or not and a pointer to said node or null if not found
            std::pair<bool,Node*> searchTop = searchTopLevel(symbol.getName(),false); //search top level for just redecls
            //search previous scopes for shadowing
            std::pair<bool,Node*> searchPrevRes = searchPrevScope(symbol.getName(),false);
            //if searchRes.first is false then it didn't find the symbol in current scope
            if (searchTop.first)
                if (searchTop.second->hasProto){
                    searchTop.second->setImplementation();
                    protoFound = true;
                    lastId.first = symbol.getName();
                    lastId.second = symbol.getLine();
                }

            if (searchTop.first && !protoFound) //if true it a redecl and that a nono
            {
                std::cout << "\e[31;1m ERROR: \e[0m Redifinition of Variable: " << searchTop.second->getName() << " previous declaration on line " << searchTop.second->getLine() << std::endl;
                printError();
                exit(1);
            }
            if (searchPrevRes.first && !protoFound) //shadowing found if true
            {
                std::cout << "\e[33;1m WARNING: \e[0m Shadowing of Variable: " << searchPrevRes.second->getName() << " previous declaration on line " << searchPrevRes.second->getLine() << std::endl;
                printError();
            }
            if (!searchTop.first) { //a okay to insert cuz not a redecl
                currentScope->insert(std::pair <std::string,Node> (symbol.getName(), symbol));
                lastId.first = symbol.getName();
                lastId.second = symbol.getLine();
            }
        }
        else {
            std::cout << "INSERTING SYMBOL IN LOOKUP MODE" << std::endl;
            std::cout << "THAT'S A NONO!!" << std::endl;
            std::cout << "HOW'D YOU GET HERE?" << std::endl;
            exit(1);
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

    void setMode(int modeIn) {mode = modeIn;}
    int getMode() {return mode;}

    int getCurrentScope() {return currentScopeNum;}

    /*
    std::map<std::string,Node>::reverse_iterator getCurrentEnd(){return currentScope->rend();}
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
    */

    std::pair<bool,Node*>searchTree (std::string name, bool ASTInsert){
        std::pair<bool,Node*> ret = std::pair<bool,Node*>(false,NULL);
        std::pair<bool,Node*> top = searchTopLevel(name,ASTInsert);
        std::pair<bool,Node*> all = searchPrevScope(name,ASTInsert);
        if (top.first) {
            //std::cout << "TOP LEVEL TEST" << name << std::endl;
            return top;
        }
        if (all.first){
            //std::cout << "PREV SCOPE TEST" << name << std::endl;
            return all;
        }
        if (mode==lookup && !ASTInsert){
            std::cout << "\e[31;1m ERROR: \e[0m No declaration of Variable: " << name << std::endl;
            printError();
            exit(1);
        }
        return ret;
    }

    std::pair<bool,Node*> searchTopLevel (std::string name,bool ASTInsert) {
        return searchScope(name,currentScope,ASTInsert); //searches top level scope which is currentScope
    }

    //searches past scopes for symbols
    std::pair<bool,Node*> searchPrevScope(std::string name,bool ASTInsert){
        std::pair<bool,Node*> ret = std::pair<bool,Node*>(false,NULL);
        currentLooker = currentScope;
        while (currentLooker != symbolTable.begin()){
            currentLooker--;
            ret = searchScope(name,currentLooker,ASTInsert);
            if (ret.first)
                return ret;
        }
        return ret;
    }
    std::pair<bool,Node*> searchScope (std::string name, std::list <std::map<std::string,Node>> :: iterator searchWindow,bool ASTInsert){
        std::pair<bool,Node*> ret = std::pair<bool,Node*>(false,NULL);
        //if (mode == insert && !ASTInsert){
            /*
			for(std::map<std::string,Node> :: iterator iter = searchWindow->begin(); iter != searchWindow->end(); iter++)
			{
            */
            //node is 2nd in map pair
            if (searchWindow->find(name) == searchWindow->end()){
                //std::cout << "DID NOT FIND: " << name << std::endl;
                return ret;
            }
            ret.first=true; //got this far it is found
            Node * treeNode = &(searchWindow->find(name)->second);
            ret.second=treeNode;
            //function proto block
			//}
            return ret;
        //}
        /*
		else if (mode == lookup)
		{
			for(std::map<std::string,Node> :: iterator iter = searchWindow->begin(); iter != searchWindow->end(); iter++)
			{
                //node is 2nd in map pair
                Node * treeNode = &(iter->second);
				if (treeNode->getName().compare(name)==0)
                {
                    ret.first = true;
                    ret.second = treeNode;
					return ret;
                }
            }
		}
        */
      	return ret;
    }

};
