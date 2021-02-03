class Solution {
public:
    int mod = 1e9+7;
    
    long long gcd(long long a, long long b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    
    long long lcm(long long a, long long b){
        return (a*b)/gcd(a,b);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long low,high,mid,target;
        long long ab = lcm(a,b);
        
        low = 1;
        high = 1e17;
        
        while(low < high){
            mid = (low+high)/2;
            target = (mid/a) + (mid/b) - (mid/ab);
            
            if(target < n){
                low = mid +1;
            }else{
                high = mid;
            }
        }
        
        return high%mod;
    }
};
