class Solution {
public:
    // Based on BFS, same as rotten orange
    vector<int>dir={0,1,0,-1,0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>res(n,vector(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
                else
                {
                    res[i][j]=-1;
                }
            }
        }
        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+dir[i],nc=c+dir[i+1];
                if(nr<0 or nr>=n or nc<0 or nc>=m or res[nr][nc]!=-1)continue;
                res[nr][nc]=res[r][c]+1;
                q.push({nr,nc});
            }
        }
        return res;
    }
};