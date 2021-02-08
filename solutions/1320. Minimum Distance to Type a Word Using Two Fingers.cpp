class Solution {
public:
    
    int dist(map<char,pair<int,int>> &m, char a, char b){
        if(a == '!' || b == '!') return 0;
        pair<int,int> A = m[a];
        pair<int,int> B = m[b];
        return (abs(A.first-B.first)+abs(A.second-B.second));
    }
    
    int func(string& word, map<char,pair<int,int>> &m, map<string, int>& memo, int i, char f1, char f2){
        if(i == word.length()) return 0;
        
        string s = to_string(i)+to_string(f1)+to_string(f2);
        if(memo.find(s) != memo.end()){
            return memo[s];
        }
        
        int choice1 = dist(m, f1, word[i]) + func(word, m, memo, i+1, word[i],f2);
        int choice2 = dist(m, f2, word[i]) + func(word, m, memo, i+1, f1, word[i]);
        memo[s] = min(choice1, choice2);
        return memo[s];
    }
    
    int minimumDistance(string word) {
        map<char,pair<int,int>> m;
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 6; j++){
                if(i == 4 && j == 2) break;
                char x = (i*6+j)+'A';
                m[x] = {i,j};
            }
        }
        
        map<string, int> memo;
        return func(word, m, memo, 0, '!', '!');
    }
};
