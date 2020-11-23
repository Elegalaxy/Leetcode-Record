class Solution {
public:
​
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() < 1){
            return "";
        }
        char comC = ' ';
        int ind = 0;
        string com = "";
        bool brk = false;
        
        int size = strs[0].length();
        for(int i = 1; i < strs.size(); i++){
            if(strs[i].length() < size){
                size = strs[i].length();
                ind = i;
            }
        }
        
        for(int j = 0; j < size; j++){
            comC = strs[ind][j];
            for(int i = 0; i < strs.size(); i++){
                if(strs[i][j] != comC){
                    brk = true;
                    break;
                }
            }
            if(brk == true){
                break;
            }
            com += comC;
        }
        return com;
}
};
