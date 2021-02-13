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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head = nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;
​
        for(ListNode* root:lists){
            while(root != nullptr){
                pq.push(root->val);
                root = root->next;
            }
        }
        
        if(!pq.empty()){
            head = new ListNode(pq.top());
            pq.pop();
            ListNode* temp = head;
            while(!pq.empty()){
                temp->next = new ListNode(pq.top());
                pq.pop();
                temp = temp->next;
            }
        }
        
        return head;
    }
};
