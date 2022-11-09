// 找x 
#include <cstdio>
const int MAXN = 200+10;
int arr[MAXN];
int main()
{
	int n, x;
	while(scanf("%d",&n) != -1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d", arr+i);
		}
		scanf("%d", &x);
		int res=-1;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==x)
			{
				res = i;
				break;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
