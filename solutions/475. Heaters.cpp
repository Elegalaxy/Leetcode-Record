class Solution {
public:    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int houseSize = houses.size();
        int heatSize = heaters.size();
        vector<int> result(houseSize, INT_MAX);
        
        for(int i = 0, j = 0; i < houseSize && j < heatSize;){
            if(heaters[j] >= houses[i]){
                result[i] = heaters[j] - houses[i];
                i++;
            }else{
                j++;
            }
        }
        
        for(int i = houseSize-1, j = heatSize-1; i >= 0 && j >= 0;){
            if(heaters[j] <= houses[i]){
                result[i] = min(result[i], houses[i] - heaters[j]);
                i--;
            }else{
                j--;
            }
        }
        
        return *max_element(result.begin(), result.end());
    }
};
