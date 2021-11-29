class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> res;
        set<int> st;
        map<int, vector<pair<int, int>>> mp;
        
        st.insert(0);
        st.insert(firstPerson);
        
        for(auto i:meetings){
            mp[i[2]].push_back({i[0], i[1]});
        }
        
        for(auto i:mp){
            for(auto j:i.second){
                if(st.count(j.first)){
                    st.insert(j.second);
                }
                
                if(st.count(j.second)){
                    st.insert(j.first);
                }
            }
            
            for(auto j = i.second.rbegin(); j != i.second.rend(); j++){
                if(st.count((*j).first)){
                    st.insert((*j).second);
                }
                
                if(st.count((*j).second)){
                    st.insert((*j).first);
                }
            }
        }
        
        for(auto i:st){
            res.push_back(i);
        }
        
        return res;
    }
};
