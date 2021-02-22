class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*int r = matrix.size();
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
        }*/
        int r = matrix.size();
        int c = matrix[0].size();
        bool col = false;
        
        for(int i = 0; i < r; i++){
            if(matrix[i][0] == 0) col = true;
            
            for(int j = 1; j < c; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < r; i++){
            if(matrix[i][0] == 0){
                for(int k = 0; k < c; k++){
                    matrix[i][k] = 0;
                }
            }
        }
        
        for(int i = 1; i < c; i++){
            if(matrix[0][i] == 0){
                for(int k = 0; k < r; k++){
                    matrix[k][i] = 0;
                }
            }
        }
        
        if(matrix[0][0] == 0){
            for(int i = 0; i < c; i++){
                matrix[0][i] = 0;
            }
        }
        
