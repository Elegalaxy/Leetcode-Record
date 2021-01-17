class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';
        int l = (1<<n)-1;
        if(k == (l+1)/2) return '1';
        else if(k < (l+1)/2) return findKthBit(n-1,k);
        else return '1'- findKthBit(n-1,l-k+1) +'0';
    }
};
