class Solution {
public:
    int reverse(int x) {
        int num = x;
        int y = 0;
        x = abs(x);
        while(x != 0){
            if (y > INT_MAX/10 || (y == INT_MAX / 10 && x%10 > 7)) return 0;
            if (y < INT_MIN/10 || (y == INT_MIN / 10 && x%10 < -8)) return 0;
            y *= 10;
            y += x %10;
            x /= 10;
        }
        
        if(num < 0){
            y = -(y);
        }
        return y;
    }
};
​
