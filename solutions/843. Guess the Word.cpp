/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int getCount(string a, string b){
        int cnt = 0;
        for(int i = 0; i < 6; i++)
            if(a[i] == b[i]) cnt++;
        
        
        return cnt;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for(int i = 0; i < 10; i++){
            string cur = wordlist[rand() % wordlist.size()];
            int cnt = master.guess(cur);
            
            vector<string> vec;
            
            for(string j:wordlist){
                if(getCount(cur, j) == cnt)
                    vec.push_back(j);
            }
            
            wordlist = vec;
        }   
    }
};
