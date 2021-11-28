class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k*2+1 > nums.size()){
            for(int &i:nums)
                i = -1;
            return nums;
        }
        
        vector<int> temp(nums.size(), INT_MAX);
        long sz = k*2+1;
        long cur = 0;
        
        for(int i = 0; i < sz; i++){
            cur += nums[i];
        }
        temp[k] = cur/sz;
​
        for(int i = sz; i < nums.size(); i++){
            cur -= nums[i-k-k-1]; //minus first num
            cur += nums[i]; //plus next num
            temp[i-k] = cur/sz; //store cur avg
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(temp[i] == INT_MAX) nums[i] = -1;
            else nums[i] = temp[i];
        }
            
        
        return nums;
    }
};
