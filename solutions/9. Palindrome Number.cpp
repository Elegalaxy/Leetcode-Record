class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        int y = 0;
        int num = x;
        while(x != 0){
            if (y > INT_MAX/10 || (y == INT_MAX / 10 && x%10 > 7)) return false;
            if (y < INT_MIN/10 || (y == INT_MIN / 10 && x%10 < -8)) return false;
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if(y == num){
            return true;
        }else{
            return false;
        }
    }
};
