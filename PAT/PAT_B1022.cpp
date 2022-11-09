#include <cstdio>
int main()
{
	int a, b, d;
	scanf("%d %d %d",&a,&b,&d);
	int sum = a+b;
	int stack[32], cnt=0;
	do{
		stack[cnt++] = sum%d;
		sum /= d;
	}while(sum!=0);
	while(cnt--)
		printf("%d",stack[cnt]);
	return 0;
}
