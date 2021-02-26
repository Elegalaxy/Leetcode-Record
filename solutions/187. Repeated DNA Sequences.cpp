class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.length() < 10) return res;
        
        map<string, int> m;
        string temp;
        for(int i = 0; i < s.length()-9; i++){
            temp = s.substr(i, 10);
            m[temp]++;
        }
        
        for(auto i = m.begin(); i != m.end(); i++){
            if(i->second > 1){
                res.push_back(i->first);
            }
        }
        
        return res;
    }
};
