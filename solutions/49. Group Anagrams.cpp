class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> temp;
        vector<map<char,int>> freq;
        vector<bool> visited(strs.size(), false);
        
        for(int i = 0; i < strs.size(); i++){
            map<char,int> curr;
            for(char j:strs[i]){
                curr[j]++;
            }
            freq.push_back(curr);
            curr.clear();
        }
        
        for(int i = 0; i < strs.size(); i++){
            if(visited[i]) continue;
            temp.push_back(strs[i]);
            for(int j = i+1; j < strs.size(); j++){
                if(!visited[j] && freq[i] == freq[j]){
                    temp.push_back(strs[j]);
                    visited[j] = true;
                }
            }
            if(!temp.empty())
                res.push_back(temp);
            temp.clear();
        }
        
        return res;
    }
};
