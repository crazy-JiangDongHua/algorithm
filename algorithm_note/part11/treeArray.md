本节介绍数状数组，简直就是屠龙技！

首先介绍lowbit运算。`lowbit(x)=x&(-x)`，在二进制中，`-x`发生就是`x`所有bit位取反加一，相当于`x`最右边的1左边的每一位都取反。所以`lowbit(x)`就是去`x`二进制最右边的1和它右边的0。因此`lowbit(x)`也可以理解为`x`能整出的最大的2的幂次。
```c++
int lowbit(int x){
    return x&(-x);
}
```

接下来介绍树状数组，首先看一个问题：给出一个整数序列A，元素个数为N（N<=10^5），接下来查询次数为K（K<=10^5），每次查询都给出一个正整数x，求前x个整数之和。

这个问题有一个很常规的思路，就是来一个`sum`数组，`sum[i]`记录前`i`数的和，这样生成`sum`数组的时间复杂度为$O(N)$，均摊到每一次查询上，每次查询的时间复杂度为$O(1)$，总的时间复杂度为$O(N)$。

现在升级一下，如果查询的过程中可能随时给第x个整数加上一个整数v，要求能够实时查询前x给整数之和。如果沿用之前的思路，那么每次更新第x个整数的值，都需要更新`sum[x],sum[x+1],...,sum[N]`，时间复杂度为$O(N)$，这样总的时间复杂度就是$O(N^2)$。如果我们直接在原数组上更新，那么更新只需要$O(1)$的时间，但是查询就需要求前缀和，需要$O(N)$的时间，总的时间复杂度为$O(N^2)$。

这样的时间复杂度是难以接受的，我们可以利用树状数组来巧妙的解决这个问题。树状数组`C[i], 1<=i<=N`的定义为在i号位之前（含i号位）lowbit(i)个整数之和。

首先来看一下如何更新。如果改变了第x个整数，那么所有包含了`A[x]`的`C[i]`都需要更新。那么是哪些`C[i]`呢，首先肯定有`C[x]`，然后再去找最近的`C[y]`覆盖`A[x]`，显然`y>=x`。而这件事等价于找最近的`C[y]`覆盖`C[x]`，那么显然`lowbit(y)=lowbit(x+a)>lowbit(x)`，不然怎么覆盖呢...我们考虑`lowbit(a)`，如果`lowbit(a)<lowbit(x)`，那么`lowbit(a+x)<lowbit(x)`，所以可知`lowbit(a)>=lowbit(x)`，而我们又希望`a`尽可能小，所以答案这就出来了，`a=lowbit(x)`。更新代码实现如下：
```c++
void update(int x, int v){
    for(int i=x;i<=N;i+=lowbit(i){
        C[i]+=v;
    }
}
```
这样子做的时间复杂度为$\log N$，因为i每加一次lowbit(i)，做右边的1支少向左移动1位，最多移动$\log N$位。

然后来看求和，求和就很简单了，根据定义可知`A[1]+A[2]+...+A[x]=A[1]+...+A[x-lowbit[x]]+C[x]`，然后就可以根据递归做了。
```c++
int getSum(int x){
    int sum=0;
    for(int i=x;i>0;i-=lowbit(i)){
        sum+=C[i];
    }
    return sum;
}
```
i每次减去lowbit(i)，相当于把最右边的1置0，那么最多执行$O(\log N)$次。如果是要求区间`[x,y]`的和，那就可以转化为`getSun(y)-getSum(y-1)`。

现在来看下树状数组最经典的应用：给定一个又N个正整数的序列A（N<=10^5, A[i]<=10^5），对序列中的每个数，求出序列中它左边比他小的数的个数。

最直接的思路是用哈希数组`hash[x]`记录`x`当前出现的次数。接着从左到右遍历序列A，假设当前访问`A[i]`，那么令`hash[A[i]]++`，然后求和`hash[1]+...+hashhash[A[i]-1]`。直接求和最后的时间复杂度为$O(N^2)$。但是我们可以用树状数组，来做这一步，可以使得时间复杂度降到$O(N\log N)$。实际上，使用树状数组之后，我们并不需要真的维护一个hash数组，只是逻辑上存在就可以了。
```c++
const int maxn=100010;
int C[maxn];//树状数组
int A[maxn];
int main(){
    for(int i=0;i<n;i++){
        update(A[i], 1);
        cout<<getSum(A[i]-1)<<endl;
    }
    return 0;
}
```
这个问题也有一些变体，比如说元素左边比元素大的元素个数，那答案就是`getSum(N)-getSum(A[i])`。如果是元素右边比元素小的元素，那就从右至左遍历`A[i]`。
如果`A[i]<=10^5`不成立，那就要用到**离散化**的技巧。看一个例子，对于这个问题而言，`[1,9999999, 3]`和`[1,3,2]`是没有区别的，所以我们可以吧`A[]`排序，然后用排名（相同则排名一样），代替`A[i]`。

