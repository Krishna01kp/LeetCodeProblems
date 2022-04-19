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
   void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL;
        TreeNode* x = NULL;
        TreeNode* y = NULL;
        
        searchPair(root, pre, x, y);
        if (x == NULL || y == NULL) {
            return;
        }
        int yVal = y->val;
        y->val = x->val;
        x->val = yVal;
}
    
bool searchPair(TreeNode* node, TreeNode*& pre, TreeNode*& x, TreeNode*& y) {
        if (node == NULL) {
            return false;
        }
        if (searchPair(node->left, pre, x, y)) {
            return true;
        }
        if (pre != NULL && node->val < pre->val) {
            y = node;
            if (x == NULL) {
                x = pre;
            } else {
                return true;
            }
        }
        pre = node;
        return searchPair(node->right, pre, x, y);
}
};