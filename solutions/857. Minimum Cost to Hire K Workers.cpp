class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int n = quality.size();
        priority_queue<int> pq;
        double totalWages = INT_MAX;
        multimap<double, int> m;
        
        for(int i = 0; i < n; i++){
            double r = (double)wage[i]/quality[i];
            m.insert({r,quality[i]});
        }
        
        int curr = 0;
        
        for(auto i:m){
            pq.push(i.second);
            curr += i.second;
            cout << pq.top() << endl;
            if(pq.size() > K){
                curr -= pq.top(); pq.pop();
            }
            if(pq.size() == K){
                totalWages = min(totalWages, curr*i.first);
            }
​
        }
        
        return totalWages;
    }
};
