#include <cstdio>
#include <cmath>
int main()
{
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int col = n, row = round((double)(n)/2);
	for(int i=0;i<row;i++)
	{
		if(i == 0)
		{
			for(int j=0;j<col;j++)
			{
				printf("%c", c);
			}
			printf("\n");
		}
		else if(i == row-1)
		{
			for(int j=0;j<col;j++)
			{
				printf("%c", c);
			}
		}
		else
		{
			printf("%c", c);
			for(int j=0;j<col-2;j++)
			{
				printf(" ");
			}
			printf("%c\n", c);
		}
	}
	return 0;
} 
