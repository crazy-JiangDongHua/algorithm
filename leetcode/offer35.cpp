/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
private:
    void copy(Node* head){
        Node *node=head, *next=nullptr;
        while(node!=nullptr){
            next=node->next;
            node->next=new Node(node->val);
            node->next->next=next;
            node=next;
        }
    }
    void connextRandom(Node* head){
        Node *node=head, *next=nullptr;
        while(node!=nullptr){
            next=node->next;
            if(node->random!=nullptr)
                next->random=node->random->next;
            node=next->next;
        }
    }
    Node* split(Node* head){
        Node *node=head, *copyHead=nullptr, *copyNode=nullptr;
        if(node!=nullptr){
            copyHead=copyNode=node->next;
            node->next=copyNode->next;
            node=node->next;
        }
        while(node!=nullptr){
            copyNode->next=node->next;
            copyNode=copyNode->next;
            node->next=copyNode->next;
            node=node->next;
        }
        return copyHead;
    }
public:
    Node* copyRandomList(Node* head) {
        copy(head);
        connextRandom(head);
        return split(head);
    }
};