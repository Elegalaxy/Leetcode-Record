class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        
        sort(nums.begin(), nums.end());
        vector<int> temp(3);
        
        int j,k,target;
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            j = i+1, k = nums.size()-1;
            target = -(nums[i]);
            while(j < k){
                int sum = nums[j] + nums[k];
                if(sum > target) k--;
                else if(sum < target) j++;
                else{
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = nums[k];
                    res.push_back(temp);
                    j++;k--;
                    while(k > j && nums[k] == nums[k+1]) k--;
                    while(k > j && nums[j] == nums[j-1]) j++;
                }
            }
        }      
        
        return res;
    }
};
