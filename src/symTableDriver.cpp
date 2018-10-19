#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <list>
#include "symbolTable.cpp"

extern int mode;
std::string srcFile = "tests/input";
int lineNum = 42;
using namespace std;

int main () {
    SymbolTable st;

    int sign1 = 1; //unsigned
    int type1 = 3; //int
    string name1 = "my_var1";
    int line1 = 144;

    int type2 = 2; //char
    string name2 = "my_var2";
    int line2 = 1337;

    int type3 = 1; //char
    string name3 = "my_var3";
	int line3 = 145;

    int type4 = 1; //char
    string name4 = "my_var4";
    int line4 = 123;

    // SHADOWING TEST
    int type0 = 3; //int
    string name0 = "my_var1";
    int line0 = 244;

    std::cout << "BEFORE NODES"<< std::endl;
    // CREATE NODES
    Node a;
    Node b;
    Node c;
    Node d;
    Node z;

    a.setTypeSpec(type1);
    a.setSigned(sign1);
    a.setName(name1);
    a.setLine(line1);

    b.setTypeSpec(type2);
    b.setName(name2);
    b.setLine(line2);

    c.setTypeSpec(type3);
    c.setName(name3);
    c.setLine(line3);

    d.setTypeSpec(type4);
    d.setName(name4);
    d.setLine(line4);

    z.setTypeSpec(type0);
    z.setName(name0);
    z.setLine(line0);

    std::cout << "ENTERING INSERT MODE"<< std::endl;
    mode = insert;
    std::cout << "AFTER NODES"<< std::endl;
    st.insertSymbol(a);
    std::cout << "INSERT NODES"<< std::endl;
    st.insertSymbol(b);
    std::cout << "NEW SCOPE"<< std::endl;
    st.addNewScope();
    std::cout << "INSERT NODES"<< std::endl;
    st.insertSymbol(c);
    st.insertSymbol(z);
    st.insertSymbol(d);
    std::cout << "PRINT ST"<< std::endl;
    mode = lookup;
    st.searchTree(z);
    st.printST();
    //st.writeST("out.txt");



    /*
    list<map<string,Node>> st;
    list<map<string,Node>> :: iterator it;
    map <string,Node> map1;
    map <string,Node> map2;

    // NODE TESTING
    string type1 = "int";
    string name1 = "my_var1";
    int line1 = 144;

    string type2 = "string";
    string name2 = "my_var2";
    int line2 = 1337;

    string type3 = "double";
    string name3 = "my_var3";
	  int line3 = 145;

    string type4 = "char";
    string name4 = "my_var4";
    int line4 = 123;


    // CREATE NODES
    Node a(type1, name1, line1);
    Node b(type2, name2, line2);
    Node c(type3, name3, line3);
    Node d(type4, name4, line4);

    // OUTPUT CONTENTS OF NODES
    cout << "OUTPUT CONTENTS OF NODES" << endl;
    a.printNode();
    b.printNode();
    c.printNode();
    d.printNode();

    // Insert Nodes into map1
    map1.insert(pair <string,Node> (a.name,a));
    map1.insert(pair <string,Node> (b.name,b));

    // Insert Nodes into map2
    map2.insert(pair <string,Node> (c.name,c));
    map2.insert(pair <string,Node> (d.name,d));

    // Insert maps into the symbol table
    st.push_back(map1);
    st.push_back(map2);

    cout << "OUTPUT CONTENTS OF LIST" << endl;
    for (it = st.begin(); it != st.end(); ++it)
    {
      map<string,Node> m = *it;
      cout << "OUTPUT CONTENTS OF MAP" << endl;
      for (map<string,Node> :: iterator iter = m.begin(); iter != m.end(); iter++)
      {
        cout << "TEST" << endl;
        Node n = iter->second;
        n.printNode();
      }
    }
    */
    return 0;
}
