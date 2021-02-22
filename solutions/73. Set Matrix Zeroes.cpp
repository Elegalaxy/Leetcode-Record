class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> temp(c, 0);
        vector<pair<int,int>> zeros;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    zeros.push_back({i,j});
                }
            }
        }
        
        for(int i = 0; i < zeros.size(); i++){
            int f = zeros[i].first, s = zeros[i].second;
            for(int k = 0; k < r; k++){
                matrix[k][s] = 0;
            }
            matrix[f] = temp;
        }
        
    }
};
