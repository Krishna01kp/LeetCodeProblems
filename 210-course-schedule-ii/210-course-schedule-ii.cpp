class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         vector<int>adj[n];
         vector<int>inorder(n,0);
         for(auto p:pre)
         {
            adj[p[1]].push_back(p[0]);
            inorder[p[0]]++;
         }
         vector<int>res;
         queue<int>q;
          for(int i=0;i<n;i++)
          {
              if(inorder[i]==0)
              q.push(i);
          }
          while(!q.empty())
          {
              int u=q.front();
              q.pop();
              res.push_back(u);
              for(auto v:adj[u])
              {
                  if(--inorder[v]==0)
                  q.push(v);
              }
          }
        if(res.size()==n)
            return res;
        return {};
    }
};