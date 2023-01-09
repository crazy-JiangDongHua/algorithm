/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 方法一 哈希表
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> hash;
        ListNode *prev=nullptr, *cur=head;
        while(cur!=nullptr){
            if(hash.count(cur->val)>0){
                prev->next=cur->next;
                delete cur;
                cur=prev->next;
            }else{
                hash.insert(cur->val);
                prev=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};

// 方法二 遍历
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode *cur=head, *runner;
        while(cur!=nullptr){
            runner=cur;
            while(runner->next!=nullptr){
                if(runner->next->val==cur->val){
                    ListNode* temp=runner->next;
                    runner->next=temp->next;
                    delete temp;
                }else{
                    runner=runner->next;
                }
            }
            cur=cur->next;
        }
        return head;
    }
};
