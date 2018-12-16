#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <iterator>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>

void initTable();
void freeReg(int reg);
int getRetReg(); //v0-v1 return vals
int getArgReg(); //a0-a3 1st four params of func call
int getTmpReg(); //t0-t9 temp reg no preserved
int getSaveReg(); //s0-s7 save regs vals preserved between func calls


//true if avail int for reg num
std::vector <std::pair<bool,int>> regTable;

void initTable() {
    for (int i = 0;i<32;i++) {
        std::pair <bool,int> tmp = std::pair<bool,int>(true,i);
        regTable.push_back(tmp);
    }
}

void freeReg(int reg) {
    std::pair <bool,int> tmp = std::pair<bool,int>(true,reg);
    regTable[reg] = tmp;
}

//$2-$3
int getRetReg(){ //v0-v1 return vals
    int i = 2;
    while (i !=4) {
        if(regTable[i].first){
            return i;
            i=4;
        }
        i++;
    }
    return -1;
}
//$4-$7
int getArgReg(){ //a0-a3 1st four params of func call
    int i = 4;
    while (i !=8) {
        if(regTable[i].first){
            return i;
            i=8;
        }
        i++;
    }
    return -1;
}
//$8-$15 & $24-$25
int getTmpReg(){ //t0-t9 temp reg no preserved
    int i = 8;
    while (i !=26) {
        if(regTable[i].first){
            return i;
            i=26;
        }
        i++;
        if (i ==16)
            i = 24;
    }
    return -1;
}

//$16-$23
int getSaveReg(){ //s0-s7 save regs vals preserved between func calls
    int i = 16;
    while (i !=24) {
        if(regTable[i].first){
            return i;
            i=24;
        }
        i++;
    }
    return -1;
}
