class Solution {
public:
    
    void func(vector<vector<int>>& res, vector<int>& temp, vector<int>& candidates, int target, int ind, int curr){
        if(curr > target) return;
        
        if(curr == target)
            res.push_back(temp);
        
        for(int i = ind; i < candidates.size(); i++){
            temp.push_back(candidates[i]);
            curr += candidates[i];
            func(res, temp, candidates, target, i, curr);
            temp.pop_back();
            curr -= candidates[i];
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
 
        func(res, temp, candidates, target, 0, 0);
        
        return res;
    }
};
