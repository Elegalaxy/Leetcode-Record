class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> array;
        int len = candies.size();
        int max = *max_element(candies.begin(), candies.end());
        for(int i = 0; i < len; i++){
            if(candies[i] + extraCandies >= max){
                array.push_back(true);
            }else{
                array.push_back(false);
            }
        }
        return array;
    }
};
