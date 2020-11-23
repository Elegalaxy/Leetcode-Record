class Solution {
public:
    string removeOuterParentheses(string S) {
        string newS = "";
        int count = 0;
        int ind = 0;
        for(int i = 0; i < S.length(); i++){
            if(S[i] == '('){
                count++;
            }else{
                count--;
            }
            
            if((count == 1 && S[i] == '(') || (count == 0 && S[i] == ')')){
            continue;
        }else{
            newS += S[i];
        }
        }
        return newS;
    }
};
