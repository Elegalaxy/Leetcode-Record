class Solution {
public:
    
    void func(vector<vector<int>>& matrix, int s){
        int n = matrix.size();
        if(n-s-1 <= s) return;
        int next,temp;
        
        //n = 3, s = 0, i = 0~2
        for(int i = s; i < n-s-1; i++){
            next = matrix[i][n-s-1];
            matrix[i][n-s-1] = matrix[s][i];
            
            temp = next;
            next = matrix[n-s-1][n-i-1];
            matrix[n-s-1][n-i-1] = temp;
         
            temp = next;
            next = matrix[n-i-1][s];
            matrix[n-i-1][s] = temp;
            
            matrix[s][i] = next;
        }
        
        return func(matrix, s+1);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        func(matrix, 0);
    }
};
