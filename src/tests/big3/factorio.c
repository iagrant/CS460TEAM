void printInt(int in);
int fact(int i);
int main()
{
    int a = 5;
    printInt(a);
    a = fact(a);
    printInt(a);
    return 0;
}
int fact(int i) {
    int t = fact(i-1);
    return i+t;
}
