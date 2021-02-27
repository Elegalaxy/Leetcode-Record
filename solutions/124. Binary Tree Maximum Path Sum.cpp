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
    int dfs(TreeNode* root, int& maxx){
        if(root == nullptr) return 0;
        int l = dfs(root->left, maxx);
        int r = dfs(root->right, maxx);
        int cur = max(max(l, r) + root->val, root->val);
        maxx = max(maxx, cur);
        maxx = max(maxx, max(cur, l+r+root->val));
        return cur;
    }
    
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxx = INT_MIN;
        dfs(root, maxx);
        return maxx;
    }
};
