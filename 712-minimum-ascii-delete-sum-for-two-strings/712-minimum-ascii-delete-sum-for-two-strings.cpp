class Solution {
public:
    //int dp[1005][1005];
    // int solve(int i,int j,string s1, string s2)
    // {
    //     if(i==s1.size() or j==s2.size())
    //         return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int ans=0;
    //     if(s1[i]==s2[j])
    //     {
    //         ans=s1[i]+solve(i+1,j+1,s1,s2);
    //     }
    //     else
    //     {
    //         ans=max(solve(i+1,j,s1,s2),solve(i,j+1,s1,s2));
    //     }
    //     return dp[i][j]=ans;
    // }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        // memset(dp,-1,sizeof(dp));
        // solve(0,0,s1,s2);
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0) dp[i][j] =0;
                else
                    if(s1[i-1]==s2[j-1])
                        dp[i][j] = dp[i-1][j-1] + s1[i-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int sum=0;
        for(auto s:s1)
            sum+=s;
        for(auto s:s2)
            sum+=s;
        
        return sum-2*dp[n][m];
    }
};