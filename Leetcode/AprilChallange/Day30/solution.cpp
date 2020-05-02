/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    set<string> paths;
public:
    void dfs(TreeNode* root, string &s){
        s.push_back(root -> val + '0');
        if(root -> left == NULL && root -> right == NULL){
            paths.insert(s);
        }
        if(root -> left != NULL){
            dfs(root->left, s);
        }
        if(root -> right != NULL){
            dfs(root -> right, s);
        }
        s.pop_back();
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        string s;
        dfs(root, s);
        string f;
        for(int a : arr){
            f.push_back(a + '0');
        }
        return (paths.find(f) != paths.end());
        
    }
};