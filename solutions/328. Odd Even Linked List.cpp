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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* i = head;
        if(!i || !i->next) return head;
        ListNode* j = head->next;
        
        ListNode* tmp = j;
        
        while((i->next && i->next->next) || (j->next && j->next->next)){
            if(i->next && i->next->next){
                i->next = i->next->next;
                i = i->next;
            }
            
            if(j->next && j->next->next){
                j->next = j->next->next;
                j = j->next;
            }
        }
        
        i->next = tmp;
        j->next = nullptr;
        
        return head;
    }
};
