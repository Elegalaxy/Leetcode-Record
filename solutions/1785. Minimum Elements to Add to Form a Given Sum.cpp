class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long total = 0;
​
        for(long i:nums) total+=i;
       long dif = abs(goal-total);
        if(dif%limit != 0) return (dif/limit)+1;
        
        return dif/limit;
    }
};
