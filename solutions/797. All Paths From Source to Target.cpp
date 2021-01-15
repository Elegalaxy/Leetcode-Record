class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    int target;
    
    void dfs(vector<vector<int>>& graph, int node = 0){
        temp.push_back(node);
        if(node == target){
            result.push_back(temp);
        }else{
            for(auto i:graph[node])
                dfs(graph, i);
        }
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size()-1;
        dfs(graph);
        return result;
    }
};
