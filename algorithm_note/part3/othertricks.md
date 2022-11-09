* 打表

  递归，dp的时候可以打表，如斐波那契数

* 递推

  PATA1093 有几个PAT

  ```c++
  // 一个A左边有m个P,n个T,那么他就可以组成m*n个PAT
  #include <cstring>
  #include <iostream>
  using std::cin;
  const int maxn = 100010;
  char str[maxn];
  const int mod = 1000000007;
  int pcount[maxn] = {0};
  int main()
  {
      cin.getline(str, maxn);
      int len = strlen(str);
      for(int i=0;i<len;i++)
      {
          if(i>0)
              pcount[i] = pcount[i-1];
          if(str[i]=='P')
              pcount[i]++;
      }
      int tcount = 0,res = 0;
      for(int i=len-1;i>-1;i--)
      {
          if(str[i]=='T')
              tcount++;
          else if(str[i]=='A')
          {
              res = (res + tcount * pcount[i]) % mod;
          }
      }
      printf("%d\n", res);
      return 0;
  }
  ```

* 随机选择

  求第K大的数

  应用：划分一个集合为两个相等子集，使得差最大。解法：求n/2的划分。
  
* 判断两个浮点数a和b是否相等的时候，不要用等于，要用fabs(a-b)<eps，eps是个很小的阈值，例如$1e-9$

* 判断一个整数是否为奇数，不要写x%2==1，因为x可能是负数，要写x%2!=0

* 用char的值做数组下标是不对的，因为char可能是负数，应该写强制类型转换为unsigned char，再做下标。

* vector和string的性能优于动态分配的数组。

* 使用reserve来避免不必要的重新分配

关于优化上一些tricks:

* `!`，`==`和`!=`比`>`，`<`等要快

* 多用引用，速度回快很多

* emplace_back比push_back快很多

