class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0;
        int i = 0;
        
        while(points[i][0] != points[i+1][0] || points[i][1] != points[i+1][1] || i != points.size()){
            if(points[i][0] < points[i+1][0]){
                points[i][0]++;
            }else if(points[i][0] > points[i+1][0]){
                points[i][0]--;
            }
            
            if(points[i][1] < points[i+1][1]){
                points[i][1]++;
            }else if(points[i][1] > points[i+1][1]){
                points[i][1]--;
            }
            
            sum ++;
            if(i < points.size()-1 && points[i][0] == points[i+1][0] && points[i][1] == points[i+1][1] && i < points.size()){
                i++;
                if(i == points.size()-1){
                    break;
                }
            }
        }
        
        return sum;
    }
};
