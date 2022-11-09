class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0), *pre=&dummy, *tmp=head;
        unordered_map<Node*, Node*> hash;
        while(tmp!=nullptr){
            pre->next=new Node(tmp->val);
            pre=pre->next;
            pre->random=tmp->random;
            hash[tmp]=pre;
            tmp=tmp->next;
        }
        pre=dummy.next;
        while(pre!=nullptr){
            if(pre->random!=nullptr)
                pre->random=hash[pre->random];
            pre=pre->next;
        }
        return dummy.next;
    }
};