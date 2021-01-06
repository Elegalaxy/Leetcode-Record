class Solution {
public:
    struct set{
        string s[101] = {""};
        int count = 0;
        void insert(string t){
            for(int i = 0; i <= count; i++){
                if(t == s[i]) return;
            }
            s[count++] = t;
        }
        
    };
    
    string sToM(string s){
        string mos[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        string n = "";
        for(int i = 0; i < s.length(); i++){
            n += mos[s[i] - 'a'];
        }
        return n;
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set mos;
        for(int i = 0; i < words.size(); i++){
            string m = sToM(words[i]);
            mos.insert(m);
        }
        return mos.count;
    }
};
