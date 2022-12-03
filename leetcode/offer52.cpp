/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 方法1 两个栈
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> sA, sB;
        while(headA!=nullptr){
            sA.push(headA);
            headA=headA->next;
        }
        while(headB!=nullptr){
            sB.push(headB);
            headB=headB->next;
        }
        ListNode* ans=nullptr;
        while(!sA.empty() && !sB.empty() && sA.top()==sB.top()){
            ans=sA.top();
            sA.pop();
            sB.pop();
        }
        return ans;
    }
};


// 方法2 哈希表
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> ht;
        while(headA!=nullptr){
            ht.insert(headA);
            headA=headA->next;
        }
        while(headB!=nullptr){
            if(ht.count(headB)>0)
                return headB;
            headB=headB->next;
        }
        return nullptr;
    }
};

// 双指针
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // if(headA==nullptr || headB==nullptr)
        //     return nullptr;
        ListNode *pA=headA, *pB=headB;
        while(pA!=pB){
            pA=pA?pA->next:headB;
            pB=pB?pB->next:headA;
        }
        return pA;
    }
};