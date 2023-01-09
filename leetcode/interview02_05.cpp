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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1), *cur=&dummy;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr){
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+carry;
            cur->next=new ListNode(sum%10);
            carry=sum/10;
            cur=cur->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        if(carry!=0){
            cur->next=new ListNode(carry);
        }
        return dummy.next;
    }
};


// 数字正向排列，用递归
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int length(ListNode* p){
        int len=0;
        while(p!=nullptr){
            len++;
            p=p->next;
        }
        return len;
    }
    ListNode* padzero(ListNode* p, int len){
        if(len<=0)
            return p;
        ListNode* temp;
        while(len--){
            temp=new ListNode(0);
            temp->next=p;
            p=temp;
        }
        return p;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int& carry){
        if(l1==nullptr && l2==nullptr){
            carry=0;
            return nullptr;
        }
        ListNode* ans=addTwoNumbers(l1->next, l2->next, carry);
        int sum=l1->val+l2->val+carry;
        carry=sum/10;
        ListNode* temp=new ListNode(sum%10);
        temp->next=ans;
        return temp;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=length(l1), len2=length(l2);
        ListNode* p1=padzero(l1, len2-len1);
        ListNode* p2=padzero(l2, len1-len2);
        int carry=0;
        ListNode* ans=addTwoNumbers(p1,p2,carry);
        if(carry!=0){
            ListNode* temp=new ListNode(carry);
            temp->next=ans;
            ans=temp;
        }
        return ans;
    }
};