// 方法1，模仿归并排序，分治和并

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeList(lists, 0, lists.size());
    }

    ListNode* mergeList(vector<ListNode*>& lists, int lo, int hi)
    {
        if(lo == hi)
            return nullptr;
        if(lo+1 == hi)
            return lists[lo];
        int mi = (lo+hi)/2;
        ListNode* l1 = mergeList(lists, lo, mi);
        ListNode* l2 = mergeList(lists, mi, hi);
        // merge twe sort list
        ListNode prednode = ListNode(-1);
        ListNode* pred = &prednode;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val <= l2->val)
            {
                pred->next = l1;
                l1 = l1->next;
            }
            else
            {
                pred->next = l2;
                l2 = l2->next;
            }
            pred = pred->next;
        }
        pred->next = l1==nullptr?l2:l1;
        return prednode.next;
    }
};


// 方法2 维护规模为k的小根堆，每次插入堆顶 
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct comp{
        bool operator()(const ListNode* p, const ListNode* q)
        {
            return p->val > q->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comp> heap;
        for(int i=0;i<lists.size();i++)
            if(lists[i]!=nullptr)
                heap.push(lists[i]);
        ListNode prednode = ListNode(-1);
        ListNode* pred = &prednode;
        while(!heap.empty())
        {
            pred->next = heap.top();
            heap.pop();
            pred = pred->next;
            if(pred->next!=nullptr)
                heap.push(pred->next);
        }
        return prednode.next;
    }
};
