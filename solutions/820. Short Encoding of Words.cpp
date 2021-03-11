class Solution {
public:
    static bool comp(string& a, string&b){
        return a.size()>b.size();
    }
        
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        string res = words[0]+"#";
        
        for(int i = 1; i < words.size(); i++){
            if(res.find(words[i]+"#") == -1){
                res+=words[i]+"#";
            }
        }
        
        return res.length();
    }
};
