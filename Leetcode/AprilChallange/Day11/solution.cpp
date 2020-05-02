/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int &maxn){
        if(root == NULL){
            return 0;
        }
        int l = dfs(root->left, maxn);
        int r = dfs(root->right, maxn);
        maxn = max(maxn, 1 + l + r);
        return 1 + max(l, r);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxn = 0;
        int fin = dfs(root, maxn);
        if(fin > 0){
            maxn--;
        }
        return maxn;
    }
};
