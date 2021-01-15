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
    int target;
    
    TreeNode* dfs(TreeNode* root, int v, int d){
        if(target == 1){
            TreeNode *temp = new TreeNode(v, root, nullptr);
            return temp;
        }
        
        if(d == target-2){
            TreeNode *t = root;
            TreeNode *ll = t->left;
            TreeNode *rr = t->right;
            
            TreeNode *l = new TreeNode(v, ll, nullptr); 
            TreeNode *r = new TreeNode(v, nullptr, rr);
​
            t->left = l;
            t->right = r;
            return t;
        }
        d++;
        if(root->left != nullptr) dfs(root->left, v, d);
        if(root->right != nullptr) dfs(root->right, v, d);
        
        return root;
    }
    
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        target = d;
        root = dfs(root, v, 0);
        return root;
    }
};
