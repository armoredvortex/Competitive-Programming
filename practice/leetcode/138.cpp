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
public:
    Node* copyRandomList(Node* head) {
        
        if(head == nullptr){
            return nullptr;
        }
        unordered_map<Node*, Node*> m;
        Node* newhead = new Node(head->val);
        Node* tmp = head;
        Node* newtmp = newhead;
        m[head] = newhead;
        m[nullptr] = nullptr;

        while(tmp){
            if(tmp->next != nullptr && m[tmp->next] == nullptr){
                Node* newNode = new Node(tmp->next->val);
                newtmp->next = newNode;

                m[tmp->next] = newNode;
            } else {
                newtmp->next = m[tmp->next];
            }
            if(tmp->random != nullptr && m[tmp->random] == nullptr){
                Node* newNode = new Node(tmp->random->val);
                newtmp->random = newNode;

                m[tmp->random] = newNode;
            } else {
                newtmp->random = m[tmp->random];
            }
            
            tmp = tmp->next;
            newtmp = newtmp->next;
        }

        return newhead;
    }
};