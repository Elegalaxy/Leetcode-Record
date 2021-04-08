class Solution {
public:
    void backtrack(int index, string& temp, string& digits, vector<string>& res, map<char,string>& mp){
        if(index == digits.length()){
            res.push_back(temp);
            return;
        }
        
        for(char i:mp[digits[index]]){
            temp.push_back(i);
            backtrack(index+1, temp, digits, res, mp);
            temp.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        vector<string> res;
        vector<string> t;
        string temp = "";
        if(!digits.length()) return res;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        backtrack(0, temp, digits, res, mp);
        return res;
    }
};
