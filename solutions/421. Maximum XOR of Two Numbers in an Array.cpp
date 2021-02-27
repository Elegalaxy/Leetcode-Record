class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, max = 0;
        for(int i = 31; i >= 0; i--){
            mask = mask | (1 << i);
            set<int> s;
            for(int n:nums)
                s.insert(mask & n);
            
            int temp = max | (1 << i);
            for(int pre:s){
                if(s.find(temp ^ pre) != s.end()){
                    max = temp;
                    break;
                }
            }
        }
        
        return max;
    }
};
