#include <cstdio> 
char words[80][80];
int main()
{
	int cnt=0;
	while(scanf("%s",words[cnt])!=-1)
		cnt++;
	while(cnt--)
	{
		printf("%s",words[cnt]);
		if(cnt!=0)
			printf(" ");
	}
	return 0;
}
