class Solution {
public:    
    int numDecodings(string s) {
        int p = 1, pp, size = s.size();
        for(int i = size-1; i >= 0; i--){
            int curr;
            if(s[i] == '0') curr = 0;
            else curr = p;
            if(i < size-1 && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) curr += pp;
            pp = p;
            p = curr;
        }
        if(size == 0) return 0;
        return p;
    }
};
