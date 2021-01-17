class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> result;
        set<string> name;
        map<int,unordered_map<string,int>> m;
        
        for(auto i:orders){
            name.insert(i[2]);
            m[stoi(i[1])][i[2]]++;
        }
        
        vector<string> dish(name.begin(), name.end());
        dish.insert(dish.begin(), "Table");
        result.push_back(dish);
        
        for(auto i:m){
            vector<string> temp;
            temp.push_back(to_string(i.first));
            
            for(auto j:name){
                temp.push_back(to_string(i.second[j]));
            }
            result.push_back(temp);
        }
        
        return result;
    }
};
