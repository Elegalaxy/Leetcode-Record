class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> res(2, vector<int>(colsum.size(), 0));
        int total = 0;
        for(int i:colsum) total+=i;
        if(total != upper+lower) return {};
​
        for(int i = 0; i < colsum.size(); i++){
            if(colsum[i] == 1){
                if(!upper && !lower) return {};
                if(upper > lower){
                    res[0][i] = 1;
                    upper--;
                }
                else{
                    res[1][i] = 1;
                    lower--;
                }
            }else if(colsum[i] == 2){
                if(upper+lower < 2 || !lower || !upper) return {};
                if(upper && lower){
                    res[0][i] = 1;
                    res[1][i] = 1;
                    upper--; lower--;
                }
            }
        }
​
        
        return res;
    }
};
