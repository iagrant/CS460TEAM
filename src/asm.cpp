#include <iostream>
#include <string>
#include <vector>
#include <sstream>      // std::istringstream
#include <fstream>
#include "RegAlloc.cpp"

int tmpRegGetter(std::string input);
int argRegGetter(std::string input);
int retRegGetter(std::string input);
std::vector<std::string> asmCode;
extern std::vector<std::string> triACStruct;
extern std::string outSrcFile;
void parseStruct ();
void callOpHandle(std::vector<std::string> parsedLine);
void retOpHandle(std::vector<std::string> parsedLine);
void retLoadOpHandle(std::vector<std::string> parsedLine);
void argLoadOpHandle(std::vector<std::string> parsedLine);
void notHandle(std::vector<std::string> parsedLine);

void ltOpHandle(std::vector<std::string> parsedLine);
void gtOpHandle(std::vector<std::string> parsedLine);
void leOpHandle(std::vector<std::string> parsedLine);
void geOpHandle(std::vector<std::string> parsedLine);
void eqOpHandle(std::vector<std::string> parsedLine);
void neOpHandle(std::vector<std::string> parsedLine);
void andOpHandle(std::vector<std::string> parsedLine);
void orOpHandle(std::vector<std::string> parsedLine);
void xorOpHandle(std::vector<std::string> parsedLine);

void mathRHS(std::vector<std::string> parsedLine);
void beqOpHandle(std::vector<std::string> parsedLine);
void bneOpHandle(std::vector<std::string> parsedLine);
void operatorHandle(std::vector<std::string> parsedLine);
void labelOpHandle(std::vector<std::string> parsedLine);
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
void exprOpHandle(std::vector<std::string> parsedLine);
void brOpHandle(std::vector<std::string> parsedLine);
void prologHandle(std::vector<std::string> parsedLine);
void epilogHandle();
void printSrc(std::vector<std::string> parsedLine);
int getOffSet(std::vector<std::string> parsedLine);
std::vector<std::string> parseLine (std::string triACLine);
void printLine(std::string line);
void printASM();
std::list<int> actFrameStack;
int actSize = 0;
std::string tmpStr = "";
enum lastOpE {normie,mulie,divie,modie};
int lastOp = normie;

// Grab line from the 3Ac struct
std::list<std::vector<std::string>> lineStack;

void parseStruct ()
{
    initTable();
    std::vector<std::string> parsedLine;
    std::string triACLine;

    triACLine = triACStruct[0];
    parsedLine = parseLine(triACLine);
    int i = 0;
    if (parsedLine[0].front() != '#') {
        i++;
    }
    while (parsedLine[0].front() == '#') {
        triACLine = triACStruct[i];
        parsedLine = parseLine(triACLine);
        i++;
    }
    prologHandle(parsedLine);
    lineStack.push_front(parsedLine);
    tmpStr = "";
    //starts at 1 so i can steal main label
    // Slice the struct
    // Call parse line
    while (i < triACStruct.size())
    {
        triACLine = triACStruct[i];
        parsedLine = parseLine(triACLine);

        // Get the enum for the operator
        printSrc(parsedLine);
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
    }
    return parsedLine;
}

int getOffSet(std::vector<std::string> parsedLine) {
    actSize = actFrameStack.front();
    //return actSize-std::stoi(parsedLine[2]);
    return actSize-std::stoi(parsedLine[2])-4;
}

int tempRegGetter(std::string input) {
    std::string test = "";
    test.append(input);
    test.erase(0,3);
    int reg = getTmpReg(std::stoi(test));
    return reg;
}

int argRegGetter(std::string input) {
    std::string test = "";
    test.append(input);
    test.erase(0,3);
    int reg = getArgReg(std::stoi(test));
    return reg;
}
int retRegGetter(std::string input) {
    std::string test = "";
    test.append(input);
    test.erase(0,3);
    int reg = getRetReg(std::stoi(test));
    return reg;
}

void printSrc(std::vector<std::string> parsedLine) {
    tmpStr = "##";
    for (int i=0;i<parsedLine.size();i++) {
        tmpStr.append(parsedLine[i]);
        tmpStr.append("\t");
    }
    asmCode.push_back(tmpStr);
    tmpStr = "";
}

