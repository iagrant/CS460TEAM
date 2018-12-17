#include <iostream>
#include <string>
#include <vector>
#include <sstream>      // std::istringstream

#include "RegAlloc.cpp"

std::vector<std::string> asmCode;
extern std::vector<std::string> triACStruct;
extern std::string outSrcFile;
void parseStruct ();
std::vector<std::string> parseLine (std::string triACLine);
void operatorHandle(std::vector<std::string> parsedLine);
void loadOpHandle(std::vector<std::string> parsedLine);
void storeOpHandle(std::vector<std::string> parsedLine);
void assignHandle(std::vector<std::string> parsedLine);
void addrOpHandle(std::vector<std::string> parsedLine);
void addOpHandle(std::vector<std::string> parsedLine);
void subOpHandle(std::vector<std::string> parsedLine);
void mulOpHandle(std::vector<std::string> parsedLine);
void divOpHandle(std::vector<std::string> parsedLine);
void modOpHandle(std::vector<std::string> parsedLine);
void commentOpHandle(std::vector<std::string> parsedLine);
void prologHandle(std::vector<std::string> parsedLine);
void epilogHandle(std::vector<std::string> parsedLine);
void printLine(std::string line);
int actSize;

// Grab line from the 3Ac struct
std::list<std::vector<std::string>> lineStack;

void parseStruct ()
{
    initTable();
    std::cout << "\n##ASM CODE BELOW\n" << std::endl;
    std::vector<std::string> parsedLine;
    std::string triACLine;

    triACLine = triACStruct[0];
    parsedLine = parseLine(triACLine);
    prologHandle(parsedLine);
    lineStack.push_front(parsedLine);
    //starts at 1 so i can steal main label
    int i = 1;
    // Slice the struct
    // Call parse line
    while (i < triACStruct.size())
    {
        triACLine = triACStruct[i];
        parsedLine = parseLine(triACLine);

        // Get the enum for the operator
        operatorHandle(parsedLine);
        i++;
    }
    //parsedLine = lineStack.front();
    //lineStack.pop_front();
    //epilogHandle(parsedLine);
}


// Split the 3AC line into sub-strings
std::vector<std::string> parseLine (std::string triACLine)
{
    std::vector<std::string> parsedLine;
    std::string subString;
	std::istringstream ss(triACLine);

    // Grab each part of the line and push into a vector
    while(std::getline(ss, subString, '\t')) {
        parsedLine.push_back(subString);
    }
    return parsedLine;
}


int tempRegGetter(std::string input) {
    std::string test = "";
    test.append(input);
    test.erase(0,3);
    int reg = getTmpReg(std::stoi(test));
    return reg;
}

void operatorHandle(std::vector<std::string> parsedLine)
{
    if (parsedLine[0].compare("LOAD") == 0)
    {
        loadOpHandle(parsedLine);
    }
    else if (parsedLine[0].compare("STORE") == 0)
    {
        storeOpHandle(parsedLine);
    }
    else if (parsedLine[0].compare("ASSIGN") == 0)
    {
        assignHandle(parsedLine);
    }
    else if (parsedLine[0].compare("ADDR") == 0)
    {
        addrOpHandle(parsedLine);
    }
    else if (parsedLine[0].compare("ADD") == 0)
    {
        addOpHandle(parsedLine);
    }
    else if (parsedLine[0].compare("SUB") == 0)
    {
        subOpHandle(parsedLine);
    }
    else if (parsedLine[0].compare("MUL") == 0)
    {
        mulOpHandle(parsedLine);
    }
    else if (parsedLine[0].compare("DIV") == 0)
    {
        divOpHandle(parsedLine);
    }
    else if (parsedLine[0].compare("MOD") == 0)
    {
        modOpHandle(parsedLine);
    }
    else if (parsedLine[0].compare("##") == 0)
    {
        commentOpHandle(parsedLine);
    }
    else
    {
        //labels
        //std::cout << parsedLine[0] << " OP NOT INCLUDED YET" << std::endl;
    }
}


void loadOpHandle(std::vector<std::string> parsedLine)
{
    tempString = "";
    int reg = tempRegGetter(parsedLine[1]);
    parsedLine[2].erase(0,2);
    //tempString.append("li\t"+"$"+reg+"\t"+parsedLine[2]+"($sp)");
}
void storeOpHandle(std::vector<std::string> parsedLine)
{
    int reg = tempRegGetter(parsedLine[1]);
    parsedLine[2].erase(0,2);
    std::cout << "sw\t" << "$" << reg << "\t" << actSize-std::stoi(parsedLine[2])-4 << "($sp)" << std::endl;
}
void assignHandle(std::vector<std::string> parsedLine)
{
    int reg = tempRegGetter(parsedLine[1]);
    std::cout << "li\t" << "$" << reg << "\t" << parsedLine[2] << std::endl;
}
void addrOpHandle(std::vector<std::string> parsedLine)
{
    std::cout << "la\t" << "dst\toffset($sp)" << std::endl;
}
void addOpHandle(std::vector<std::string> parsedLine)
{
    std::cout << "addu\t" << "dest\top1\top2" << std::endl;
}
void subOpHandle(std::vector<std::string> parsedLine)
{
    std::cout << "subu\t" << "dest\top1\top2" << std::endl;
}
void mulOpHandle(std::vector<std::string> parsedLine)
{
    std::cout << "mult\t" << "op1\top2" << std::endl;
    std::cout << "mflo\t" << "dest" << std::endl;
}
void divOpHandle(std::vector<std::string> parsedLine)
{
    std::cout << "div\t" << "dest\top1\top2" << std::endl;
    std::cout << "mfhi\t" << "dest" << std::endl;
    std::cout << "mflo\t" << "dest" << std::endl;

}
void modOpHandle(std::vector<std::string> parsedLine)
{

}
void commentOpHandle(std::vector<std::string> parsedLine)
{

}
void prologHandle(std::vector<std::string> parsedLine) {
    tempString.append("##\t.globl\t"+parsedLine[0]);
    std::cout << tempString << std::endl;
    asmCode.push_back(tempString);
    tempString = "";

    tempString.append("##\t.ent\t"+parsedLine[0]);
    std::cout << tempString << std::endl;
    asmCode.push_back(tempString);
    tempString = "";

    tempString.append(parsedLine[0]+":");
    std::cout << tempString << std::endl;
    asmCode.push_back(tempString);
    tempString = "";

    tempString.append("subu\t$sp,"+parsedLine[1]);
    std::cout << tempString << std::endl;
    asmCode.push_back(tempString);
    tempString = "";

    actSize=std::stoi(parsedLine[1]);
    tempString.append("sw\t$31,"+std::to_string(actSize-4)+"($sp)"); //sub 4 cuz ret addr is 4 large
    std::cout << tempString << std::endl;
    asmCode.push_back(tempString);
    tempString = "";
    //FIXME maybe come back later after investigating .mask thing

    //store any currently used save regs here

    asmCode.push_back(tempString);
    tempString = "";
    std::cout << std::endl;
}

/* who wrote this broken code?
void printLine(std::string line)
{
    std::ofstream fout;
    fout.open(outSrcFile, ios:app);
    fout << line << std::endl;
    fout.close();
}
*/
