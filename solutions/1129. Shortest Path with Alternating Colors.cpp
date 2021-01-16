class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<pair<int, int>>> g(n); //Index:start, First:end, Second:colour
        queue<pair<int,int>> q; //First: start, Second: colour
        vector<vector<int>> visited(n, vector<int>(2,-1)); //First: visited red, Second: visited blue
        
        for(auto node:red_edges)
            g[node[0]].push_back(make_pair(node[1], 0));
        
        for(auto node:blue_edges)
            g[node[0]].push_back(make_pair(node[1], 1));
        
        visited[0][0] = 0;
        visited[0][1] = 0;
        q.push(make_pair(0,0));
        q.push(make_pair(0,1));
        
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                pair<int, int> curr = q.front();
                q.pop();
                
                for(auto j:g[curr.first]){
                    if(visited[j.first][j.second] == -1 && curr.second != j.second){
                        q.push(j);
                        visited[j.first][j.second] = visited[curr.first][curr.second]+1;
                    }
                }
            }
        }
        
        vector<int> result;
        for(auto i:visited){
            if(min(i[0], i[1]) == -1){
                result.push_back(max(i[0], i[1]));
            }else{
                result.push_back(min(i[0], i[1]));
            }
        }
        
        return result;
    }
};
