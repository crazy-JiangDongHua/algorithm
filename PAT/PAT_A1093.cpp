#include <cstdio>
#include <cstring>

const int M = 1000000007;
const int MAXLEN = 10e5 + 10;
char str[MAXLEN];
int pcnt[MAXLEN];

int main()
{
	scanf("%s", str);
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i] == 'P')
			pcnt[i] = 1;
		if(i>0)
			pcnt[i] += pcnt[i-1];
	}
	int res = 0;
	int tcnt= 0;
	for(int i=len-1;i>0;i--)
	{
		if(str[i]=='A')
			res = (res + pcnt[i-1]*tcnt%M) % M;
		else if(str[i]=='T')
			tcnt++; 
	}
	printf("%d\n",res);
	return 0;
}
