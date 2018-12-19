void printInt(int a);
int main(){
    int a = 5;
    int h = 4 + a;
    int b = a + 4;
    int c = 5;
    int d = a + 5 - 3;
    int e = 5 % 10;
    int f = 2 * a + 3 * b - 5 * c * d / e;
    printInt(a);
    printInt(h);
    printInt(b);
    printInt(c);
    printInt(d);
    printInt(e);
    printInt(f);
    a++;
    a--;
    return 0;
}
