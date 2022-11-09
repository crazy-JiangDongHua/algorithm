hash是非常常用的算法，很多程序都会无意识的用到

例如：给定N个数，在给定M个数，问这M个数是否在N个数之间出现过，出现了几次，常规想法是一趟一趟的遍历，时间复杂度为O(N*M)。但是我们可以用hash的思想，用空间换时间：

```c++
int hashtable[10010];
memset(hashtable, 0, sizeof(hashtable));
int x;
for(int i=0;i<N;i++)
{
    scanf("%d", &x);
    hashtable[x]++;
}
for(int i=0;i<M;i++)
{
    scanf("%d", &x);
    printf("%d", hashtable[x]);
}
```

这里的hash函数是h(key) = key。这个需要的地址空间很大，还有其他hash函数，例如:

1. 线性变换

   hash(key) = a*key+b

2. 求模

   hash(key) = key%mod(mod为素数)

3. 字符串hash

   * 字符串包含A-Z可以转为26进制数

   ```c++
   int hash(char str[])
   {
       int id = 0;
       for(int i=0;i<strlen(str);i++)
       {
           id = id*26 + (str[i]-'A');
       }
       return id;
   }
   ```

   当还包含a-z，0-9可以变成62进制，主要注意id的范围。

当发生冲突时，可以使用：

1. 线性探测
2. 平方探测
3. 链地址



实际使用中可以使用map或者unordered_map，详情参见1.2节