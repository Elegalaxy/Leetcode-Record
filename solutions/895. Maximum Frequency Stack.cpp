class FreqStack {
public:
    unordered_map<int, int> m;
    unordered_map<int, stack<int>> ms;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int x) {
        m[x]++;
        maxFreq = max(maxFreq, m[x]);
        ms[m[x]].push(x);
    }
    
    int pop() {
        if(maxFreq < 0) return -1;
        int cur = ms[maxFreq].top();
        ms[maxFreq].pop();
        m[cur]--;
        if(!ms[maxFreq].size()){
            ms.erase(maxFreq);
            maxFreq--;
        }
        return cur;
    }
};
​
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
