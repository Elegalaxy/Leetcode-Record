class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mn = 0, mx = 0;
        int mnc = INT_MAX, mxc = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > mxc){
                mxc = nums[i];
                mx = i;
            }
            
            if(nums[i] < mnc){
                mnc = nums[i];
                mn = i;
            }
        }
        
        int res = 0;
        res = min(r-mn, l+mn) + min(r-mx, l+mx)+2;
        
        int two = min(max(l+mn, l+mx), max(r-mx, r-mn))+1;
        res = min(res, two); 
        return res;
    }
};
