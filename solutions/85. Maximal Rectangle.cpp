class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        
        vector<vector<int>> row(n, vector<int>(m)), col(n, vector<int>(m));
        
        for(int j = 0; j < m; j++){
            for(int i = n-1, k = 0; i >= 0; i--){
                if(matrix[i][j] == '1')
                    row[i][j] = ++k;
                else
                    row[i][j] = k = 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = m-1, k = 0; j >= 0; j--){
                if(matrix[i][j] == '1')
                    col[i][j] = ++k;
                else
                    col[i][j] = k = 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int r = row[i][j], c = col[i][j];
                
                for(int k = j+1, l = j+c; k < l; k++){
                    if(r > row[i][k]){
                        res = max(res, r*(k-j));
                        r = row[i][k];
                    }
                }
                
                res = max(res, r*c);
            }
        }
        
        return res;
    }
};
