1. 如何求n!中有几个质因子p。

   ```c++
   //递归求法 O(logn)
   int cal(n, p)
   {
       if(n<p)
       {
           return 0;
       }
       // 1~n中p的倍数的个数 + 加上剩下的
       return n/p + cal(n/p, p);
   }
   
   //迭代求法
   int cal(n, p)
   {
       int res = 0;
       while(n)
       {
           res += n/p;
           n /= p;
       }
   }
   ```

2. 如何求n取m的组合数

   ```c++
   // 定义求法，迅速溢出
   long long C(long long n, long long m)
   {
       long long res = 1;
       for(long long i=1;i<=n;i++)
           res *= i;
       for(long long i=1;i<=m;i++)
           res /= i;
       for(long long i=1;i<=n-m;i++)
           res /= i;
       return res;
   }
   
   // 递归求法O(n^2), 也可以用dp实现
   long long res[67][67];
   long long C(long long n, long long m)
   {
       if(n == 0 || m == 0)
           return 1;
       if(res[n][m]!=0)return res[n][m];
       else
           // 取最后一个和不取最后一个
           return res[n][m] = res[n-1][m-1] + res[n-1][m];
   }
   
   // 最快方法O(m)
   long long C(long long n, long long m)
   {
       long long res = 1;
       for(int i=1;i<=m;i++)
           res = res * (n - m + i) / i; //保证整除证明很精妙
           // 这个方法没法用去组合数取模，因为求模对除法，不满足
           // (a/b)%p != ((a%p) / (b%p))%p 
   }
   ```

   不管那种方法都是非常容易溢出的，所以最后还是要用到大数存储。

3. 如何求n取m的组合数求模p

   ```c++
   // 直接算 支持m<=n<=1000
   int res[1010][1010];
   int C(int n, int m)
   {
       if(n == 0 || m == 0)
           return 1;
       if(res[n][m]!=0)return res[n][m];
       else
           // 取最后一个和不取最后一个
           return res[n][m] = (res[n-1][m-1] + res[n-1][m])%p;
   }
                 
   // 用求n!里面有多少个p的方法先质因数分解，然后再快速幂求。O(nlongn) 支持m<=n<=1000
   int prime[maxn]; //先用筛法求素数表
   int C(int n, int m, int p)
   {
       int ans = 1;
       for(int i=0;i<maxn && prime[i]<=n;i++)
       {
           // 求C(m,n)中prime[i]的个数 O(logn)
           int c = cal(n, prime[i]) - cal(m, prime[i]) - cal(n-m, prime[i]);
           // 快速幂 O(logc)
           ans *= binpower(prime[i], c, p) % p;
       }
       return ans;
   }
   ```

   