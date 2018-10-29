#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <list>
#include "../symbolTable.cpp"

std::string srcFile = "tests/input";
int lineNum = 42;
bool printSymbolNums=false;
using namespace std;

int main () {
    SymbolTable st;

    int sign1 = unsignedE; //unsigned
    int type1 = intS; //int
    string name1 = "my_var1";
    int line1 = 144;

    int type2 = charS; //char
    string name2 = "my_var2";
    int line2 = 1337;

    int type3 = charS; //char
    string name3 = "my_var3";
	int line3 = 145;

    int type4 = charS; //char
    string name4 = "my_var4";
    int line4 = 123;

    //function
    int type5 = intS;
    string name5 = "funcTest";
    int line5 = 350;

    // CREATE NODES
    Node a;
    Node b;
    Node c;
    Node d;
    Node f;

    a.setTypeSpec(type1);
    a.setSigned(sign1);
    a.setName(name1);
    a.setLine(line1);
    a.setScope(0);

    b.setTypeSpec(type2);
    b.setName(name2);
    b.setLine(line2);
    b.setScope(0);

    c.setTypeSpec(type3);
    c.setName(name3);
    c.setLine(line3);
    c.setScope(1);

    d.setTypeSpec(type4);
    d.setName(name4);
    d.setLine(line4);
    d.setScope(1);

    f.setTypeSpec(type5);
    f.setName(name5);
    f.setLine(line5);
    f.setScope(1);
    f.setFunction();
    f.addParam();
    f.addParamValue(signedPT,unsignedE);
    f.addParamValue(typeQualPT,volatileQ);
    f.addParamValue(typeSpecPT,intS);
    f.addParam();
    f.addParamValue(typeQualPT,constQ);
    f.addParamValue(typeSpecPT,charS);

    st.mode = insert;
    st.insertSymbol(a);
    st.insertSymbol(b);
    st.addNewScope();
    st.insertSymbol(c);
    st.insertSymbol(d);
    st.insertSymbol(f);
    st.mode = lookup;
    st.printST();
    //st.writeST("symbolTable.txt");
    return 0;
}
