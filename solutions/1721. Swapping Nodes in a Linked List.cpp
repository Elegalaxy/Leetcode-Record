/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1 = head, *n2 = head, *nk;
        while(--k){
            n1 = n1->next;
        }
        
        nk = n1;
        n1 = n1->next;
        while(n1){
            n1 = n1->next;
            n2 = n2->next;
        }
        
        swap(n2->val, nk->val);
        return head;
    }
};
