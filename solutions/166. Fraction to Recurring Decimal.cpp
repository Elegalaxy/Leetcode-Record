class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        if(!denominator) return "";
        
        long nt = (long)(numerator);
        long dt = (long)(denominator);
        
        unordered_map<long,int> m;
        string res = "";
        if((numerator > 0 && denominator < 0) || (numerator < 0 && denominator > 0))
            res += '-';
        
        res += to_string(abs(nt/dt));
        long rem = abs(nt%dt);
        
        if(!rem) return res;
        
        res+='.';
        while(rem){
            m[rem] = res.length();
            rem *= 10;
            res += to_string(rem/abs(dt));
            rem %= abs(dt);
            if(m.find(rem) != m.end()){
                res.insert(m[rem],"(");
                res += ')';
                break;
            }
        }
        
        return res;
    }
};
