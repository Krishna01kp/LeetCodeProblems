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
    int m=0,ans=0;
    void solve(TreeNode *root,int depth)
    {
        if(root==NULL)
            return;
        solve(root->left,depth+1);
        if(depth==m)
            ans+=root->val;
        else if(depth>m)
        {
            m=depth;
            ans=root->val;
        }
        solve(root->right,depth+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};