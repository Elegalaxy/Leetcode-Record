class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        if(firstList.size() == 0 || secondList.size() == 0) return result;
        
        int i = 0;
        int j = 0;
        
        while(i < firstList.size() && j < secondList.size()){
            int low = max(firstList[i][0], secondList[j][0]);
            int high = min(firstList[i][1], secondList[j][1]);
            
            if(low <= high){
                vector<int> temp(2);
                temp[0] = low;
                temp[1] = high;
                result.push_back(temp);
            }
            
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        
        return result;
    }
};
