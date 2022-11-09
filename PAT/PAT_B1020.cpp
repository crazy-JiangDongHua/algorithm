//连续背包问题
//注意题干月饼库存和总售价是正数，不一定是正整数，可能是正浮点

#include <cstdio>
#include <algorithm>
using std::sort;

struct mooncake
{
	double w; //存量 
	double v; //单位售价 
};

int cmp(const mooncake& a, const mooncake& b)
{
	return a.v > b.v;
}

mooncake arr[1010]; 
int n;
double d;

int main()
{
	scanf("%d %lf",&n,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%lf", &(arr[i].w));
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lf", &(arr[i].v));
		arr[i].v /= arr[i].w;
	}
	sort(arr, arr+n, cmp);
	double res = 0.0;
	int i=0; 
	while(d>0 && i<n) //有可能需求大于全部月饼存量 
	{
		if(d>arr[i].w)
		{
			d -= arr[i].w;
			res += arr[i].v * arr[i].w;
		}
		else
		{
			res += d * arr[i].v;
			d = 0.0;
		}
		i++;
	}
	printf("%.2f", res);
	return 0;	
} 
