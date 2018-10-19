#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>
#include "node.cpp"

using namespace std;

int main () {
    list<map<string,Node>> st;
    map <string,Node> map1;
    string type = "int";
    string name = "a";
    int value = 5;
    intVal n(type, name, value); 
    n.printNode();
    map1.insert(pair <string,Node> (n.name,n));
    st.push_back(map1);
    map <string,Node> testmap = st.back();
    

    return 0;
}
