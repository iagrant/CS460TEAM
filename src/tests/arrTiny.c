void printInt(int a);
void printNewLine();

int main ()
{
    int i;
    int j;
    int l;
    int k;
	int temp = 0;
	int array[3];

	for (i = 0; i < 3; i++)
	{
        array[i] = 3 - i;
        printInt(array[i]);
	}
    printNewLine();
	for (i = 2; i >= 0; i--)
	{
        printInt(array[i]);
	}
    printNewLine();
    return 0;
}
