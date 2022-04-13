class Solution {
public:
    #define MOD 1000000007
    int n,step;
    int dp[501][501];
    int solve(int idx, int k)
    {
        if(k==0) return idx==0;
        if(idx<0 or idx>=n or idx>step or k<0) return 0;
        if(dp[idx][k]!=-1)return dp[idx][k];
        int ans=solve(idx+1,k-1)%MOD;
        ans=(ans+solve(idx,k-1))%MOD;
        ans=(ans+solve(idx-1,k-1))%MOD;
        return dp[idx][k]=ans%MOD;
    }
    int numWays(int steps, int arrLen) {
        n=arrLen,step=steps;
        memset(dp,-1,sizeof dp);
        return solve(0,steps);
    }
};