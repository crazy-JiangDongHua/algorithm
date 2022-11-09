#include <cstdio>
const int MAXN = 10e5;
int score[MAXN+1];
int main()
{
	int n;
	scanf("%d", &n);
	int id, s;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&id,&s);
		score[id]+=s; 
	}
	int maxid=0, maxs=-1;
	for(int i=1;i<=n;i++)
	{
		if(score[i]>maxs)
		{
			maxid = i;
			maxs = score[i];
		}
	}
	printf("%d %d", maxid, maxs);
	return 0;
}
