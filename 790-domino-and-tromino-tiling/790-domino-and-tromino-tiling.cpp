class Solution {
public:
    const int MOD=1e9+7;
    int dp[1001][2]{};
    long solve(int i, int n, int f)
    {
        if(i>n)return 0;
        if(i==n) return f==0;
        if(dp[i][f])return dp[i][f];
        if(f)
        {
            return dp[i][f]=(solve(i+1,n,0)+solve(i+1,n,1))%MOD;
        }
        return dp[i][f]=(solve(i+2,n,0)+solve(i+1,n,0) + 2*solve(i+2,n,1))%MOD;
    }
    int numTilings(int n) {
        return solve(0,n,0)%MOD;
    }
};