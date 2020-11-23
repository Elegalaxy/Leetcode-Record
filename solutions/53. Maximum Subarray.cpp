class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int current = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(current+nums[i] > nums[i]){
                current += nums[i];
            }else{
                current = nums[i];
            }
            
            if(current > best){
                best = current;
            }
        }
        return best;
    }
};
