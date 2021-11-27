class Solution {
public:
    int minimumBuckets(string street) {
        int res = 0;
        int n = street.length();
        vector<bool> taken(n, true);
        
        for(int i = 0; i < n; i++){
            if(street[i] == 'H')
                taken[i] = false; //Get house position
        }
        
        for(int i = 0; i < n; i++){
            if(street[i] == 'H'){
                if(taken[i]) continue;
                
                int l = i-1, r = i+1;
                
                if(r < n && street[r] == '.'){ //Right got place
                    taken[i] = true;
                    res++;
                    
                    if(street[r+1] == 'H') //check common
                        taken[r+1] = true;
                    
                }else if(l >= 0 && street[l] == '.'){
                    taken[i] = true;
                    res++;
                }
            }
        }
        
        for(bool i:taken)
            if(!i) return -1;
        
        return res;
    }
};
