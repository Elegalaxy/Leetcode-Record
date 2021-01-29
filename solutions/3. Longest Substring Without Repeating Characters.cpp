class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(!n) return 0;
        int i=0,j=0;
        set<char> st;
        int res = 0;
        
        while(j < n){
            if(st.count(s[j]) == 0){
                st.insert(s[j++]);
                res = max(res, (int)st.size());
            }else{
                st.erase(s[i]);
                i++;
            }
        }
        
        return res;
    }
};
