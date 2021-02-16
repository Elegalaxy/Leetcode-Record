class Solution {
public:    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        
        int rStart = 0, rEnd = matrix.size()-1, cStart = 0, cEnd = matrix[0].size()-1;
        
        while(rStart <= rEnd && cStart <= cEnd){
            for(int c = cStart; c <= cEnd; c++)
                res.push_back(matrix[rStart][c]);
            for(int r = rStart+1; r <= rEnd; r++)
                res.push_back(matrix[r][cEnd]);
            
            if(rStart < rEnd && cStart < cEnd){
                for(int c = cEnd-1; c > cStart; c--)
                    res.push_back(matrix[rEnd][c]);
                for(int r = rEnd; r > rStart; r--)
                    res.push_back(matrix[r][cStart]);
            }
            
            rStart++; rEnd--;
            cStart++; cEnd--;
        }
        
        return res;
    }
};
