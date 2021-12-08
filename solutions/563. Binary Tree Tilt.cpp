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
    int res = 0;
    
    int func(TreeNode* root){
        if(!root) return 0;
        
        int l = func(root->left);
        int r = func(root->right);
        int t = abs(l-r);
        res+=t;
        
        return root->val+l+r;
    }
    
    int findTilt(TreeNode* root) {
        func(root);
        return res;
    }
};
