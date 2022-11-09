#include <cstdio>
#include <algorithm>
using std::sort;

int tonum(int arr[])
{
	int res = 0;
	for(int i=0;i<4;i++)
		res = res*10 + arr[i];
	return res;
}

void toarr(int num, int arr[])
{
	for(int i=3;i>=0;i--)
	{
		arr[i] = num%10;
		num /= 10;
	}
}

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	int arr[4];
	int up, down, num;
	scanf("%d", &num);
	do{
		toarr(num, arr);
		sort(arr, arr+4);
		up = tonum(arr);
		sort(arr, arr+4, cmp);
		down = tonum(arr);
		num = down - up;
		printf("%04d-%04d=%04d\n", down, up, num); 
	}while(num!=0 && num!=6174);
	return 0;
} 
