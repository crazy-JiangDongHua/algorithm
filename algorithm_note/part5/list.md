链表是非常高频的考点，算是那种说难不难，说简单又不好写的题，需要认真学习。

1. 链表的定义

   ```c++
   struct node{
       typename data; //数据域
       node* next;
   }
   ```

2. 创建链表

   ```c++
   node* create(int arr[])
   {
       node* head = new node;
       head->next = nullptr;
       node* p, *pre = head;
       for(int i=0;i<arr.len;i++)
       {
           p = new node;
           p->data = arr[i];
           p->next = nullptr;
           pre->next = p;
           pre = p;
       }
       return head;
   }
   ```

3. 查找元素

   ```c++
   node* search(node* head, int x)
   {
       node* p = head->next;
       while(p!=nullptr)
       {
           if(p->data = x)
               return p;
       }
       return nullptr;
   }
   ```
   
4. 插入元素

   ```c++
   node* insert(node* head, int pos, int x)
   {
       node* pre = head;
       for(int i=0;i<pos-1;i++)
       {
           pre = pre->next;
       }
       node* p = new node;
       p->data = x;
       p->next = pre->next;
       pre->next = p;
       return p;
   }
   ```

5. 删除元素

   ```c++
   bool del(node* head, int x)
   {
       node* p = head->next;
       node* pre = head;
       while(p!=nullptr)
       {
           if(p->data == x)
           {
               pre->next = p->next;
               delete p;
               return true;
           }
           pre = p;
           p = p->next;
       }
       return false;//没找到
   }
   ```

6. 静态链表

   ```c++
   struct node{
       typename data;
       int next
   }nodes[size];
   ```




练习：

1. PAT A1023 Sharing：静态链表，第一个链表先遍历一遍留下标记，第二个链表再遍历一边寻找标记。
2. PAT A1052 Linked List Sorting：静态链表，把有效节点拍到数组左边。注意给出的节点并不都在链表上。
3. leetcode 2 两数相加：简单模拟，类似大数求模，从低位开始加。可以使用原链表节省空间。
4. leetocde 92 反转链表2：简单模拟，这种一般都是加一个头节点解决。逆转链表除了遍历一遍翻转指针以外，还可以使用**头插法**。不管是直接反转还是头插，反转链表的第一个节点都是不用动，从他后面一个节点开始循环。
5. leetcode 86 分隔链表：就分一大一小两个链表插入就行。
6. leetcode 83 删除链表的重复元素：模拟数组删除重复元素就行。
7. leetcode 82 删除链表的重复元素2: 和上一题差不多，简单模拟。
8. leetcode 61 旋转链表：简单模拟，先数链表节点个数，然后做成环，最后从中间断开。
9. leetcode 19 删除链表的倒数第 N 个结点: 双指针，一个先走n步。
10. leetcode 24 两两交换链表中的节点: 简答模拟
11. leetcode 25 K 个一组翻转链表: 简单模拟，
12. leetcode 138 复制带随机指针的链表: 这道题的难点在于，当我们复制链表时候，它的随机指针所指向的节点可能还没有在复制链表中创建。首先我们可以想到的方法是先把复制链表建立起来，然后再去复制随机指针，那么我们就需要把原节点和复制节点关联起来，这就可以用哈希表。当然也可以采用特殊的方法，即将复制节点插入原链表，放在原节点之后，这样原节点与复制节点的关系也对应起来了。上述是迭代的方法，当然我们也可以采用递归回溯的方法。
13. leetcode 143 重排链表:可以先拆分列表，然后反转，再合并。也利用线性表先存链表，然后串起来就行。
14. leetcode 146 LRU cache: 通过哈希表和双头链表实现。