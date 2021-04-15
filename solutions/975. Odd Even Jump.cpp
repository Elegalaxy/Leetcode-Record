class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[n-1][0] = dp[n-1][1] = 1;
        map<int,int> mp;
        mp[arr[n-1]] = n-1;
        int res = 1;
        
        for(int i = n-2; i >= 0; i--){
            auto odd = mp.lower_bound(arr[i]);
            if(odd != mp.end())
                dp[i][0] = dp[odd->second][1];
            
            auto even = mp.upper_bound(arr[i]);
            if(even != mp.begin())
                dp[i][1] = dp[prev(even)->second][0];
            
            if(dp[i][0]) res++;
            mp[arr[i]] = i;
        }
        
        return res;
    }
};
