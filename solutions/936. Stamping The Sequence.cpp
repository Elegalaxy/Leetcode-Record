class Solution {
public:
    int func(string& stamp, string& target, int s){
        int len = stamp.length();
        for(int i = 0; i < stamp.length(); i++){
            if(target[s+i] == '?')
                len--;
            else if(target[s+i] != stamp[i])
                return 0;
        }
        
        if(len)
            fill(target.begin()+s, target.begin()+s+stamp.length(), '?');
        return len;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int n = stamp.length(), m = target.length();
        vector<int> res;
        vector<bool> visited(m, false);
        int total = 0;
        
        while(total < m){
            bool found = false;
            for(int i = 0; i <= m-n; i++){
                if(visited[i]) continue;
                int len = func(stamp, target, i);
                if(!len) continue;
                
                visited[i] = true;
                total+=len;
                res.push_back(i);
                found = true;
            }
            if(!found) return {};
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
