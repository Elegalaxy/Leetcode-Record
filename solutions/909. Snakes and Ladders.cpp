class Solution {
public:    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int count = 0, move = n*n;
        vector<bool> visited(n*n+1, false);
        queue<int> q;
        q.push(1);
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int curr = q.front(); q.pop();
                if(curr == n*n) move = min(move, count);
                
                for(int j = 1; j <= 6; j++){
                    int num = curr + j;
                    
                    if(num > n*n) break;
                    if(num == curr) continue;
                        
                    int r = n-(num-1)/n-1;
                    int c;
                    if((n-r)%2 != 0){
                        c = (num-1)%n;
                    }else{
                        c = n-(num-1)%n-1;
                    }
                    if(!visited[num]){
                        visited[num] = true;
                        
                        if(board[r][c] == -1){
                            q.push(num);
                        }else{
                            q.push(board[r][c]);
                        }
                    }
                }
            }
            count++;
        }
        if(move == n*n) return -1;
        return move;
    }
};
