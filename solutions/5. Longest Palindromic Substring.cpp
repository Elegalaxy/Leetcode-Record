class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++){
            int l1 = center(s, i, i);
            int l2 = center(s, i, i+1);
            int l = max(l1,l2);            
            if(l > end-start){
                start = i-(l-1)/2;
                end = i+l/2;
            }
        }
        
        string res = "";
        for(int i = start; i <= end; i++){
            res+=s[i];
        }
        return res;
    }
    
    int center(string s, int l, int r){
        while(l >= 0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
};
