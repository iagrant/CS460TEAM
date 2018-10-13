#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "node.cpp"

using namespace std;

int main () {

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
    a.printNode();
    b.printNode();
    c.printNode();
    d.printNode();


    return 0;
}
