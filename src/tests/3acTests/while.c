void printInt(int a);
void printNewLine();

int main(){
    int b = 4;
    int c = 3;
    while (b < 5) {
        c = 122;
        printInt(c);
        while (c < 6) {
            c = 121;
            printInt(c);
        }
        printNewLine();
    }
    while (c < 6) {
        c = 121;
        printInt(c);
    }
    printNewLine();

}
