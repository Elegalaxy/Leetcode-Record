class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        if(!n) return 0;
        vector<vector<int>> vec(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++)
            vec[i][i] = 1;
        
        return dp(s, 0, n-1, vec);
    }
    /*
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
    }*/
    
    int dp(string s, int i, int j, vector<vector<int>>& vec){
        if(vec[i][j] != -1) return vec[i][j];
        
        if(s[j-1] == s[j] || s[i] == s[j]){
            vec[i][j] = dp(s, i, j-1, vec);
        }else if(s[i] == s[i+1]){
            vec[i][j] = dp(s, i+1, j, vec);
        }else{
            vec[i][j] = dp(s, i, j-1, vec)+1;
            for(int k = i+1; k < j; k++){
                if(s[j] == s[k]){
                    vec[i][j] = min(vec[i][j], dp(s, i, k-1, vec)+dp(s, k, j-1, vec));
                }
            }
        }
        
        return vec[i][j];
    }
};
