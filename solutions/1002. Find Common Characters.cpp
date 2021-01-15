class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> result;
        vector<int> m(26,0);
        
        for(auto i:A[0]) m[i-'a']++;
        
        for(int i = 1; i < A.size(); i++){
            vector<int> temp(26, 0);
            bool duplicate = false;
            for(auto j:A[i]) temp[j-'a']++;
            
            for(int j = 0; j < 26; j++){
                if(m[j]){
                    if(temp[j]) duplicate = true;
                    m[j] = min(m[j], temp[j]);
                }
            }
            
            if(!duplicate) return result;
        }
        
        for(int j = 0; j < 26; j++)
            for(int i = 0; i < m[j]; i++){
                string s = "";
                s += (char)('a'+j);
                result.push_back(s);
            } 
            
        return result;
    }
};
