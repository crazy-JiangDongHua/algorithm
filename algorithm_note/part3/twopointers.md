双指针真实是五星级考点，我真的不下十次在面经中看到它，而且这个题型真的超级固定，简直是性价比最高的八股文，uu们千万不要漏了这部分。

大致分为四个类：

1. **对撞指针**，代表题

   1. leetcode 167 两数之和2：一个递增的正整数序列和一个整数M，求序列中的两个不同位置的数a和b，使得他们的和正好为M。

      ```c++
      class Solution {
      public:
          vector<int> twoSum(vector<int>& numbers, int target) {
              int lo=0, hi=numbers.size()-1;
              while(lo<hi)
              {
                  int sum = numbers[lo]+numbers[hi];
                  if(sum==target)
                      return {lo+1, hi+1};
                  else if(sum<target)
                      lo++;
                  else
                      hi--;
              }
              return {0,0};
          }
      };
      ```

   2. leetcode 15 三数之和：先排序，遍历第一个数a，剩下两个数就可以看成和为-a的两数之和问题，要注意多个步骤保证不重复。

   3. 区间划分（快速排序，第k大）

      ```c++
      int partition(int A[], int left, int right)
      {
          right--;//[1,n]这样更好处理
          int randid = rand()%(right-left+1) + left;
          swap(nums[randid], nums[left]);
          int temp = A[left];
          while(left < rigth)
          {
              while(left<right && A[right]>temp)
                  right--;
              A[left] = A[right];
              while(left<right && A[left]<=temp)
                  left++;
              A[right]=A[left];
          }
          A[left] = temp;
          return left;
      }
      
      void quicksort(int A[], int left, int right)
      {
          if(right-left<2)
              return;
          int position = partition(A, left, right);
          quicksort(A, left, position);
          quicksort(A, position+1, right);
      }
      ```

   4. leetcode215 数组的第k大元素：利用区间划分思想，第k大就是找pos==n-k的划分，第k小就是找pos==k-1的划分，且递归不用加停止条件，因为必然有解。期望时间复杂度$O(n)$，最坏时间复杂度$O(n^2)$。还可以使用堆，维护k个元素的最小堆插入n次，删除n-k次，堆顶即为第k大；维护n个元素的最大堆删除k-1次，堆顶即为第k大，时间复杂度均为$O(n\log n)$

2. **滑窗指针**，代表题：

   1. LeetCode26:删除有序数组中的重复项

      ```c++
      int removeDuplicates(vector<int>& nums) {
      	int pred=0, last=1;
      	while(last<nums.size())
      	{
      		while(last<nums.size() && nums[pred]==nums[last])
      		last++;
      		if(last<nums.size())
      		{
      			nums[++pred] = nums[last++];
      		}
      	}
      	return pred+1;
      }
      ```
   
   2. 剑指offer 22 求链表倒数第k个元素：先让其中一个指针向前走k步，接着两个指针以同样的速度一起向前进，直到前面的指针走到尽头了，则后面的指针即为倒数第k个元素。

   3. 在快速排序中，除了上述的划分将序列分为两段，还可以采用另外一种划分，将序列划分为三段：小于轴点，等于轴点，大于轴点。这种划分可以应对所有元素都相同的极端情况，注意此时的边界设置为[1,n)。
      ```c++
      pair<int,int> partition(vector<int>& nums, int lo, int hi){
        int id=rand()%(hi-lo)+lo;
        swap(nums[id], nums[lo]);
        int pivot=nums[lo];
        int p0=lo, p1=lo;
        for(int i=lo;i<hi;i++){
            if(nums[i]<pivot){
                swap(nums[i], nums[p0]);
                if(p0<p1)
                    swap(nums[i], nums[p1]);
                p0++;p1++;
            }else if(nums[i]==pivot){
                swap(nums[i], nums[p1++]);
            }
        }
        return {p0,p1};
      }

      void sort(vector<int>& nums, int lo, int hi){
        if(hi-lo<2)
            return;
        pair<int, int> id=partition(nums, lo, hi);
        sort(nums, lo, id.first);
        sort(nums, id.second, hi);
      }
      ```
   
3. **快慢指针**，代表题目：

   1. leetcode141环形链表：

      ```c++
      /**
       * Definition for singly-linked list.
       * struct ListNode {
       *     int val;
       *     ListNode *next;
       *     ListNode(int x) : val(x), next(NULL) {}
       * };
       */
      class Solution {
      public:
          bool hasCycle(ListNode *head) {
              ListNode* slow=head, *fast=head;
              while(slow!=NULL && fast!=NULL)
              {
                  slow = slow->next;
                  fast = fast->next;
                  if(fast == NULL)
                      return false;
                  fast = fast->next;
                  if(slow == fast)
                      return true;
              }
              return false;
          }
      };
      ```

   2. leetcode 142 环形链表2：计算环的起点。当我们判断出链表中存在环，并且知道了两个指针相遇的节点，我们可以让其中任一个指针指向头节点，然后让它俩以慢指针速度前进，再次相遇时所在的节点位置就是环开始的位置。也可以使用哈希表遍历一次，发现重复节点就是环的起点。

   3. 求链表中环的长度：只要相遇后一个不动，另一个前进直到相遇算一下走了多少步就好了

   4. leetcode 876 计算链表的中点：快慢指针从头节点出发，每轮迭代中，快指针向前移动两个节点，慢指针向前移动一个节点，最终当快指针到达终点的时候，慢指针刚好在中间的节点。
        ```c++
        ListNode *slow=head, *fast=head;
        // 此时空链表需要特判，slow指向链表中点。
        // 并保证前段的链表节点数量大于等于后段链表数量，即有两个中点的话，slow指向前一个。
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ```


4. 其他类

   1. 序列合并（归并排序用到），另外有一个空间换时间的方法是一开始就申请和序列一样长的tmp空间，避免在运行过程中反复申请内存。

      ```c++
      int merge(int A[], int B[], int C[], int n, int m)
      {
          int i=0, j=0, cnt=0;
          while(i<n && j<m)
          {
              if(A[i]<=B[j])
                  C[cnt++] = A[i++];
              else
                  C[cnt++] = B[j++];
          }
          while(i<n)
              C[cnt++] = A[i++];
          while(j<m)
              C[cnt++] = B[j++];
          return cnt;
      }
      
      void mergesort(int arr[], int left, int right)
      {
          int mid = (left + right)>>1;
          mergesort(arr, left, mid);
          mergesort(arr, mid, right);
          // 合并左右区间
          int* B = arr+mid, *C = arr+left;
          int* A = new int[mid-left];
          for(int j=0;j<mid-left;j++)
              A[j] = arr[left+j];
          merge(A,B,C,mid-left,right-mid);
      }
      ```


练习：leetcode 912 排序数组

