class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(2,vector<int>(amount+1,0));
        dp[0][0]=1;
    
        for(int i=1;i<=amount;i++)
        {
            dp[0][i]=0;
        }
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                dp[flag][j]=dp[flag^1][j];
                if(coins[i-1]<=j)
                {
                    dp[flag][j]+=dp[flag][j-coins[i-1]];
                }
            }
            flag^=1;
        }
        return dp[flag^1][amount];
    }
};