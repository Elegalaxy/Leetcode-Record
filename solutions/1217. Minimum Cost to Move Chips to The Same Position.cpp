class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n = position.size();
        int res = 0, tmp = 0;
        
        for(int i:position){
            if(i%2 == 0)
                res++;
            else
                tmp++;
        }
        
        return min(res, tmp);
    }
};
