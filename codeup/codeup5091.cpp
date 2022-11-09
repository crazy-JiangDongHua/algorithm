// 回文串 
#include <cstdio>
#include <cstring>
int main()
{
	char str[256];
	while(scanf("%s",str)!=-1)
	{
		int len = strlen(str)-1, i=0;
		while(i<len)
		{
			if(str[len] != str[i])
			{
				printf("NO\n");
				break;	
			}
			len--,i++;
		}
		if(i>=len)
			printf("YES\n");
	}
	return 0;
}
