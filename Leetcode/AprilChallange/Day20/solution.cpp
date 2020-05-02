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
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int parent = INT_MAX) {
        if(i == (int)preorder.size() || preorder[i] > parent){
            return NULL;
        }
        int currVal = preorder[i++];
        TreeNode* root = new TreeNode(currVal);
        
        // go left till all values are smaller than me.
        root -> left = bstFromPreorder(preorder, currVal);
        
        // go right till all values are greater than me but smaller than my parent (i.e. on left of my parent)
        root -> right = bstFromPreorder(preorder, parent);
        return root;
    }
    
};