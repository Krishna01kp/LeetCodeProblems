class Solution {
public:
    int dp[10005];
    int solve(int n)
    {
         if (sqrt(n) - floor(sqrt(n)) == 0)
               return 1;
         if (n <= 3)
              return (dp[n]=n);
        if(dp[n]!=-1)
            return dp[n];
         int res = n;
       for (int x = 1; x <= n; x++)
        {
           int temp = x * x;
           if (temp > n)
               break;
           else
             res = min(res, 1 + solve(n - temp));
        }
    return (dp[n]=res);
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};