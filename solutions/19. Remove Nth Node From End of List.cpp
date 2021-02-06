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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dum = new ListNode(0);
        dum->next = head;
        
        ListNode* slow = dum;
        ListNode* fast = dum;
        for(int i = 0; i < n+1; i++){
            fast = fast->next;
        }
        
        while(fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        
        slow->next = slow->next->next;
        
        return dum->next;
    }
};
