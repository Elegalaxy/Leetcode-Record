class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        char newS[s.length()+1];
        int ind = 0;
        for(int i = 0; i < s.length(); i++){
            newS[indices[i]] = s[i];
        }
        string str = "";
        for(int i = 0; i < s.length(); i++){
            str += newS[i];
        }
        
        return str;
        
    }
};
