class TimeMap {
public:
    /** Initialize your data structure here. */
    map<string, map<int, string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = m.find(key);
        map<int, string>::iterator temp;
        if(it == m.end()) return "";
        else{
            temp = it->second.find(timestamp);
            while(timestamp != 0 && temp == it->second.end()){
                timestamp--;
                temp = it->second.find(timestamp);
            }
        }
        if(!timestamp) return "";
        return temp->second;
    }
};
​
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
