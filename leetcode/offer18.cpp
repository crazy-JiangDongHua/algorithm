// 原题，删除最后一个结点的时间复杂度为O(n)，其他为O(1)，均摊分析是O(1)
void DeleteNode(ListNode** pListHead, ListNode* pToBeDelete){
    if(pListHead==nullptr || pToBeDelete==nullptr)
        return;
    // 要删除的不是尾结点
    if(pToBeDelete->next!=nullptr){
        ListNode* pNext=pToBeDelete->next;
        pToBeDelete->val=pNext->val;
        pToBeDelete->next=pNext->next;
        delete pNext;
        pNext=nullptr;
    }
    // 是最后一个，但是链表只有一个元素
    else if(*pListHead==pToBeDelete){
        delete pToBeDelete;
        pToBeDelete=nullptr;
        *pListHead=nullptr;
    }
    // 是最后一个，而且有多个元素，必须从头找起
    else{
        ListNode* pPre=*pListHead;
        while(pPre->next!=pToBeDelete){
            pPre=pPre->next;
        }
        pPre->next=pToBeDelete->next;
        delete pPre;
        pToBeDelete=nullptr;
    }
}


// leetcode 改编
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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode dummy(-1, head), *pre=&dummy;
        while(head!=nullptr && head->val!=val){
            pre=head;
            head=head->next;
        }
        if(head!=nullptr){
            pre->next=head->next;
            // delete head;
            // head=nullptr;
        }
        return dummy.next;
    }
};