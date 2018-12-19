void printInt(int a);
int main(){
    int a = 3;
    int b = 4;
    char c = 'c';
    for (a = 0; a < 3; a++) {
            printInt(a);
        for (b = 0; b < 5; b++) {
            printInt(b);
        }
    }
        for (a = 0; a < 5; a++) {
            printInt(a);
        }
    return 0;
}
