二分应用太多了，学问也太多了。

1. 二分查找

   对于n个不重复有序元素arr[]，查找给定元素x

   * 返回元素x的位置，没找到返回-1

   ```c++
   // left,right 初值为0,n,结果范围为[-1, n-1]
   int binsearch(int arr[], int left, int right, int x)
   {
       while(left < right)
       {
           int mid = (left + right)>>1;
           if(x == arr[mid])
               return mid;
           else if(x < arr[mid])
               right = mid;
           else
               left = mid+1;
       }
       return -1;
   }
   ```

   * 返回第一个大于x的元素的位置，维护了两个区间：

     1. [0, left)：所有元素都小于等于x
     2. [right, n]：所有元素都大于x
   
     最后left==right结束
   
   ```c++
   // left,right 初值为0,n,结果范围为[0, n]
   int binsearch(int arr[], int left, int right, int x)
   {
       while(left < right)
       {
           int mid = (left + right)>>1;
           if(arr[mid] > x)
               right = mid;
           else
               left = mid + 1;
       }
       return left;
   }
   ```
   
   * 返回第一个大于等于x的元素的位置，维护了两个区间：
   
     1. [0, left)：所有元素都小于x
     2. [right, n]：所有元素都大于等于x
   
     最后left==right结束
   
   ```c++
   // left,right 初值为0,n,结果范围为[0, n]
   int binsearch(int arr[], int left, int right, int x)
   {
       while(left < right)
       {
           int mid = (left + right)>>1;
           if(arr[mid] >= x)
               right = mid;
           else
               left = mid + 1;
       }
       return left;
   }
   ```
   
   * 当right超过int范围的一半的时候，mid按上面那种写法可能超限，可以写成下面这样，记得打括号，因为移位操作优先级比加法低。
   
   ```c++
   int mid = left + ((right - left)>>1);
   ```



练习：

1. leetcode34 在排序数组中查找元素的第一个和最后一个位置：算一遍第一个大于target的位置，算一遍第一个大于等于target的位置。

2. leetcode35 搜索插入位置：搜索第一个大于等于target的位置，因为无重复，有重复就是第一个大于target的位置加判断。

3. leetcode33 搜索旋转数组：这个问题感觉用左闭右闭区间更好做，关键在于[lo,mi)和(mi,hi]中一定有一个是有序的，从而可以在O(1)时间判断target是否在有序区间，如果不在就去另一半数组寻找，在的话后面就等价于二分

4. leetcode74 搜索二维矩阵：把矩阵的行拼起来组成一个升序向量二分，但是行向量长度不一是没法快速索引，所以可以先对第一列二分，找到target所在行再对行二分。

5. leetcode240 搜索二维矩阵2：和二分没啥关系，和上一题有关系，从右上角z字行查找，每次少一行或一列。



2. 二分法的其他应用

      * 求解单调函数f(x)=0在某个区间的根，例如求解$\sqrt 2$可以看作是$f(x)=x^2 -2 =0$ 在区间$[1,2]$内的根
      
        练习：leetcode 69 x的平方根
      
      * 木棒切割问题：给出N跟木棒，长度已知，需要切割成至少K段长度相等的木棒（长度必须为整数），问这些长度相等的木棒最长能有多长。
      
        对L进行二分，找出k大于等于K的最大的L，即第一个k小于K的L-1。
      
        ```c++
        #include <cstdio>
        int sticks[100];
        int main()
        {
            int N, K, left=1, right=1;
            scanf("%d %d", &N, &K);
            for(int i=0;i<N;i++)
            {
                scanf("%d", &sticks[i]);
                if(sticks[i]>right)
                    right = sticks[i];
            }
            right++;
            while(left<right)
            {
                int mid = (left+right)>>1;
                int k = 0;
                for(int i=0;i<N;i++)
                    k += sticks[i]/mid;
                if(k<K)
                    right = mid;
                else
                    left = mid+1;
            }
            printf("%d", left-1);
            return 0;
        }
        ```
      
      
      * 快速幂——求a^b%m
      
        * 递归版本
      
          ```c++
          int pow(int a, int b, int m)
          {
          	if(b == 0)
                  return 1;
          	if(b%2 != 0)
          		return a * pow(a, b-1, m) % m;
          	else
          	{
          		int mul = pow(a, b>>1, m) % m;
          		return mul * mul % m;
          	}
          }
          ```
      
        * 迭代版本
      
          ```c++
          int pow(int a, int b, int m)
          {
          	a = a%m;
          	int res = 1;
          	while(b>0)
          	{
          		if(b&1)
          			res = res * a % m;
          		a = a * a % m;
          		b >>= 1;
          	}
          	return ans;
          }    
          ```
      

​练习：leetcode 50 Pow(x, n)