void operatorHandle(std::vector<std::string> parsedLine)
{
    if (parsedLine[0].compare("LOAD") == 0)
    {
        loadOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("STORE") == 0)
    {
        storeOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("ASSIGN") == 0)
    {
        assignHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("ADDR") == 0)
    {
        addrOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("ADD") == 0)
    {
        addOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("SUB") == 0)
    {
        subOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("MUL") == 0)
    {
        mulOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("DIV") == 0)
    {
        divOpHandle(parsedLine);
        lastOp = divie;
    }
    else if (parsedLine[0].compare("MOD") == 0)
    {
        modOpHandle(parsedLine);
        lastOp = modie;
    }
    else if (parsedLine[0].compare("##") == 0)
    {
        commentOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("BR") == 0)
    {
        brOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("BREQ") == 0)
    {
        beqOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("BNE") == 0)
    {
        bneOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("ARGLOAD") == 0)
    {
        argLoadOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("CALL") == 0)
    {
        callOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].back() == ':')
    {
        labelOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("LT") == 0) {
        ltOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("GT") == 0) {
        gtOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("GE") == 0) {
        geOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("LE") == 0) {
        leOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("EQ") == 0) {
        eqOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("NE") == 0) {
        neOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("AND") == 0) {
        andOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("OR") == 0) {
        orOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("XOR") == 0) {
        xorOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("RETLOAD") == 0) {
        retLoadOpHandle(parsedLine);
        lastOp = normie;
    }
    else if (parsedLine[0].compare("RET") == 0) {
        retOpHandle(parsedLine);
        lastOp = normie;
    }
    else
    {
        std::cout << parsedLine[0] << "THAT'S A NONO!" << std::endl;
        lastOp = normie;
    }
}
void retOpHandle(std::vector<std::string> parsedLine)
{
    epilogHandle();
    tmpStr.append("jr\t$31");
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void retLoadOpHandle(std::vector<std::string> parsedLine)
{
    int dst = retRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);
    tmpStr.append("move\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void callOpHandle(std::vector<std::string> parsedLine)
{
    tmpStr.append("jal\t");
    tmpStr.append(parsedLine[1]);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void argLoadOpHandle(std::vector<std::string> parsedLine)
{
    int dst = argRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);
    tmpStr.append("move\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void notHandle(std::vector<std::string> parsedLine){
    int dst = getTmpReg(-1);
    int src1 = tempRegGetter(parsedLine[1]);
    tmpStr.append("not\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void gtOpHandle(std::vector<std::string> parsedLine)
{
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("sgt\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void ltOpHandle(std::vector<std::string> parsedLine)
{
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("slt\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void geOpHandle(std::vector<std::string> parsedLine)
{
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("sge\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";

}
void leOpHandle(std::vector<std::string> parsedLine)
{
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("sle\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void eqOpHandle(std::vector<std::string> parsedLine){
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("seq\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}

void neOpHandle(std::vector<std::string> parsedLine){
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("sne\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void andOpHandle(std::vector<std::string> parsedLine){
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("and\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void orOpHandle(std::vector<std::string> parsedLine){
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("or\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void xorOpHandle(std::vector<std::string> parsedLine){
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("xor\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void exprOpHandle(std::vector<std::string> parsedLine)
{
    tmpStr.append(parsedLine[0]);
    if (parsedLine[3].front() == 'i') {
        int dst = tempRegGetter(parsedLine[1]);
        int src1 = tempRegGetter(parsedLine[2]);
        int src2 = tempRegGetter(parsedLine[3]);
        tmpStr.append("\t$");
        tmpStr.append(std::to_string(dst));
        tmpStr.append("\t$");
        tmpStr.append(std::to_string(src1));
        tmpStr.append("\t$");
        tmpStr.append(std::to_string(src2));
    }
    else {
        int dst = tempRegGetter(parsedLine[1]);
        int src1 = tempRegGetter(parsedLine[2]);
        tmpStr.append(std::to_string(dst));
        tmpStr.append("\t$");
        tmpStr.append(std::to_string(src1));
        tmpStr.append("\t");
        tmpStr.append(parsedLine[3]);
    }
    asmCode.push_back(tmpStr);
    tmpStr = "";
}

void loadOpHandle(std::vector<std::string> parsedLine)
{
    int reg = tempRegGetter(parsedLine[1]);
    if (parsedLine[2].front() == 'A') {
        parsedLine[2].erase(0,2);
        tmpStr = "lw\t$" + std::to_string(reg) + "\t" + std::to_string(getOffSet(parsedLine)) + "($sp)";
        asmCode.push_back(tmpStr);
        tmpStr = "";
    }
    else if (parsedLine[2].front() == '0'|| parsedLine[2].front() == 'O') {
        parsedLine[2].erase(0,5);
        parsedLine[2].pop_back();
        int reg1 = getTmpReg(std::stoi(parsedLine[2]));
        tmpStr = "lw\t$" + std::to_string(reg) + "\t0($" + std::to_string(reg1) + ")";
        asmCode.push_back(tmpStr);
        tmpStr = "";
    }
}
void storeOpHandle(std::vector<std::string> parsedLine)
{
    int reg = tempRegGetter(parsedLine[1]);
    if (parsedLine[2].front() == 'A') {
        parsedLine[2].erase(0,2);
        tmpStr = "sw\t$" + std::to_string(reg) + "\t" + std::to_string(getOffSet(parsedLine)) + "($sp)";
        asmCode.push_back(tmpStr);
        tmpStr = "";
    }
    else if (parsedLine[2].front() == '0' || parsedLine[2].front() == 'O') {
        parsedLine[2].erase(0,5);
        parsedLine[2].pop_back();
        int reg1 = getTmpReg(std::stoi(parsedLine[2]));
        tmpStr = "sw\t$" + std::to_string(reg) + "\t0($" + std::to_string(reg1) + ")";
        asmCode.push_back(tmpStr);
        tmpStr = "";
    }
}
void assignHandle(std::vector<std::string> parsedLine)
{
    int reg = tempRegGetter(parsedLine[1]);
    tmpStr = "li\t$" + std::to_string(reg);
    tmpStr.append("\t");
    tmpStr.append(parsedLine[2]); //FIXME idk if okay load int onto far right side
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void addrOpHandle(std::vector<std::string> parsedLine)
{
    tmpStr = "";
    int reg = tempRegGetter(parsedLine[1]);
    parsedLine[2].erase(0,2);
    tmpStr = "la\t$" + std::to_string(reg) + "\t" + std::to_string(getOffSet(parsedLine)) + "($sp)";
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void mathRHS(std::vector<std::string> parsedLine) {
    if (parsedLine[3].front() == 'i') {
        int src2 = tempRegGetter(parsedLine[3]);
        tmpStr.append("\t$");
        tmpStr.append(std::to_string(src2));
    }
    else { //constant
        tmpStr.append("\t");
        tmpStr.append(parsedLine[3]);
    }
}
void addOpHandle(std::vector<std::string> parsedLine)
{
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("add\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void subOpHandle(std::vector<std::string> parsedLine)
{
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("sub\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void mulOpHandle(std::vector<std::string> parsedLine)
{
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("mul\t$");
    tmpStr.append(std::to_string(dst));
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void divOpHandle(std::vector<std::string> parsedLine)
{
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("div\t$");
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";

    tmpStr.append("mflo\t$");
    tmpStr.append(std::to_string(dst));
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void modOpHandle(std::vector<std::string> parsedLine)
{
    int dst = tempRegGetter(parsedLine[1]);
    int src1 = tempRegGetter(parsedLine[2]);

    tmpStr.append("div\t$");
    tmpStr.append("\t$");
    tmpStr.append(std::to_string(src1));
    mathRHS(parsedLine);
    asmCode.push_back(tmpStr);
    tmpStr = "";

    tmpStr.append("mfhi\t$");
    tmpStr.append(std::to_string(dst));
    asmCode.push_back(tmpStr);
    tmpStr = "";
}
void commentOpHandle(std::vector<std::string> parsedLine)
{
    //important function don't delete
}
void brOpHandle(std::vector<std::string> parsedLine){
        tmpStr = "";
        tmpStr.append("j\t");
        tmpStr.append(parsedLine[1]);
        tmpStr.append("\t");
        asmCode.push_back(tmpStr);
        tmpStr = "";
}
void beqOpHandle(std::vector<std::string> parsedLine){
        int reg = tempRegGetter(parsedLine[1]);
        tmpStr = "";
        tmpStr.append("beq\t$");
        tmpStr.append(std::to_string(reg));
        tmpStr.append("\t");
        tmpStr.append(parsedLine[2]);
        tmpStr.append("\t");
        tmpStr.append(parsedLine[3]);
        asmCode.push_back(tmpStr);
        tmpStr = "";
}
void bneOpHandle(std::vector<std::string> parsedLine){
        int reg = tempRegGetter(parsedLine[1]);
        tmpStr = "";
        tmpStr.append("bne\t");
        tmpStr.append(std::to_string(reg));
        tmpStr.append(parsedLine[2]);
        tmpStr.append("\t");
        tmpStr.append(parsedLine[3]);
        asmCode.push_back(tmpStr);
        tmpStr = "";
}
void labelOpHandle(std::vector<std::string> parsedLine){
        tmpStr = "";
        for (int i = 0; i < parsedLine.size(); i++){
            tmpStr.append(parsedLine[i]);
            tmpStr.append("\t");
        }
        asmCode.push_back(tmpStr);
        tmpStr = "";
}
void prologHandle(std::vector<std::string> parsedLine) {
    tmpStr.append("##\t.globl\t"+parsedLine[0]);
    //std::cout << tmpStr << std::endl;
    asmCode.push_back(tmpStr);
    tmpStr = "";

    tmpStr.append("##\t.ent\t"+parsedLine[0]);
    //std::cout << tmpStr << std::endl;
    asmCode.push_back(tmpStr);
    tmpStr = "";

    tmpStr.append(parsedLine[0]+":");
    //std::cout << tmpStr << std::endl;
    asmCode.push_back(tmpStr);
    tmpStr = "";

    tmpStr.append("addiu\t$sp\t$sp\t");
    tmpStr.append("-"+parsedLine[1]);
    //std::cout << tmpStr << std::endl;
    asmCode.push_back(tmpStr);
    tmpStr = "";

    actSize=std::stoi(parsedLine[1]);
    actFrameStack.push_front(actSize);
    tmpStr.append("sw\t$31,"+std::to_string(actSize-4)+"($sp)"); //sub 4 cuz ret addr is 4 large
    //std::cout << tmpStr << std::endl;
    asmCode.push_back(tmpStr);
    tmpStr = "";
    //FIXME maybe come back later after investigating .mask thing

    //store any currently used save regs here

    asmCode.push_back(tmpStr);
    tmpStr = "";
    //std::cout << std::endl;
}
void epilogHandle() {
    //after done with func call
    tmpStr = "";
    actSize = actFrameStack.front();
    tmpStr.append("addiu\t$sp\t$sp\t");
    tmpStr.append(std::to_string(actSize));
    asmCode.push_back(tmpStr);
    tmpStr = "";
    actFrameStack.pop_front();
    if (actFrameStack.size() == 0){
        tmpStr.append("exit:");
        asmCode.push_back(tmpStr);
        tmpStr = "";
        tmpStr.append("li\t$v0\t10\t# terminate program run and");
        asmCode.push_back(tmpStr);
        tmpStr = "";
        tmpStr.append("syscall\t# Exit");
        asmCode.push_back(tmpStr);
        tmpStr = "";
    }
}

void printASM() {
    //std::ofstream fileP(filename,std::ios::app);
    std::ofstream fileP("output/output.s");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(fileP.rdbuf()); //changes cout to print to file stream
    std::string buff = ""; //it's a strong string :)
    for (int i =0; i < asmCode.size(); i++) {
        buff = asmCode[i];
        std::cout << buff << std::endl;
    }
    fileP.close();
    std::cout.rdbuf(coutbuf); //resets cout to stdout
    if (debug) {
        for (int i =0; i < asmCode.size(); i++) {
            buff = asmCode[i];
            std::cout << buff << std::endl;
        }
    }
}
