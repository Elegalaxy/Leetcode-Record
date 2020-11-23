class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size() < 1){
            return;
        }
        vector<int> nums3(m+n, 0);
        int j = 0, k = 0;
​
        for(int i = 0; i < nums3.size(); i++){
           if(k == n || (nums1[j] < nums2[k] && j < m)){
                nums3[i] = nums1[j];
                j++;
            }else{
                nums3[i] = nums2[k];
                k++;
            }
        }
            nums1 = nums3;
    }
};
