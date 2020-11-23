class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        for(int i = 0; i < numRows; i++){
            vector<int> temp;
            for(int j = 0; j < i+1; j++){
                if(j == 0 || j == i){
                    temp.push_back(1);
                }else{
                    temp.push_back((vec[i-1][j] + vec[i-1][j-1]));
                    
                }
            }
            
            vec.push_back(temp);
        }
        return vec;
    }
};
