class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int col = 2;
        vector<int> temp;
        if(rowIndex == 0){
            temp.push_back(1);
            return temp;
        }
        
        for(int i = 1; i <= rowIndex; i++){
            vector<int> vec;
            vec.push_back(1);
            for(int j = 1; j < col-1; j++){
                vec.push_back(temp[j]+temp[j-1]);
            }
            col++;
            vec.push_back(1);
            temp = vec;
        }
        
        return temp;
    }
};
