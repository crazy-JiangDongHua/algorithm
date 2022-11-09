首先有些简单的热身，只需要懂得基本的数理逻辑

* PATA1069数字黑洞

```c++
#include <cstdio>
#include <algorithm>
using std::sort;

bool cmp(char a, char b)
{
    return a>b;
}

int num, max, min;
char numarr[5];
int len = 4;

int tonum()
{
	int res=0;
	for(int i=0;i<len;i++)
	{
		res = res*10 + (numarr[i]-'0');
	}
	return res;
}

int main()
{
    scanf("%d", &num);
    do{
        sprintf(numarr, "%04d", num);
        sort(numarr, numarr+len);
        min = tonum();
        sort(numarr, numarr+len, cmp);
        max = tonum();
        num = max - min;
        printf("%04d - %04d = %04d\n", max, min, num);
    }while(num!=0 && num!=6174);
    return 0;
}
```

