void printInt(int a);
void printNewLine();

int main()
{
	int i;
	int j;
	int k;
	int l;
	int m;
	int n;

	int x;
	int y;
	int z;
	int b;
	int A[2][2];
	int B[2][2];
	int AB[2][2];

	//initialize Matrix A
	b = 1;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			A[i][j] = b;
			b++;
			printInt(A[i][j]);
		}
		printNewLine();
	}
	//intilize Matrix B
	b = 4;
	for (k = 0; k < 2; k++)
	{
		for (l = 0; l < 2; l++)
		{
			B[k][l] = b;
			b--;
			printInt(B[k][l]);
		}
		printNewLine();
	}
	//initialize Matrix AB
	for (m = 0; m < 2; m++)
	{
		for (n = 0; n < 2; n++)
		{
			AB[m][n] = 0;
			printInt(AB[m][n]);
		}
		printNewLine();
	}
	//Perform Matrix Multiplication
	for (x = 0; x < 2; x++)
	{
		for (y = 0; y < 2; y++)
		{
			for (z = 0; z < 2; z++)
			{
				AB[x][y] = AB[x][y] + A[x][z] * B[z][y];
			    printInt(AB[x][y]);
			}
		printNewLine();
		}
		printNewLine();
	}

	return 0;
}
