class Solution {
public:
    bool isValid(string s) {
    if(s.length()%2 != 0){
        return false;
    }
​
    int index = 0;
    string array = s;
    for(int i = 0; i < s.length(); i++){
        array[i] = 'a';
    }
​
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            array[index] = s[i];
            index++;
        }else{
            for(int j = array.length()-1; j >= 0; j--){
                if(s[i] == ')' && array[j] == '('){
                    array[j] = 'a';
                    break;
                }else if(s[i] == ']' && array[j] == '['){
                    array[j] = 'a';
                    break;
                }else if(s[i] == '}' && array[j] == '{'){
                    array[j] = 'a';
                    break;
                }else if(array[j] == 'a'){
                    if(j == 0){
                        return false;
                    }
                    continue;
                }else if(j == 1){
                    return false;
                }else{
                    return false;
                }
                
            }
            
        }
    }
    for(int k = 0; k < array.length(); k++){
        if(array[k] != 'a'){
            return false;
