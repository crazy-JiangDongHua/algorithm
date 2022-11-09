这一节来讲怎么处理分数

1. 分数的表示

   分数有分子和分母组成

   ```c++
   struct fraction{
       int up, down; //分子，分母
   }
   ```

   我们需要对分数规范化的表达（一般题目会有要求，以下是常见规则，读者可以根据实际拓展）：

   * 如果为负分数，那么分子为负，分母为正
   * 如果为0，那么分子为0，分母为1
   * 约分：分子分母最大公约数为1

   ```c++
   fraction reduction(fraction f)
   {
       if(f.down < 0)
       {
           f.down *= -1;
           f.up *= -1;
       }
       if(f.up == 0)
           f.down = 1;
       else
       {
           int d = gcd(abs(f.up), abs(f.down));
           f.up / = d;
           f.down /= d;
       }
       return f;
   }
   ```

2. 分数的加减乘除

   分数的加减乘除方法都是一样的，先通分，在计算，最后化简。

   这里以加为例子

   ```c++
   fraction add(fraction a, fraction b)
   {
       fraction res;
       res.up = a.up*b.down + b.up*a.down;
       res.down = a.down * b.down;
       return reduction(res);
   }
   ```

3. 分数的输出

   * 输出之前先化简
   * 如果分母为1，输出分子整数
   * 如果分母大于分子，输出带分数

   ```c++
   void show(fraction f)
   {
       reduction(f);
       if(f.down == 1) //整数
           printf("%d", f.up);
       else if(f.up < f.down) //真分数
           printf("%d/%d", f.up, f.down);
       else
       {
           printf("%d %d/%d", f.up/f.down, f.up%f.down, f.down);
       }
   }
   ```

   

最后说明一下，分数的计算很有可能超出int的范围，最好用longlong。

练习：

1. leetcode 592 分数加减运算：使用上述模板即可