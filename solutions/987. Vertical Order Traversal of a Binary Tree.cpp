/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dist(TreeNode* root, int row, int col, map<int, multiset<pair<int,int>>>& temp){
        if(root == nullptr) return;
        temp[col].insert({row, root->val});
        dist(root->left, row+1, col-1, temp);
        dist(root->right, row+1, col+1, temp);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        map<int, multiset<pair<int,int>>> temp;
        dist(root, 0, 0, temp);
        
        for(auto i:temp){
            vector<int> cur;
            for(auto j:i.second){
                cur.push_back(j.second);
            }
            res.push_back(cur);
        }
        
        return res;
    }
};
