本节讲解质因数分解

首先要明白一个道理，就是对于n的质因数，他们只会有两种情况：

1. 全部小于等于sqrt(n)
2. 只有一个大于sqrt(n)，其他全部小于sqrt(n)

所以我们只需要对sqrt(n)以内的数算素数表，然后枚举每一个素数，看他是不是质因数就行。然后如果枚举完了，这个数还不为1，那么剩下这个数就是大于sqrt(n)的质因数。

```c++
#include <cstdio>
#include <cmath>

// 用埃拉托色尼方法打表
const int maxn = 100010; //sqrt(int)约等于10的5次方
int prime[maxn], pCnt=0;
bool p[maxn] = {0};

void find_Prime()
{
    for(int i=2;i<maxn;i++)
    {
        if(!p[i])
        {
            prime[pCnt++] = i;
            for(int j=i+i;j<maxn;j+=i)
            {
                p[j] = true;
            }
        }
    }
}

struct factor{
    int x, cnt; //质因子，个数
}fac[10];//10个足够，再大就超出int范围

int main()
{
    int n, num = 0;
    scanf("%d", &n);
    if(n == 1) //1需要特判
        printf("1=1");
    else
    {
        find_Prime();
        printf("%d=",n);
        int sqr = sqrt(n);
        for(int i=0;i<pCnt && prime[i]<=sqr;i++)
        {
            if(n % prime[i] == 0)
            {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while(n%prime[i] == 0)
                {
                    n /= prime[i];
                    fac[num].cnt++;
                }
                num++;
            }
            if(n==1)
                break;
        }
        if(n!=1)
        {
            fac[num].x = n;
            fac[num].cnt = 1;
            num++;
        }
        for(int i=0;i<num;i++)
        {
            if(i>0)
                printf("*");
            printf("%d", fac[i].x);
            if(fac[i].cnt>1)
                printf("^%d", fac[i].cnt);
        }
    }
    return 0;
}
```



另外，如果要求一个数的因子个数，那就对他质因数分解，得到各个质因数的个数为$n_1,n_2,n_3,\dots,n_k$，那么因子的个数为$\prod_{i=1}^{k} 1+n_i$。

所有因子的和为$\prod_{i=1}^{k} \sum_{j=0}^{n_i} p_i^j$。



练习：

1. leetcode 263 丑数

2. leetocde 264 丑数2：首先要明白，对于一个丑数$x$，那么$2x,3x,5x$也都是丑数。假设丑数的序列是$a_1,a_2,\dots,a_n$，那么$a_i$一定能被下面三个序列覆盖到：

   * 由丑数 * 2 所得的有序序列
   * 由丑数 * 3 所得的有序序列
   * 由丑数 * 5 所得的有序序列

   如果我们已经得到这三个序列，那就归并这三就好了。但是我们并不需要一开始就知道整个序列，可以随着迭代算。已知三个序列开始都是1，即$a_1=1$，那么三个序列接下来是$2a_1=2，3a_1=3，5a_1=5$，最小的是2，所以得到$a_2=2$，那么我们可以继续计算第一个序列的下一个元素是$2a_2=4$，然后已知重复下去直到得到$a_n$。注意，可能会存在重复，比如$a_6=6=2a_3=3a_2,a_3=2,a_2=2$，这种情况就应该同时计算第一个和第二个序列的下一个元素了。实际上是一种动态规划的思想。

3. leetcode 1492 n的第k个因子：先遍历一遍从1到$\sqrt n$，再遍历一遍$\sqrt n$到1。注意$\sqrt n$可能有重复。
