class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count = 1;
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] == ' '){
                count++;
            }
            
            if(i == 0 || sentence[i-1] == ' '){
                for(int j = 0; j < searchWord.length(); j++){
                    if(sentence[i] == searchWord[j]){
                        if(j == searchWord.length()-1) return count;
                        i++;
                        if(sentence[i] == ' ') count++;
                    }else{
                        break;
                    }
                }
            }
        }
        return -1;
    }
};
