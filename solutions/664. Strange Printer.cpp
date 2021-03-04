class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> vec(n, vector<int>(n, 0));
        return dp(s, 0, n-1, vec);
    }
    
    int dp(string s, int i, int j, vector<vector<int>>& vec){
        if(i > j) return 0;
        
        if(!vec[i][j]){
            int cur = dp(s, i+1, j, vec)+1;
            for(int k = i+1; k <= j; k++){
                if(s[i] == s[k]){
                    cur = min(cur, dp(s, i, k-1, vec) + dp(s, k+1, j, vec));
                }
            }
            vec[i][j] = cur;
        }
        
        return vec[i][j];
    }
};
