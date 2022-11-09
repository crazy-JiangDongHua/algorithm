这一节讲扩展欧几里得算法，很多数学证明，实在懒得打字，就看书把

1. ax+by=gcd(a, b)

```c++
int exGcd(int a, int b, int&x, int& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = exGcd(b, a%b, x, y);
    int temp = x;
    x = y;
    y = temp - a/b*y;
    return g;
}
```

这只一组解，实际上x=x+b/gcd乘K，y=y-a/gcd乘K

x的最小非负数解是x=(x%(b/gcd)+(b/gcd)%(b/gcd)

2. 求解ax+by=gcd(a,b)

   * 如果c%gcd(a,b)!=0，那么无解
   * 如果c%gcd(a,b)=0，那么两边同乘c/gcd转化为第一题

3. 求解ax=c(mod m)

   转换为ax+m(-y)=c求解，令y = -y，转化为第二题
   
4. 求解逆元和(b/a)%m
   
   ax=1(mod m)，用第三题解法求出x，然后(b/a)%m就可以转化为(b*x)%m，
   
   而(b*x)%m = (b%m)乘(a%m)%m
   
   * 如果gcd(a,m)=1，那就转化成第三题
   
   * 如果gcd(a, m)!=1，那就转为(b%(am))/a，但是小心am溢出。
   
   