对于上一章提到的在线查询第k大元素，也可以用树状数组解决。寻找第k大，实际上就是找到第一个i，使得`hash[1]+hash[2]+...hash[i]>=k`，用树状数组解决hash数组求和问题，就转换成了`getSum(i)>=k`。
因为hash数组的前缀和是递增的，所以我们可以令`l=1,r=manx`，然后在这个区间内二分搜索。
```c++
int findKMax(int k){
    int l=1,r=maxx;
    while(l<maxn){
        int m=(l+r)/2;
        if(getSum(m)<k)
            l=m+1;
        else
            r=m;
    }
    return l;
}
```
getSum的时间复杂度是$O(\log N)$，二分的时间复杂度是$O(\log N)$，所以总的时间复杂度就是$O((\log N)^2)$

到目前为止，都是在对树状数组进行**单点更新，区间查询**。那如果想要**区间更新，单点查询**呢？我们面对的是两个问题：
1. 设置函数getSum(x)，返回A[x]
2. 设置函数update(x, v)，将A[1]~A[x]的元素都加上v

我们只需要稍微修改一个树状数组的定义就可以了。`C[i]`依然保持`lowbit(i)`的长度，但是不再表示这段元素和了，而是表示这段区间，每个数加了多少。

对于getSum(x)，只需要找到所有覆盖`A[x]`的`C[i]`，然后求和就行，这不就是之前单点更新，区间查询的update(x)操作吗。
```c++
int getSum(int x){
    int sum=0;
    for(int i=x;i<;i+=lowbit(i)){
        sum+=c[i];
    }
    return sum
}
```

对于update()函数，此时需要把`A[1]~A[x]`的每个数都加上v，这就是之前单点更新，区间查询的getSum(x)操作。
```c++
void update(int x,int v){
    for(int i=x;i>0;i-=lowbit(x))
        c[i]+=v;
}
```
如果需要更新`[x,y]`区间的每个元素都加上v，那么可以变为先后执行update(y,v)和update(x-1, -v)。

练习：
1. offer51 数组中的逆序对：可以边归并排序边计算，也可以转为元素右边比元素小的个数的和。时间复杂度都是$O(n\log n)$，空间复杂度都为$O(n)$。
2. leetcode 307 区域和检索 - 数组可修改：树状数组的直接应用。也可以使用前一节介绍的分块思想。

