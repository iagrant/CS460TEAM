void printInt(int a);
void printNewLine();

int main ()
{
	int array[1000];
    int i;
    int j;
    int l;
    int k;
	int temp = 0;

	for (i = 0; i < 100; i++)
	{
        array[i] = 100 - i;
        printInt(array[i]);
	}
    printNewLine();
	for (j = 0; j < 99; j++)
	{
	    for (k = 0; k < 99; k++)
        {
            if ( array[k] > array[k + 1] )
            {
                temp = array[k + 1];
                array[k + 1] = array[k];
                array[k] = temp;
            }
        }

	}

	for (l = 0; l < 100; l++)
	{
        printInt(array[l]);
	}
    printNewLine();
    return 0;
}
