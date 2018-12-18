void printInt(int a);
void printNewLine();

int main ()
{
	int array[10];
    int i;
    int j;
    int l;
    int k;

	for (i = 0; i < 9; i++)
	{
        array[i] = 10 - i;
        printInt(array[i]);
	}
    printNewLine();

	for (j = 0; j < 8; j++)
	{
		for (k = 0; k < 8; k++ )
		{
			if ( array[k] > array[k + 1] )
			{
				int temp = 0;
				temp = array[k + 1];
				array[k + 1] = array[k];
				array[k] = temp;
			}
		}
	}

	for (l = 0; l < 9; l++)
	{
        printInt(array[l]);
	}
    printNewLine();
    return 0;
}
