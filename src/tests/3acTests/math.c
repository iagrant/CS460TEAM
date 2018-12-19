void printInt(int a);
int main(){
    int a = 5;
    printInt(a);
    int h = 4 + a;
    printInt(h);
    int b = a + 4;
    printInt(b);
    int c = 5;
    printInt(c);
    int d = a + 5 - 3;
    printInt(d);
    int e = 10 % 5;
    printInt(e);
    int f = a + b - c * d / e;
    printInt(f);
    a++;
    a--;
    return 0;
}
