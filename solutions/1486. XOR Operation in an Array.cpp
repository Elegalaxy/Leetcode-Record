class Solution {
public:
    int xorOperation(int n, int start) {
        int sum = start;
        for(int i = 1; i < n; i++){
            sum ^= start+i+i;
        }
        return sum;
    }
};
