/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 方法二 栈
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

// 方法三 纯遍历
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
        if(headA==nullptr || headB==nullptr)
            return nullptr;
        int lenA=1, lenB=1;
        ListNode *pA=headA, *pB=headB;
        while(pA->next!=nullptr){
            lenA++;
            pA=pA->next;
        }
        while(pB->next!=nullptr){
            lenB++;
            pB=pB->next;
        }
        if(pA!=pB)
            return nullptr;
        if(lenA>lenB)
            for(int i=0;i<lenA-lenB;i++)
                headA=headA->next;
        else
            for(int i=0;i<lenB-lenA;i++)
                headB=headB->next;
        while(headA!=nullptr && headB!=nullptr && headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};