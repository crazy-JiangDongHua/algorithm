#include<cstdio>
int main()
{
	int n, cnt=0;
	scanf("%d", &n);
	while(n!=1)
	{
		n = n%2==0?n>>1:(3*n+1)>>1;
		cnt++; 
	}
	printf("%d",cnt);
	return 0;
}
