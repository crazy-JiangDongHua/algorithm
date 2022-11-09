排序是非常常用的算法，这里先回顾一下简单的排序算法，在讲解一下上机的实用排序算法实现。

1. 冒泡排序

```c++
void bubblesort()
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<len-1;j++)
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    }
}
```



2. 选择排序

```c++
void selectsort()
{
	 for(int i=0;i<n-1;i++)
	 {
	 	int minid=i;
	 	for(int j=i+1;j<n;j++)
	 	{
	 		if(arr[j]<arr[minid])
				minid = j 
	 	}
	 	int temp = arr[minid];
        arr[minid] = arr[i];
        arr[i] = temp;
	 }
}
```



3. 插入排序

```c++
void insertsort()
{
    for(int i=1;i<n;i++)
    {
        int temp = arr[i], j=i-1;
        while(j>-1 && temp<arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
```

4. 快速排序，归并排序放在双指针那一章了

5. 希尔排序

   希尔排序是基于直接插入排序的以下两点性质而提出的改进方法：

   1. 插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率。
   2. 插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位。

   希尔排序是将待排序的数组元素 按下标的一定增量分组 ，分成多个子序列，然后对各个子序列进行直接插入排序算法排序；然后依次缩减增量再进行排序，直到增量为1时，进行最后一次直接插入排序，排序结束。期望时间复杂度是$O(n^{\frac{3}{2}})$。


接下来是三种不是基于比较的排序，都是空间换时间的思想，时间复杂度能达到线性，但是它们通常只适用于整数元素序列的排序。因为用的不多，所以不放代码了，懂得原理就好

6. 计数排序

   以一个整数数列为例，如果我们知道它的最大值和最小值，那么也就意味着数组中的所有元素都位于 [最小值，最大值] 这个区间，我们对这个区间的每一个数在数组中出现的次数，然后在从小到大展开，这样就完成了排序，这就是计数排序(counting sort)的基本思想。可以看到，计数排序**不通过比较元素的大小关系来进行排序，因此是一种非比较类排序算法**。时间复杂度为 $O(n+k)$ ，其中 $k$ 是需要的桶的个数。总的来说基数排序的时间复杂度为 $O(n+k)$ ，最好最坏情况下都为 $O(n+k)$ 。计数排序使用了额外的长度为 $k$ 的数组来存放计数结果，空间复杂度为 $O(k)$。

7. 桶排序

   桶排序和计数排序的思路很象，只不过计数排序的“桶”只是用来计数每个元素的次数，而桶排序中的“桶”是真实存放元素的。桶排序中每个桶都是一个可以存放元素的容器，用来将原数组中的元素按照一定的**映射规则**放到桶里并且满足第 $i$ 个桶里的元素均小于第 $j$ 个桶里的元素($i<j$)，然后对每一个桶里的元素分别进行排序，这样在所有的桶排序完成后再将元素取出放回到原数组。

   上面一直在提一个“**映射规则**”，这个映射规则的目的就是确定某个元素应该被放到哪个桶里，从而当 $i<j$ 时满足第 $i$ 个桶里的元素均小于第 $j$ 个桶里的元素，这样保证在所有桶里元素均排序完成后将元素放回数组也是有序的。

   映射规则是人为设计的具体来说，如果我们预设桶的容量为 $m$，也就是每个桶中最多存放 $m$ 个元素，假设数组最大值和最小值分别为 $max$ 和 $min$，那么桶排序需要的桶的个数就为 $(max-min)/m$，接下来通过以下映射确定元素 $x$ 应当被放到哪个桶中：

   可以理解为我们将 $[min,max]$ 区间划分为了 $k$ 个连续的子区间，然后将数组中的数放到所属的区间内，接下来对每个区间内的数单独排序，最后使得整个数组有序。

   桶排序的平均时间复杂度为 $O(n+k)$ ，最好的时间复杂度为 $O(n+k)$ ，最坏的情况下时间复杂度为 $O(n^2)$。 当 $k==n$ 时，桶排序就变成了计数排序；当 $k==1$ 时，所有元素放在一个桶里，桶排序就演化成了内部排序的实现方式。

   桶排序使用了 $k$ 个桶来存放数组的所有元素，空间复杂度为 $O(n+k)$。

8. 基数排序

   基数排序是另一种使用了桶来辅助排序的非比较类排序。从直观上来讲，对于一个均为正数的整型数组，每个数字的每一位都是0-9中的某个数字。这样我们从最低位(个位)开始将每个数字放到最低位数字对应的桶中(编号0-9)，这样按桶的顺序得到一个新排列的数组，接下来按照十位的数字再放到相应桶中，一直到最高位，最终就得到一个有序的数组。

   基数排序平均时间复杂度为 $O(n *k)$，最好时间复杂度为 $O(n* k)$，最坏时间复杂度为 $O(n * k)$。其中k为最大数的位数。

4. sort函数

可以参考1.2节algorithm头文件sort函数用法，sort函数内部实现是快速排序。（PS，快速排序和归并排序给放到双指针那一章了）

有一些涉及到排序的题目会要求把rank输出，一般是同分同排名，非降输出，可以有选择地保存或者输出。

```c++
int r = 1;
for(int i=0;i<n;i++)
{
    if(i>0 && arr[i].score != arr[i-1].score)
        r = i+1;
    // r即为当前元素的排名
    save or print
}
```

练习题：

1. PAT A1025 PAT Ranking
2. interview 10.01 合并排序的数组：因为是后面的数组被提前复制，所以从后面开始合并，即先放大的数。
3. leetcode 21 合并两个有序链表：新建一个头节点，一个一个插入就好，剩下每处理完的链表直接放队尾，$O(\max(m,n))$
4. leetcode 23 合并k个升序列表：最朴素的方法是不停的合并两个有序链表，假设单个链表的长度最大为n，那么时间复杂度为$\sum_{i=1}^{k-1} kn=O(k^2n)$。可以模拟归并排序的做法，采用二分治，这样时间复杂度为$\sum_{i=1}^{\log k}\frac{k}{2^i}2^{i-1}n=O(k\log k n)$。也可以维护一个规模为k的小根堆，最多插入kn次，删除kn次，时间复杂度为$O(k\log kn)$。
5. leetcode 147 对链表进行插入排序：模拟插入排序，维护一个有序链表（链表末尾指向nullptr），插入n次。要点是在头节点之前设置一个pred节点，方便插入。通过设置一个lastsort指针指向有序链表的最后一个节点，如果待插入节点大于它就直接插入链表末尾不用搜索，可以加速。
6. leetcode 148 排序链表：单向链表适合用归并排序，双向链表适合快速排序。这里采用自顶向下的递归实现的归并排序，$O(\log n)$空间，$O(n\log n)$。注意采用快慢指针找链表中点的循环条件与循环链表不同，小心陷入无限循环。可以改进为自底向上的归并排序，达到常数空间。
7. leetcode 41 缺失的第一个整数：首先要明白结果区间为$[1,n+1]$，如果数组包含1-n的元素，那结果就是n+1，否则就是1-n中第一个缺失的元素。使用桶排序，数组可以看作是n个桶，通过交换操作把元素放入对应桶中（i放到num[i-1]）。最后遍历，元素和桶对不上就表示没有这个元素。
7. leetcode 75 颜色划分：一开始想法是计数排序，但是需要遍历两遍。用双指针进行划分，将数组分为小于i，等于i，大于i的三个区间，其中$i=1$。
