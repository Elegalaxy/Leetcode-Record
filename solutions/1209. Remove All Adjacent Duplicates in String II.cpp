class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i = 1, j = 1;
        stack<int> st;
        st.push(0);
        for(i, j; j < s.length(); i++, j++){
            s[i] = s[j];
            if(!i || s[i] != s[i-1]) st.push(i);
            else if(i-st.top()+1 == k){
                i = st.top()-1;
                st.pop();
            }
        }
        
        return s.substr(0, i);
    }
};
