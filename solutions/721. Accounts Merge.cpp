        }else{
            sz[repB]+=sz[repA];
            rep[repA] = repB;
        }
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int accListSz = accounts.size();
        init(accListSz);
        
        unordered_map<string, int> emGp;
        
        for(int i = 0; i < accListSz; i++){
            int accSz = accounts[i].size();
            
            for(int j = 1; j < accSz; j++){
                string em = accounts[i][j];
                string name = accounts[i][0];
                
                if(emGp.find(em) == emGp.end()){
                    emGp[em] = i;
                }else{
                    unionSz(i, emGp[em]);
                }
            }
        }
        
        unordered_map<int, vector<string>> comp;
        for(auto eml:emGp){
            string em = eml.first;
            int group = eml.second;
            comp[findRep(group)].push_back(em);
        }
        
        vector<vector<string>> res;
        for(auto i:comp){
            int g = i.first;
            vector<string> tmp = {accounts[g][0]};
            tmp.insert(tmp.end(), i.second.begin(), i.second.end());
            sort(tmp.begin()+1, tmp.end());
            res.push_back(tmp);
        }
    
            return res;
    }
};
