class Solution {
public: 
    int func(vector<int>& boxes, vector<vector<vector<int>>>& dp, int i, int j, int k){
        if(i > j) return 0;
        if(dp[i][j][k] > 0) return dp[i][j][k];
        
        int curr = (k+1)*(k+1) + func(boxes, dp, i+1, j, 0);
        
        for(int c = i+1; c <= j; c++){
            if(boxes[i] == boxes[c]){
                curr = max(curr, func(boxes, dp, i+1, c-1, 0) + func(boxes, dp, c, j, k+1));
            }
        }
        dp[i][j][k] = curr;
        return curr;
    }
    
    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int>>> dp(100, vector<vector<int>>(100, vector<int> (100, 0)));
        int n = boxes.size();
        return func(boxes, dp, 0, n-1, 0);
    }
};
