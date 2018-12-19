void printInt(int a);
void printNewLine();

int main ()
{
    int a[4];
    int i;
    for (i = 0; i < 4; i++)
    {
        a[i] = 4 - i;
        printInt(a[i]);
    }
    return 0;
}
