这一节讲解素数

* 素数的判定

  ```c++
  #include <cmath>
  bool isPrime(int n)
  {
      if(n<=1) return false;
      int sqr = sqrt(n);
      for(int i=2;i<=sqr;i++)
      {
          if(n % i == 0)
              return false;
      }
      return true;
  }
  ```

  如果n没有接近int的上界限，那么for循环可以改为

  `for(int i=2;i*i<=n;i++)`

  直接判定的时间复杂度为$O(\frac{\sqrt n}{2})$，因为随机选一个数有一定的概率是偶数，偶数只需要一次判断，整除2就结束了。

* 素数表

  1. 埃拉托色尼筛法

  ```c++
  const int maxn = 101; //100以内的素数表
  int prime[maxn], pNum=0;
  bool p[maxn] = {0}; //false表示是素数
  void Find_Prime()
  {
      for(int i=2;i<maxn;i++)
      {
          if(!p[i])
          {
              prime[pNum++] = i;
              for(int j=i*i;j<maxn;j+=i)
              {
                  p[j] = true;
              }
          }
      }
  }
  ```

  埃拉托色尼筛法的时间复杂度为$O(n\log \log n)$，外层循环$n$次，当$i$为素数是，内层循环为$\frac{n}{i}$次，，所以$T(n)=n\times (\frac{1}{2}+\frac{1}{3}+\dots+\frac{1}{p})$，其中$p$为$n$以内最小素数。后面这个级数的上限为$O(\log \log n)$。

  但是诶拉托色尼筛法还是回重复筛，比如12会被2和3筛两次。


  2. 欧拉筛法
  ```c++
  const int maxn = 101;
  int prime[maxn], pNum=0;
  bool p[maxn] = {0}; //false表示是素数
  void Find_Prime()
  {
    for(int i=2;i<maxn;i++)
    {
        if(!p[i])
            prime[pNum++]=i;
        for(int j=0;j<pNum&&i*prime[j]<maxn;j++)
        {
            p[i*prime[j]]=true;
            if(i%prime[j])
                break;
        }
    }
  }
  ```
  欧拉筛法保证每个数只会被其最小素因子筛一次，就是`prime[j]`，时间复杂度为$O(n)$。
  * 正确性证明
  
    假设我们要筛掉数$a$，且$a$的最小质因数为 $p_1$，令$a=p_1b$。那么显然$b<a$，$b$先被外层循环碰到。现在$b$要筛掉它的倍数。因为$p_1$是$a$的最小质因数，所以$b$的最小质因数必不小于$p_1$，这样就保证$b$筛掉$a$前不会在`if(i % prime[j] == 0) break;`处跳出循环。即使$b$的最小质因数等于$p_1$，也会先筛掉$a$后再退出循环。令$a$等于全体合数，就保证了每个合数都会被筛掉。

  * 时间复杂度证明
    欧拉筛法的时间、空间复杂度为$\Theta(n)$。空间复杂度是显然的。下面证明时间复杂度为线性。
    
    我们的核心就是要证明一个合数只会被筛掉一次，即标记`isprime[a]=1`一次。首先，对于$a=p_1b$，$b$当然只会筛掉$a$一次，因为我们从小到大枚举`prime[j]`，也就是说`b * prime[j]`递增，因此不可能遇到$a$两次。会不会有其他的数筛掉$a$呢？假设$a$又被$c$筛掉了，其中$a=cp_x$，$p_x$就是$c$用来筛掉 $a$的`prime[j]`。
    1. 若$c>b$，则$p_x<p_1$，$p_1$是$a$最小的质因数矛盾，假设不成立；
    2. 若$c<b$，则$p_x>p_1$，这意味着$c=b/p_x*p_1$，那么$p_1$是$c$的质因数。那么$c$从小到大筛掉它的素数倍，在筛到$cp_1$时就`break`了，所以根本轮不到$a$。
  
  综上所述，每个数都只会被筛掉一次，再加上外层的i的循环是线性复杂度，总的时间复杂度是线性的。

  对于`i%prime[j] == 0`就`break`的解释 ：当`i`是`prime[j]`的倍数时，`i = kprime[j]`，如果继续运算`j+1`，`i * prime[j+1] = prime[j] * k prime[j+1]`，这里`prime[j]`是最小的素因子，当`i = k * prime[j+1]`时会重复，所以才跳出循环。


练习：

1. leetcode 866 回文素数：直接暴力测试每一个数会超时，所以换个思路是遍历每一个回文数字，检测他们是不是素数。回文数字可以由回文根构成，比如根是789，长度为3，那么这个根就可以构成一个长度为5的回文数78987，和一个长度为6的回文数789987。这样虽然时间复杂度上限还是$O(n)$，但是显然常系数变小了很多。

