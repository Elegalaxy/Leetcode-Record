class Solution {
public:
    unordered_map<string, string> m;
    unordered_map<string, int> count;
    string st = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    
    string randStr(){
        string temp = "";
        srand(time(0));
        for(int i = 0; i < 8; i++){
            temp+=st[rand()%62];
        }
        return temp;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code = randStr();
        count[code]++;
        code+=to_string(count[code]);
        m[code] = longUrl;
        return code;
    }
​
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};
​
// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
