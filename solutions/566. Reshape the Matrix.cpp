class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        if(r*c != row*col) return nums;
        
        vector<vector<int>> v(r,vector<int>(c));
        
        int tempR = 0;
        int tempC = 0;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                v[i][j] = nums[tempR][tempC];
                tempC++;
                if(tempC == col){
                    tempC = 0;
                    tempR++;
                }
            }
        }
        
        return v;
    }
};
