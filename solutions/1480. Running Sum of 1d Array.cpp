class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int current = nums[0];
        for(int i = 1; i < nums.size(); i++){
            current += nums[i];
            nums[i] = current;
        }
        return nums;
    }
};
