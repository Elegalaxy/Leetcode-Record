class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        int t = tickets[k];
        
        for(int i = 0; i <tickets.size(); i++){
            res+=min(t-(i > k), tickets[i]);
        }
        
​
        return res;
​
    }
};
