class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        int total,org;
        org = n;
        while(n != 1){
            total = 0;
            while(n != 0){
                total += (n%10)*(n%10);
                n/=10;
            }
            if(s.find(total) != s.end()) return false;
            else s.insert(total);
            n = total;
        }
        return true;
    }
};
