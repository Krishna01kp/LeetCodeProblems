class Solution {
public:
    vector<int>color;
    bool dfs(int u,int c,vector<vector<int>>& adj)
    {
        color[u]=c;
        for(auto v:adj[u])
        {
            if(color[v]==-1)
            {
                if(!dfs(v,c^1,adj))
                {
                    return false;
                }
            }
            else if(color[u]==color[v])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int V=adj.size();
        color.resize(V,-1);
        int ans=1;
        for(int i=0;i<V;i++)
        {
            if(color[i]==-1)
            {
                ans=ans and dfs(i,0,adj);
            }
        }
        return ans;
    }
};