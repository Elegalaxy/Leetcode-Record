class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        
        for(auto i:intervals){
            if(res.empty() || res.back()[1] < i[0]){
                res.push_back(i);
            }else{
                res.back()[1] = max(i[1],res.back()[1]);
            }
        }
        
        return res;
    }
};
