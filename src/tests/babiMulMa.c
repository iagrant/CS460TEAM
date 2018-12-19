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
    return 0;
}
