class Solution {
public:
    vector<vector<int>>res;
    vector<bool> visited;
    vector<int> disc;
    vector<int> low;
    int timer=0;
    
    void dfs(int v,vector<int> adj[], int p = -1) {
      visited[v] = true;
      disc[v] = low[v] = timer++;

      for (int child : adj[v]) {
        if (child == p) continue;
        if (visited[child]) {
            low[v] = min(low[v], disc[child]);
        } else {
            dfs(child,adj,v);
            low[v] = min(low[v], low[child]);
            if (low[child] > disc[v])
            {
                vector<int> vec{v,child};
                    res.push_back(vec);
            }
        }
    }
        return;
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto x:connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        visited.resize(n,false);
        disc.resize(n,-1);
        low.resize(n,-1);
        dfs(0,adj);
        return res;
    }
};