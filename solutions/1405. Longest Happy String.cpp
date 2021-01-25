class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int,char>> pq;
        if(a) pq.push({a,'a'});
        if(b) pq.push({b,'b'});
        if(c) pq.push({c,'c'});
        
        char prev1 = '.', prev2 = '.';
        
        while(!pq.empty()){
            auto [count1,chr1] = pq.top(); pq.pop();
            if(chr1 == prev1 && chr1 == prev2){
                if(pq.empty()) return s;
​
                auto [count2,chr2] = pq.top(); pq.pop();
                s+=chr2;
                prev1 = prev2;
                prev2 = chr2;
                pq.push({count1,chr1});
​
                if(--count2 > 0) pq.push({count2,chr2});
            }else{
                s+=chr1;
                prev1 = prev2;
                prev2 = chr1;
                if(--count1 > 0) pq.push({count1,chr1});
            }
        }
        
        return s;
    }
};
