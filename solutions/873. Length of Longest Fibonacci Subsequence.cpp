class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        if(!arr.size()) return 0;
        
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n));
        map<int,int> m;
        
        for(int i = 0; i < n; i++){
            m[arr[i]] = i;
            for(int j = i+1; j < n; j++){
                dp[i][j] = 2;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int next = arr[i] + arr[j];
                if(m.find(next) != m.end()){
                    int ind = m[next];
                    dp[j][ind] = dp[i][j]+1;
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                count = max(count, dp[i][j]);
            }
        }
        
        if(count == 2) return 0;
        return count;
    }
};
