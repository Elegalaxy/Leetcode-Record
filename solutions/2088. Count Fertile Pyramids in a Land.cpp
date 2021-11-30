class Solution {
public:
    int func(vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m)), dpr(n, vector<int>(m));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0)
                    continue;
                
                int up, left;
                if(i == 0)
                    up = 0;
                else
                    up = dp[i-1][j];
                
                if(j == 0)
                    left = 0;
                else
                    left = dp[i][j-1];
                
                dp[i][j] = min(up, left) +1;
            }
            
            for(int j = m-1; j >= 0; j--){
                if(grid[i][j] == 0)
                    continue;
                
                int up, right;
                if(i == 0)
                    up = 0;
                else
                    up = dpr[i-1][j];
                
                if(j+1 == m)
                    right = 0;
                else
                    right = dpr[i][j+1];
                
                dpr[i][j] = min(up, right) +1;
            }
        }
        
        int res = 0;
            
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j])
                    res += min(dp[i][j], dpr[i][j])-1;
            }
        }
​
        return res;
    }
    
    int countPyramids(vector<vector<int>>& grid) {
        int res = func(grid);
        reverse(grid.begin(), grid.end());
        res += func(grid);
        return res;
    }
};
