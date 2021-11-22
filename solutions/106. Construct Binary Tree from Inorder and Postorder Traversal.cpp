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
    vector<int> in;
    vector<int> post;
    int curr = 0;
        
    TreeNode* func(int l, int r){
        if(l > r) return nullptr;
        
        int i = 0;
        
        while(in[i] != post[curr])
            i++;
        
        curr--;
        TreeNode* root = new TreeNode(in[i]);
        root->right = func(i+1, r);
        root->left = func(l, i-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder;
        post = postorder;
        curr = postorder.size()-1;
        return func(0, postorder.size()-1);
    }
};
