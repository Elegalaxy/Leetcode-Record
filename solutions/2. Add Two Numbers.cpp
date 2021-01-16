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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* total = nullptr;
        ListNode* head;
        int carry = 0;
        
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int d1,d2;
            d1 = d2 = 0;
            
            if(l1 != nullptr) d1 = l1->val;
            else d1 = 0;
            
            if(l2 != nullptr) d2 = l2->val;
            else d2 = 0;
            
            int sum = d1+d2+carry;
            if(total != nullptr){
                total->next = new ListNode(sum%10, nullptr);
                total = total->next;
            }else{
                total = new ListNode(sum%10, nullptr);
                head = total;
            }
            
            carry = sum/10;
            
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        
        return head;
    }
};
