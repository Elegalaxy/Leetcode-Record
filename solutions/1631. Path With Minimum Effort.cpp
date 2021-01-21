class Solution {
public:
    int dirX[4] = {-1,0,1,0}, dirY[4] = {0,-1,0,1};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rSize = heights.size(), cSize = heights[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> dist(rSize,vector<int>(cSize, INT_MAX));
        
        pq.push({0,{0,0}}); //Push start node
        dist[0][0] = 0;
        
        while(!pq.empty()){
            pair<int,pair<int,int>> curr = pq.top(); pq.pop(); //Get top
            int d = curr.first, r = curr.second.first, c = curr.second.second;
            if(r == rSize-1 && c == cSize-1) return d; //Return when current is end node
            
            for(int i = 0; i < 4; i++){
                int tempR = r+dirY[i], tempC = c+dirX[i]; //Get current coordinate
                if(tempR < 0 || tempC < 0 || tempR >= rSize || tempC >= cSize) continue; //Skip when out of bound
                int tempD = max(d, abs(heights[tempR][tempC] - heights[r][c])); //Get max height
                
                if(tempD < dist[tempR][tempC]){ //If current height is smaller
                    dist[tempR][tempC] = tempD; //Update distance
                    pq.push({tempD, {tempR, tempC}}); //Push path with new distance
                }        
            }
        }
        return 0;
    }
};
