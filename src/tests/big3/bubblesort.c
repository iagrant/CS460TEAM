void printInt(int a);
void printNewLine();

int main ()
{
    int i;
	int array[10];
	int array1[10];
    int j;
    int l;
    int k;
	int temp = 0;

	for (i = 0; i < 10; i++)
	{
        array[i] = 10 - i;
        printInt(array[i]);
	}
    printNewLine();

	for (j = 0; j < 9; j++)
	{
		for (k = 0; k < 9; k++ )
		{
			if ( array[k] > array[k + 1] )
			{
				temp = array[k + 1];
				array[k + 1] = array[k];
				array[k] = temp;
			}
		}
	}

	for (l = 0; l < 10; l++)
	{
        printInt(array[l]);
	}
    printNewLine();
    return 0;
}
