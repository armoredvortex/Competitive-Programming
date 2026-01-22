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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return nullptr;
        }
        int sz=0;
        ListNode* temp = head;
        while(true){
            sz++;
            if(temp->next == nullptr){
                temp->next = head;
                break;
            }
            temp = temp->next;
        }

        k = k%sz;
        cout << sz << ' ' << k << '\n';
        temp = head;
        for(int i=0; i<sz-k-1; i++){
            temp = temp->next;
        }
        
        ListNode* ans = temp->next;
        temp->next = nullptr;

        return ans;
    }
};