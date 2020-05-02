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
public:
    int ans;
    int dfs(TreeNode* root){
        int l = 0, r = 0;
        if(root -> left == NULL && root -> right == NULL){
            ans = max(ans, root->val);
            return root -> val;
        }
        if(root -> left != NULL){
            l = dfs(root -> left);
        }
        if(root -> right != NULL){
            r = dfs(root -> right);
        }
        ans = max(ans, max(0, l) + max(0, r) + root -> val);
        return max({0, l, r}) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        ans = max(ans, dfs(root));
        return ans;
    }
};