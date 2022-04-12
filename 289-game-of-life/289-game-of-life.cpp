class Solution {
public:
    int n,m;
    int solve(vector<vector<int>>& board, int i,int j)
    {
        int ans=0;
         //int dx[]={0,-1,0,1,-1,1,-1,1};
         //int dy[]={1,0,-1,0,-1,-1,1,1};
        int dx[]={-1,0,1,0,-1,1,1,-1,-1};
        for(int k=0;k<8;k++)
        {
            int xx=i+dx[k],yy=j+dx[k+1];
            if(xx>=0 and xx<n and yy>=0 and yy<m)
            if(board[xx][yy] == 1 or board[xx][yy] == 2) 
                ans++;
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cnt=solve(board,i,j);
                if(board[i][j]==0)
                {
                    if(cnt==3)
                        board[i][j]=3;
                }
                else if(board[i][j]==1)
                {
                    if(cnt<2 or cnt>3)
                        board[i][j]=2;      
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board[i][j]%=2;
            }
        }
    }
};