class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> arr;
        for(int i = 0; i < index.size(); i++){
            if(index[i] == arr.size()){
                arr.push_back(nums[i]);
            }else{
                arr.push_back(0);
                for(int j = arr.size()-1; j > index[i]; j--){
                    arr[j] = arr[j-1];
                }
                arr[index[i]] = nums[i];
            }
        }
        return arr;
    }
};
