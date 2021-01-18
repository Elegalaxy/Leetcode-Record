class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        vector<int>countR(mat.size(), 0), countC(mat[0].size(), 0);
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                countR[i]+=mat[i][j];
            }
        }
        
        for(int i = 0; i < mat[0].size(); i++){
            for(int j = 0; j < mat.size(); j++){
                countC[i]+=mat[j][i];
            }
        }
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1 && countR[i] == 1 && countC[j] == 1) count++;
            }
        }
        
        return count;
    }
};
