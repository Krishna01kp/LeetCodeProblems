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
    
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
         TreeNode* root=NULL;
            unordered_map<int ,TreeNode*>m;
        map<int,int>mp;
        
        for(int i=0;i<des.size();i++){
            mp[des[i][1]]++;
            if(!m.count(des[i][0]) and !m.count(des[i][1])){
                TreeNode* p=new TreeNode(des[i][0]);
                root=p;
                if(des[i][2]==0){p->right=new TreeNode(des[i][1]);m[des[i][1]]=p->right;}
                if(des[i][2]==1){p->left=new TreeNode(des[i][1]);m[des[i][1]]=p->left;}
                m[des[i][0]]=p;
            }
            else if(m.count(des[i][0]) and !m.count(des[i][1])){
                
                if(des[i][2]==0){m[des[i][0]]->right=new TreeNode(des[i][1]);m[des[i][1]]=m[des[i][0]]->right;}
                if(des[i][2]==1){m[des[i][0]]->left=new TreeNode(des[i][1]); m[des[i][1]]=m[des[i][0]]->left;}                   
            }
            else  if(!m.count(des[i][0]) and m.count(des[i][1])){
                TreeNode* p=new TreeNode(des[i][0]);
                root=p;
                m[des[i][0]]=p;
                if(des[i][2]==0){p->right=m[des[i][1]];}
                if(des[i][2]==1){p->left=m[des[i][1]];}
            }
            else
            {
                
                if(des[i][2]==0){m[des[i][0]]->right=m[des[i][1]];}
                if(des[i][2]==1){m[des[i][0]]->left=m[des[i][1]];}
                root=m[des[i][0]];
                                    
            }
        }
        for(auto d:des)
        {
            if(mp[d[0]]==0)
                return m[d[0]];
        }
        return root;
    }
};