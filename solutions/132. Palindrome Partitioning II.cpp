class Solution {
public:
    bool palin(string &s, int st, int en){
        while(st < en){
            if(s[st] != s[en]) return false;
            st++;
            en--;
        }
        
        return true;
    }
    
    int func(string &s, int st, int en, vector<vector<int>> &dp){
        if(st >= en || palin(s, st, en))
            return 0;
        
        if(dp[st][en] != -1) return dp[st][en];
            
        int res = INT_MAX;
        for(int i = st; i < en; i++){
            if(palin(s, st, i)){
                int tmp = func(s, i+1, en, dp)+1;
                res = min(res, tmp);
            }
        }
        
        dp[st][en] = res;
        return res;
    }
    
    int minCut(string s) {
        int n = s.length();
        if(n == 1) return 0;
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
​
        return func(s, 0, n-1, dp);;
    }
};
