class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int size = heights.size()-1;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < size; i++){
            if(heights[i] < heights[i+1]){
                int distance = heights[i+1] - heights[i];
                pq.push(distance);
            }
            
            if(pq.size() > ladders){
                bricks -= pq.top();
                pq.pop();
                
                if(bricks < 0){
                    return i;
                }
            }
        }
        
        return size;
    }
};
