/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node *root, Node *parent)
    {
        if(!root)return;
        if(parent->right==root)parent=parent->next;
        while(parent)
        {
            if(parent->left and root!=parent->left)
            {
                root->next=parent->left;
                break;
            }
            if(parent->right)
            {
                root->next=parent->right;
                break;
            }
            parent=parent->next;
        }
        dfs(root->right,root);
        dfs(root->left,root);
    }
    Node* connect(Node* root) {
        if(!root)return root;
        dfs(root->right,root);
        dfs(root->left,root);
        return root;
    }
};