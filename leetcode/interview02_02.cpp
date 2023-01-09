/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class BadInputException:public exception{
    const char* what() const throw(){
        return "Bad Input";
    }
};
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        if(head==nullptr)
            throw BadInputException();
        if(k<=0)
            throw BadInputException();
        ListNode *p1=head, *p2=head;
        for(int i=1;i<k;i++){
            if(p2==nullptr)
                throw BadInputException();
            p2=p2->next;
        }
        while(p2->next!=nullptr){
            p1=p1->next;
            p2=p2->next;
        }
        return p1->val;
    }
};