class Solution {
public:
    //int n;
    int dp[55][55][55][55];
    int solve(int r1,int c1,int r2,int c2,vector<vector<int>>&grid)
    {
       // if(grid[0][0]==-1 || grid[n-1][n-1]==-1)
          //  return 0;
       // int c2=r1-r2+c1;
        if(r1==grid.size()-1 && r2==grid.size()-1 && c1==grid.size()-1)
            return grid[r1][c1];
        if(r1>=grid.size() || r2>=grid.size() || c1>=grid[0].size() ||
           c2>=grid[0].size()|| grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;
        if(dp[r1][c1][r2][c2]!=-1)
            return dp[r1][c1][r2][c2];
        int ans=0;
        ans+=grid[r1][c1];
        if(r1!=r2)
            ans+=grid[r2][c2];
        int one=solve(r1+1,c1,r2+1,c2,grid);
        int two=solve(r1+1,c1,r2,c2+1,grid);
        int three=solve(r1,c1+1,r2+1,c2,grid);
        int four=solve(r1,c1+1,r2,c2+1,grid);
        
        ans+=max(max(one,two),max(three,four));
        
        return (dp[r1][c1][r2][c2]=ans);
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
       // n=grid.size();
       memset(dp,-1,sizeof(dp));
        int ans=solve(0,0,0,0,grid);
        return (ans<0)?0:ans;
    }
};