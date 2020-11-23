class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int check = 0;
            while(nums[i]!=0){
                nums[i] /= 10;
                check++;
            }
            
            if(check %2 ==0){
                count++;
            }
        }
        return count;
    }
};
