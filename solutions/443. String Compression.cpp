class Solution {
public:
    int compress(vector<char>& arr) {
        int n = arr.size();
        int cnt = 0, scan = 0, write = 0;
        char cur = ' ';
        
        while(scan <= n){
            if(scan == n || cur != arr[scan]){ //When met different alph                
                if(cnt != 0){ //When this is not first one
                    arr[write] = cur;
                    
                    if(cnt > 1){ //If count larger than 1
                        string c = to_string(cnt);
                        for(char cc:c){
                            arr[++write] = cc;
                        }
                    }
                    
                    write++;
                    
                    if(scan == n){
                        while(write != arr.size())
                            arr.pop_back();
                        
                        return arr.size();
                    }
                }
                
                cur = arr[scan];
                cnt = 1;
            }else{
                cnt++;
            }
            
            scan++;
        }
        
        return arr.size();
    }
};
