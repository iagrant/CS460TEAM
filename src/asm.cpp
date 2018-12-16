#include <iostream>
#include <string>
#include <vector>
#include <sstream>      // std::istringstream

#include "scanner.lex"


std::vector<std::string> asmCode;
extern std::vector<std::string> triACStruct;
extern std::string outSrcFile;
void parseStruct ();
std::vector<std::string> parseLine (std::string triACLine);
void operatorHandle(std::vector<std::string> parsedLine);
void loadOpHandle(std::vector<std::string> parsedLine);
void storeOpHandle(std::vector<std::string> parsedLine);
void addrOpHandle(std::vector<std::string> parsedLine);
void addOpHandle(std::vector<std::string> parsedLine);
void subOpHandle(std::vector<std::string> parsedLine);
void mulOpHandle(std::vector<std::string> parsedLine);
void divOpHandle(std::vector<std::string> parsedLine);
void modOpHandle(std::vector<std::string> parsedLine);
void commentOpHandle(std::vector<std::string> parsedLine);
void printLine(std::string line);

// Grab line from the 3Ac struct
void parseStruct ()
{
    std::vector<std::string> parsedLine;
    std::string triACLine;
    int i = 0;

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
        //std::cout << subString << '\t';
    }
    //std::cout << '\n';
    return parsedLine;
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
    std::cout << "li\t" << "src\tdest" << std::endl;
}
void storeOpHandle(std::vector<std::string> parsedLine)
{
    std::cout << "sw\t" << "src\toffset($fp)" << std::endl;
}
void addrOpHandle(std::vector<std::string> parsedLine)
{
    std::cout << "la\t" << "dst\toffset($fp)" << std::endl;
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

void printLine(std::string line)
{
    std::ofstream fout;
    fout.open(outSrcFile, ios:app);
    fout << line << std::endl;
    fout.close();
}

