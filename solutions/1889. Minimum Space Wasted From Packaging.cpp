class Solution {
public:
    int minWastedSpace(vector<int>& p, vector<vector<int>>& b) {
        sort(p.begin(), p.end());
        long res = LONG_MAX;
        long sum = 0l;
        for(long i:p) sum+=i;
        
        for(long i = 0; i < b.size(); i++){
            sort(b[i].begin(), b[i].end());
            
            if(b[i][b[i].size()-1] >= p[p.size()-1]){
                long cur = 0, prev = 0, total = 0;
                for(long j = 0; j < b[i].size(); j++){
                    cur = upper_bound(p.begin() + prev, p.end(), b[i][j]) - p.begin();
                    total += (cur-prev)*b[i][j];
                    prev = cur;
                }
​
                res = min(res, total-sum);
            }
        }
        
        return (res == LONG_MAX)? -1: (res%1000000007);
    }
};
