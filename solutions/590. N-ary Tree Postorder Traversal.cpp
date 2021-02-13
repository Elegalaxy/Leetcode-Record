/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
​
    Node() {}
​
    Node(int _val) {
        val = _val;
    }
​
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
​
class Solution {
public:
    void func(vector<int>& res, Node* root){
        if(root == nullptr) return;
        
        for(Node* i:root->children){
            func(res, i);
        }
        res.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> res;
        func(res, root);
        return res;
    }
};
