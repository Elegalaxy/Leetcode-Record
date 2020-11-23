class Solution {
public:
    int balancedStringSplit(string s) {
        int pair = 1;
        int count = 0;
        char first = s[0];
        
        for(int i = 1; i < s.length(); i++){            
            if(s[i] != first){
                pair--;
            }else{
                pair++;
            }
            
            if(pair == 0){
                count++;
                i++;
                pair++;
                first = s[i];                
            }
        }
        return count;
    }
};
