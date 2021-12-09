class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vec(n, false);
        queue<int> q;
        
        q.push(start);
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            
            if(arr[t] == 0) return true;
            
            if(vec[t])
                continue;
            
            vec[t] = true;
            int l = t-arr[t], r = t+arr[t];
            
            if(l >= 0)
                q.push(l);
            if(r < n)
                q.push(r);
        }
        
        
        return false;
    }
};
