class Solution {
public:
​
    int func(vector<vector<int>>& grid){        
        int n = grid.size();
        if(!n) return 0;
        int count = 0;
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!grid[i][j] || visited[i][j]) continue;
                
                count++;
                if(count > 1) return 2;
                
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                
                int dir[] = {0, 1, 0, -1, 0};
                while(!q.empty()){
                    pair<int,int> cur = q.front(); q.pop();
                    int curI = cur.first, curJ = cur.second;
                    for(int k = 0; k < 4; k++){
                        int newI = curI + dir[k];
                        int newJ = curJ + dir[k+1];
                        if(newI < 0 || newJ < 0 || newI >= n || newJ >= m) continue;
                        if(grid[newI][newJ] && !visited[newI][newJ]){
                            visited[newI][newJ] = true;
                            q.push({newI,newJ});
                        }
                    }
                }
            }
        }
        
        return count;
    }
    
    int minDays(vector<vector<int>>& grid) {
       int n = grid.size(), m = grid[0].size();
        if(!n) return 0;
        
        if(func(grid) != 1) return 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){
                    grid[i][j] = 0;
                    if(func(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }
};
