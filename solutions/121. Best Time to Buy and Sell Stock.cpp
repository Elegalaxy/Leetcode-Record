class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
    int small = INT_MAX;
    int profit = 0;
    for(int i = 0; i < len; i++){
        if(prices[i] < small){
            small = prices[i];
        }else if(prices[i] - small> profit){
            profit = prices[i] - small;
        }
    }
    return profit;
    }
};
