class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int count = 0;
        map<string, int> mp, mp2;
        
        for(string i: words1)
            mp[i]++;
        
        for(string i: words2)
            mp2[i]++;
        
        for(auto i:mp)
            if(i.second == 1 && mp2[i.first] == 1)
                count++;
        
        return count;
    }
};
