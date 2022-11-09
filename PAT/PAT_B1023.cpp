#include <cstdio>
#include <cstring>

int main()
{
	int cnt[10], temp=0;
	memset(cnt, 0, sizeof(cnt));
	for(int i=0;i<10;i++)
	{
		scanf("%d", cnt+i);	
	}
	for(int i=1;i<10;i++)
		if(cnt[i]!=0)
		{
			printf("%d",i);
			cnt[i]--;
			break;
		}
	for(int i=0;i<10;i++)
	{
		while(cnt[i]--!=0)
			printf("%d", i);
	}
	return 0;
}
