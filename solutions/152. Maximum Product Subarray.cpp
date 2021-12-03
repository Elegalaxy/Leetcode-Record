class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int res = nums[0], cur = nums[0], mn = nums[0];
        
        for(int i = 1; i < n; i++){
            if(!nums[i]){
                res = max(nums[i], res);
                cur = 1;
                mn = 1;
            }else{
                int t = cur;
                cur = max(cur*nums[i], max(nums[i], nums[i]*mn));
                mn = min(mn*nums[i], min(t*nums[i], nums[i]));
                res = max(res, cur);
            }
        }
        
        return res;
    }
};
