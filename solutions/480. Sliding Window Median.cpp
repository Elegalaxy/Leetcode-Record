class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        priority_queue<int> mx;
        priority_queue<int, vector<int>, greater<int> > mn;
        unordered_map<int, int> mp;
        int cur = 0;
        
        while(cur < k){
            mx.push(nums[cur++]);
        }
        
        for(int i = 0; i < k/2; i++){
            mn.push(mx.top());
            mx.pop();
        }
        
        
        while(1){
            res.push_back((k%2)? mx.top(): (((double)mx.top()+(double)mn.top())*0.5));
            
            if(cur >= nums.size())
                break;
            
            int ot = nums[cur-k];
            int in = nums[cur++];
            int bal = 0;
            
            if(ot <= mx.top()) bal--;
            else bal++;
            mp[ot]++;
            
            if(!mx.empty() && in <= mx.top()){
                bal++;
                mx.push(in);
            }else{
                bal--;
                mn.push(in);
            }
            
            if(bal < 0){
                mx.push(mn.top());
                mn.pop();
