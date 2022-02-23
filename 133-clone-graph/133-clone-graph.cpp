/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node * curr,unordered_map<Node*,Node*>&hash)
    {
        vector<Node*>adj;  
        
        Node* clone = new Node(curr->val);
        hash[curr]=clone;
        
        for(auto x: curr->neighbors)
        {
            if(hash[x]!=NULL) // use  'hash.find(x)!=hash.end()' for faster performance. 
            {
                adj.push_back(hash[x]);
            }
            else
            {
                adj.push_back(dfs(x,hash));
            }
        }
        clone->neighbors = adj;
        
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        if(node->neighbors.size()==0)
            return new Node(node->val);
        
        unordered_map<Node*,Node*>hash;
        
        return dfs(node,hash); 
    }
};