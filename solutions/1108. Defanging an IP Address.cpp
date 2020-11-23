class Solution {
public:
    string defangIPaddr(string address) {
        string newS = "";
        for(int i = 0; i < address.length(); i++){
            if(address[i] != '.'){
                newS += address[i];
            }else{
                newS += "[.]";
            }
            
        }
        return newS;
    }
};
