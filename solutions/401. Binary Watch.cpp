class Solution {
public:
    vector<int> hrs{1,2,4,8};
    vector<int> mints{1,2,4,8,16,32};
    
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        helper(res, {0,0}, num, 0);
        return res;
    }
    
    void helper(vector<string>& res, pair<int,int> time, int num, int start){
        if(num == 0){
            string s = to_string(time.first) + ":";
            if(time.second < 10) s += "0";
            s += to_string(time.second);
            res.push_back(s);
            return;
        }else{
            for(int i = start; i < hrs.size()+mints.size(); i++){
                if(i < hrs.size()){
                    time.first += hrs[i];
                    if(time.first < 12) helper(res, time, num-1, i+1);
                    time.first -= hrs[i];
                }else{
                    time.second += mints[i-hrs.size()];
                    if(time.second < 60) helper(res, time, num-1, i+1);
                    time.second -= mints[i-hrs.size()];
                }
            }
        }
    }
};
