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
    /*
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> count;
        vector<double> sum;
        dfs(root, 0, sum, count);
        for(int i = 0; i < sum.size(); i++){
            sum[i] = sum[i]/count[i];
        }
        return sum;
    }
    
    void dfs(TreeNode* root, int i, vector<double>& sum, vector<int>& count){
        if(!root) return;
        if(i < sum.size()){
            sum[i] = sum[i]+root->val;
            count[i]++;
        }else{
            sum.push_back(1.0*root->val);
            count.push_back(1);
        }
        dfs(root->left, i+1, sum, count);
        dfs(root->right, i+1, sum, count);
    }*/
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long sum = 0, count = 0;
            queue<TreeNode*> temp;
            while(!q.empty()){
                TreeNode* n = q.front(); q.pop();
                sum += n->val;
                count++;
                if(n->left) temp.push(n->left);
                if(n->right) temp.push(n->right);
            }
            q = temp;
            res.push_back(sum * 1.0 /count);
        }
        return res;
    }
};
