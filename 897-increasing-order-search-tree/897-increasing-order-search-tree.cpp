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
   
    void inorder(TreeNode* curr, TreeNode* &prev)
    { 
       if (curr == NULL)
           return;
       inorder(curr->left, prev);
       prev->left = NULL;
       prev->right = curr;
       prev = curr;
       inorder(curr->right, prev);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1);
  
        TreeNode* prev = dummy;
        
        inorder(root, prev);
  
        prev->left = NULL;
        prev->right = NULL;
        TreeNode* ret = dummy->right;
  
        delete dummy;
        return ret;
    }
};