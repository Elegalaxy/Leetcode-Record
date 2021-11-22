class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp1, mp2;
        
        for(char i:s)
            mp1[i]++;
        for(char i:t)
            mp2[i]++;
        
        return (mp1==mp2);
    }
};
