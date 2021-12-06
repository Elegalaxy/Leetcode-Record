class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string t1 = "", t2 = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '#'){
                t1 = t1.substr(0, t1.length()-1);
            }else t1+=s[i];
        }
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '#'){
                t2 = t2.substr(0, t2.length()-1);
            }else t2+=t[i];
        }
        return t1==t2;
    }
};
