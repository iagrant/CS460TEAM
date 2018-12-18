#include <stdio.h>
#include <string.h>
#include <vector>
#include <tuple>
#include <list>
#include <iterator>
#include <cstring>
#include <stdlib.h>
#include <iostream>
#include <fstream>

void initTable();
void freeReg(int reg);
int getRetReg(int temp); //v0-v1 return vals
int getArgReg(int temp); //a0-a3 1st four params of func call
int getTmpReg(int temp); //t0-t9 temp reg no preserved
int getSaveReg(int temp); //s0-s7 save regs vals preserved between func calls


//true if avail | reg num | temp num
std::vector <std::pair<int,int>> regTable;

void initTable() {
    for (int i = 0;i<32;i++) {
        std::pair <int,int> tmp = std::pair<int,int>(i,-1);
        regTable.push_back(tmp);
    }
}
void printTable() {
    for (int i = 0;i<32;i++) {
        std::pair <int,int> tmp = regTable[i];
        std::cout << tmp.first << " " << tmp.second << std::endl;
    }
}

void freeReg(int reg) {
    std::pair <int,int> tmp = std::pair<int,int>(reg,-1);
    regTable[reg] = tmp;
}

//$2-$3
int getRetReg(int temp){ //v0-v1 return vals
    int i = 2;
    while (i !=4) {
        if(regTable[i].second == temp){
            regTable[i].second = temp;
            freeReg(i);
            return i;
            i=4;
        }
        i++;
    }
    i = 2;
    while (i !=4) {
        if(regTable[i].second != -1){
            regTable[i].second = temp;
            return i;
            i=4;
        }
        i++;
    }
    return -1;
}
//$4-$7
int getArgReg(int temp){ //a0-a3 1st four params of func call
    int i = 4;
    while (i !=8) {
        if(regTable[i].second == temp){
            regTable[i].second = temp;
            freeReg(i);
            return i;
            i=8;
        }
        i++;
    }
    i = 4;
    while (i !=8) {
        if(std::get<1>(regTable[i])){
            regTable[i].second = temp;
            return i;
            i=8;
        }
        i++;
    }
    return -1;
}
//$8-$15 & $24-$25
int getTmpReg(int temp){ //t0-t9 temp reg no preserved
    int i = 8;
    while (i !=26) {
        if(regTable[i].second == temp ){
            regTable[i].second = temp;
            freeReg(i);
            return i;
            i=26;
        }
        i++;
        if (i ==16)
            i = 24;
    }
    i = 8;

    while (i !=26) {
        if(regTable[i].second == -1){
            regTable[i].second = temp;
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
int getSaveReg(int temp){ //s0-s7 save regs vals preserved between func calls
    int i = 16;
    while (i !=24) {
        if(regTable[i].second == temp ){
            regTable[i].second = temp;
            freeReg(i);
            return i;
            i=24;
        }
        i++;
    }
    i = 16;
    while (i !=24) {
        if(std::get<1>(regTable[i])){
            regTable[i].second = temp;
            return i;
            i=24;
        }
        i++;
    }
    return -1;
}
