class Solution {
public:
    int removePalindromeSub(string s) {
        if(!s.length()) return 0;
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t) return 1;
        int a = 0, b = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a'){
                if(b) return 2;
                a++;
            }else if(s[i] == 'b'){
                if(a) return 2;
                b++;
            }
        }
        return 1;
    }
};
