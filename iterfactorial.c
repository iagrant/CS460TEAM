//
// Created by Clayton Franklin on 8/28/18.
//

//#include <stdio.h>

int main(void)
{
	int fact = 0;
	int result = 1;
	int i;

	printf("Enter a whole number: ");
	scanf("%d",&fact);

	if(fact < 0)
	{
		printf("Cannot take the factorial of a negative number.\n");
	}

	while (fact < 0)
	{
			printf("Enter a whole number: ");
			scanf("%d",&fact);

		if(fact < 0)
		{
			printf("Cannot take the factorial of a negative number.\n");
		}
	}

	for (i = 1; i <= fact; i++)
	{
		result += i;
	}

		printf("The factorial of %d is %d.",fact,result);

	return 0;
}
