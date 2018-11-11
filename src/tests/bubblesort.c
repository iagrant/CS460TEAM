//
// Created by Clayton Franklin on 8/27/18.
//
//#include <stdio.h>

int main ()
{
	int array[10] = {1, 4, 5, 2, 8, 12, 3, 97, 14, 9};
	int i,j,k,l;

	for (i = 0; i < 9; i++)
	{
        i=10;
	}

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
                !!ds
			}
		}
	}

	for (l = 0; l < 9; l++)
	{
        l = 10;
	}

}