趁此良机，我们再来做一点其他数组的题目：
1. leetcode 80 删除有序数组中的重复项 II:双指针，当且仅当上一个元素和当前元素相同时，当前元素不需要保留。
2. leetcode 81 搜索旋转排序数组 II：这题是搜索旋转数组的进阶版，序列中允许存在相同的元素，这就会出现一种情况：`arr[lo]==arr[mi]==arr[hi]`，这样就会导致我们无法区分左右两个区间哪个有序，所以这是就只能收缩边界：`lo++;hi--`，然后在新的区间搜索。
3. leetcode 4 寻找两个正序数组的中位数：该题是寻找两个有序序列第k个数的特定情况。使用二分查找，不断搜索两个数组中`k/2-1`位置的数，然后可以缩小`k/2`的规模。
4. leetcode 1 两数之和：可以先排序在双指针对撞，这样需要用pair记录原数组的位置，时间复杂度为$O(n\log n)$。也可以用hash表，存储每个元素的下标，然后看traget-x存不存在就完事了，时间复杂度为$O(n)$，需要注意有可能有相同的元素，或者同一个元素相加等于target。
5. leetcode 15 三数之和：枚举第一个元素，然后就变成了两数之和。先排序，然后要求前两个元素都不能重复，这样才能保证答案唯一。
6. leetcode 16 最接近的三数之和：和leetcode15一个思路，稍微修改一下代码。
7. leetcode 18 四数之和：和leetcode15一个思路，去重的精确描述：可以对数组进行排序，并且在循环过程中遵循以下两点：1.每一种循环枚举到的下标必须大于上一重循环枚举到的下标；2.同一重循环中，如果当前元素与上一个元素相同，则跳过当前元素。
8. leetcode 27 移除元素：用双指针，可以快慢指针，也可以对撞指针。对撞指针可以避免保留元素的重复赋值。
9. leetcode 31 下一个排列：非常有意思的一个题目，通过从后往前搜索非降序列，找到最近的待交换对中较小元素x，然后再重后往前寻找第一个大于x的元素y，然后交换，最后反转x之后的序列。
10. leetcode 60 排序序列：这道题第一思路就是用dfs，然后计数，这样的时间复杂度为$O(kn)$。思考一下，将入确定了第一个位置的元素，那么后面n-1个元素的排列数则为(n-1)!。那么用k/(n-1)+1，就代表第一个位置的元素，在目前可用的元素中的排序，一次类推，时间复杂度为$O(n^2)$。同样我们也可以反过来，给定一个序列，要求排序：
$k=(\sum_{i=1}^{n}\text{order}(a_i)\times (n-i)!) +1$
其中$\text{order}(a_i)$表示$a_i$右边比它小的元素个数。
11. leetcode 42 接雨水：对于每个位置`i`，它能接到的雨水高度为，左边和右边最大高度的最小值，在减去自身的高度。那么我们可以通过从左往右和从右往左两趟扫描，得到每个`i`能接到的雨水高度，然后求和。这两趟扫描，也可以由双指针优化为一次扫描。也可以通过维护一个递减的单调栈实现。
12. leetcode 48 旋转图像：等价于先斜对角线翻转，然后竖直翻转。
13. leetcode 64 加一：第一思路就是大数求和。但是因为指定加一，所以还能优化，只需要找到最长后缀9，然后全部置0，前一位加1就行。
14. leetcode 70 爬楼梯：简单动态规划
15. leetcode 89 格雷编码：在得到n-1位的格雷码后，可以把所得的格雷码反序，然后加上$2^(n-1)$，就可以得到n位的格雷码。
16. leetcode 73 矩阵置零：题目要求用$O(1)$的空间复杂度来就地置零，一种可行的思路是，用两个变量来记录第一行和第一列是否应该置零，然后再用第一行和第一列来记录每一行和每一列是否应该置零。这种方法仍有优化的空间，我们可以发现，`matrix[0][0]`实际上是没有用到的，那我们就可以用它来存储第一行是否应该置零，那么语义上，第一列来记录每一行是否应该置零拓展包括了第一行，在赋值的之后，我们应该最后处理第一行，因为他还记录了每一列是否置零的信息。
17. leetcode 134 加油站：主要要明白如果从x出发，不能到达y，那么从xy之间的加油站出发，都不能到达y。所以最多遍历两遍就行了。这道题还有一种更牛逼的做法，因为保证有唯一解，所以我们可以把所有的gas和cost求和，然后相减，如果大于等于0，那么就有解，否则无解。然后从第一个站往后遍历，如果有解，第一个能够到达最后一个站的就是解，从而无需再遍历一遍。
18. leetcode 135 分糖果：“相邻的孩子中，评分高的孩子必须获得更多的糖果”这个规则，可以分为两条规则，1. 左规则：如果`rating[i]>rating[i-1]`，那么第`i`个孩子要比第`i-1`个孩子多拿一个糖果。2. 右规则：如果`rating[i]>rating[i+1]`，那么第`i`个孩子要比第`i+1`个孩子多拿一个糖果。所以我们可以从左往右扫描，找到每个孩子满足左规则的最少糖果数，从右往左扫描，找到每个孩子满足右规则的最少糖果数，然后取两者之中的大值求和。也可以扫描一遍，对于递增序列一样处理，对于递减序列，每次拓展一个元素，之前的元素值就都加一，特别需要注意的是，如果相邻递减序列和递增序列长度相同，那递增序列的最后一个元素也会被包括到递减序列中。
19. leetcode 136 只出现一次的数字：使用异或运算，其实只要是出现偶数次，异或都可以处理。
20. leetcode 137 只出现一次的数字2：int有32位，统计所有数每一位中1出现的次数，如果求模3不等于0，说明只出现一次的数字在这一位为1，否则为0。