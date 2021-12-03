class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        int prevP = nums[0];
        int prev = max(nums[0], nums[1]);
        int cur = prev;
        
        for(int i = 2; i < n; i++){
            cur = max(prev, nums[i]+prevP);
            prevP = prev;
            prev = cur;
        }
        
        return cur;
    }
};
