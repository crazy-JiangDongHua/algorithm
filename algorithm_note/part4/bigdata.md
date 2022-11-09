这一章就是宇宙无敌超级大考点，让人看了望而却步，但是认真学下来，你就会发现其实so esay，来吧，学完这章，机试题，你把握住了。

1. 大整数存储

   大整数直接用数组存储，一般是小尾端（即低位存在低地址），一般先以读字符串形式读取，在反向一波存到大数里面。

   比较大小的话也很简单，谁长谁大，一样长就从高位比起，谁先有一位是大的，那就是大的。

   ```c++
   struct bign{
       int d[1000];
       int len;
       bign(){
           memset(d, 0, sizeof(d));
           len=0;
       }
   }
   
   bign change(char str[])
   {
       bign a;
       a.len = strlen(str);
       for(int i=0;i<a.len;i++)
       {
           a.d[i] = str[a.len-i-1] - '0';
       }
       return a;
   };
   
   int compare(bign a, bign b)
   {
       if(a.len > b.len)return 1; //a大
       else if(a.len < b.len)return -1; //b大
       else
       {
           for(int i=a.len-1;i>=0;i++)
           {
               if(a.d[i] > b.d[i])return 1;
               else if(a.d[i] < b.d[i])return -1;
           }
           return 0;
       }
   }
   ```

2. 高精度加法

   ```c++
   bign add(bign a, bign b)
   {
       bign c;
       int carry = 0;
       c.len = max(a.len, b.len);
       for(int i=0;i<c.len;i++)
       {
           int temp = a.d[i] + b.d[i] + carry;
           c.d[i] = temp%10;
           carry = temp/10;
       }
       if(carry !=0)
           c.d[c.len++] = carry;
       return c;
   }
   ```

3. 高精度减法

   ```c++
   // 假设a>b 如果不是可以调换一下加一个负号
   bign sub(bign a, bign b)
   {
       bign c;
       int len = max(a.len, b.len)
       for(int i=0;i<len;i++)
       {
           if(a.d[i] < b.d[i])
           {
               a.d[i+1]--;
               a.d[i] += 10;
           }
           c.d[c.len++] = a.d[i] - b.d[i];
       }
       while(c.len > 1 && c.d[c.len-1] == 0)
           c.len--; //去除高位的0;
       return c;
   }
   ```

4. 高精度乘低精度

   ```c++
   // 如果有负号的话，先记录，然后输入绝对值
   bign multi(bign a, int b)
   {
       bign c;
       int carry = 0;
       for(int i=0;i<a.len;i++)
       {
           int temp = a.d[i] * b + carry;
           c.d[c.len++] = temp%10;
           carry = temp/10;
       }
       while(carry!=0)
       {
           c.d[c.len++] = carry%10;
           carry /= 10;
       }
       return c;
   }
   ```

5. 高进度除低精度 可以获得进制转换，求余数

   ```c++
   // 考虑到还要输出余数，但是又只能返回一个参数，所以用了引用
   // 同理考虑负号
   bign divide(bign a, int b, int&r)
   {
       bign c;
       c.len = a.len;
       r=0; //防止乱传数
       for(int i=a.len-1;i>=0;i--)
       {
           r = r*10 + a.d[i];
           c.d[i] = r / b;
           r %= b;
       }
       
       while(c.len > 1 && c.d[c.len-1] == 0)
       {
           c.len--;
       }
       return c;
   }
   ```

6. 高精度乘高精度

   ```c++
   bign bigmulti(bign a, bign b)
   {
       bign c;
       for(int i=0;i<a.len;i++)
           for(int j=0;j<b.len;j++)
               c.d[i+j] += a.d[i] * b.d[j];
       
       int carry = 0;
       c.len = a.len + b.len;
       for(int i=0; i<c.len; i++)
       {
           int temp = carry + c.d[i];
           c.d[i] = temp % 10;
           carry = temp / 10;
       }
       while(c.len > 1 && c.d[c.len-1] == 0) //考虑到两种情况：一是乘0，二是只有a.len+b.len-1位
           c.len--;
       return c;
   }
   ```

   

练习：

1. leetcode 166 分数到小数：和高精度一样的思路，长除法。注意循环节的寻找方法，当出现相同的余数的时候，就代表出现了循环节，用一个哈希表存储所有的余数出现的位置。
2. 高精度进制转换，套之前进制转换的板子，但是用的是高精度。

对于一个十进制数A，将A转换为二进制数，然后按位逆序排列，再转换为十进制数B，我们称B为A的二进制逆序数。   例如对于十进制数173，它的二进制形式为10101101，逆序排列得到10110101，其十进制数为181，181即为173的二进制逆序数。

https://www.nowcoder.com/questionTerminal/fd972d5d5cf04dd4bb4e5f027d4fc11e

```c++
#include <cstdio>
#include <cstring>

struct bign{
    int d[4010];
    int len;
    bign()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char str[])
{
    bign res;
    res.len = strlen(str);
    for(int i=0;i<res.len;i++)
    {
        res.d[i] = str[res.len - i -1] - '0';
    }
    return res;
}

bign reverse(bign a)
{
    for(int i=0,j=a.len-1;i<j;i++,j--)
    {
        int temp = a.d[i];
        a.d[i] = a.d[j];
        a.d[j] = temp;
    }
    return a;
}

bign divide(bign a, int b, int& r)
{
    bign res;
    res.len = a.len;
    for(int i=res.len-1;i>=0;i--)
    {
        int temp = r*10 + a.d[i];
        res.d[i] = temp/b;
        r = temp%b;
    }
    while(res.len>1 && res.d[res.len-1]==0)
        res.len--;
    return res;
}

bign multi(bign a, int b)
{
    bign res;
    int carry=0;
    for(int i=0;i<a.len;i++)
    {
        int temp = carry+a.d[i]*b;
        res.d[res.len++] = temp%10;
        carry = temp/10;
    }
    while(carry!=0)
    {
        res.d[res.len++] = carry%10;
        carry/=10;
    }
    return res;
}

bign add(bign a, bign b)
{
    bign res;
    int carry = 0;
    for(int i=0;i<a.len || i<b.len;i++)
    {
        int temp = carry + a.d[i] + b.d[i];
        res.d[res.len++] = temp%10;
        carry = temp/10;
    }
    if(carry!=0)
    {
        res.d[res.len++] = carry;
    }
    return res;
}

void show(bign res)
{
	for(int i=res.len-1;i>=0;i--)
	{
		printf("%d",res.d[i]);
	}
	printf("\n");
}


int main()
{
    char str[1010];
    while(scanf("%s", str) != -1)
    {
        // 读取
        bign a = change(str);
//        show(a); 
        // 转为二进制
        bign bin;
        int r;
        do{
            r = 0;
            a = divide(a, 2, r);
            bin.d[bin.len++] = r;
        }while(!(a.len==1 && a.d[0]==0));//直到a=0
//        show(bin);
        // 逆转
        bign rev = reverse(bin);
//        show(rev);
        // 去除首位的零
        while(rev.len>1 && rev.d[rev.len-1]==0)
        	rev.len--;
        // 转为10进制，这里不能套板子乘product了
        bign res;
        res.len = 1;//初始化为0
        for(int i=rev.len-1; i>=0; i--)
        {
            bign unit;
            unit.len = 1;
            unit.d[0] = rev.d[i];
            bign tmp = multi(res, 2);
            res = add(tmp, unit);
        }
        
        show(res);
    }
    return 0;
}
```

