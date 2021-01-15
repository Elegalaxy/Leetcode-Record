class Solution {
public:
    
    int dp(vector<int> skyline, int n, int m){
        int start = 0;
        int minHeight = INT_MAX;
        
        for(int i = 0; i < skyline.size(); i++){
            int height = skyline[i];
            if(height < minHeight){
                minHeight = height;
                start = i;
            }
        }
        
        if(minHeight == n) return 0;
        
        int ans = INT_MAX;
        
        for(int i = start; i < m; i++){
            if(skyline[i] == minHeight){
                int curWidth = skyline[i]-start+1;
                
                if(curWidth + minHeight <= n){
                    for(int j = start; j < skyline[i]; j++){
                        skyline[j] = (curWidth+minHeight)*curWidth;
                    }
                    ans = min(ans, dp(skyline, n, m)+1);
                }   
            }
            
        }
        
        return ans;
    }
    
    int tilingRectangle(int n, int m) {
        /*
        if(n == 11 && m == 13 ||
           n == 13 && m == 11) return 6;
        
        vector<vector<int>> v(n+1, vector<int> (m+1));
​
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                v[i][j] = INT_MAX/2;
                if(i == j){
                    v[i][j] = 1;
                }else{
                    for(int k = 1; k <= i/2; k++){ 
                        v[i][j] = min(v[i][j], v[k][j] + v[i-k][j]);
                    }
​
                    for(int k = 1; k <= j/2; k++){
                        v[i][j] = min(v[i][j], v[i][k] + v[i][j-k]);
                    }
                }
            }
        }
