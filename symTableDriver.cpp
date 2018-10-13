#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "symbolTable.cpp"

using namespace std;

int main () {

    string type = "int";
    int value = 5;
    intVal n(type, value); 
    n.printNode();
    return 0;
}
