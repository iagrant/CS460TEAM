#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <list>
#include "node.cpp"

using namespace std;

int main () {

    list<map<string,Node>> st;
    list<map<string,Node>> :: iterator it;
    map <string,Node> map1;
    map <string,Node> map2;

    // NODE TESTING
    string type1 = "int";
    string name1 = "my_var1";
    int int_value = 5;

    string type2 = "string";
    string name2 = "my_var2";
    string str_value = "Hollo";

    string type3 = "double";
    string name3 = "my_var3";
    double dbl_value = 3.1;

    string type4 = "char";
    string name4 = "my_var4";
    char chr_value = 'a';

    // CREATE NODES
    intVal a(type1, name1, int_value); 
    stringVal b(type2, name2, str_value); 
    doubleVal c(type3, name3, dbl_value); 
    charVal d(type4, name4, chr_value); 

    // OUTPUT CONTENTS OF NODES
    cout << "OUTPUT CONTENTS OF NODES" << endl;
    a.printNode();
    b.printNode();
    c.printNode();
    d.printNode();

    map1.insert(pair <string,Node> (a.name,a));
    map1.insert(pair <string,Node> (b.name,b));

    map2.insert(pair <string,Node> (c.name,c));
    map2.insert(pair <string,Node> (d.name,d));

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
    return 0;
}
