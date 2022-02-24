// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // int dp[1001][1001];
    // int ans=0;
    // int solve(string s1, string s2, int i, int j)
    // {
    //     if(i>=s1.size() or j>=s2.size())
    //     return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(s1[i]==s2[j])
    //      dp[i][j]=1+solve(s1,s2,i+1,j+1);
    //     else
    //     {
    //         dp[i][j]=0;
    //     }
    //     solve(s1,s2,i+1,j);
    //     solve(s1,s2,i,j+1);
    //     ans=max(ans,dp[i][j]);
    //     return dp[i][j];
    // }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        // memset(dp,-1,sizeof(dp));
        // solve(S1,S2,0,0);
        // return ans;
        int dp[n+1][m+1];
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 or j==0)
                dp[i][j]=0;
                else if(S1[i-1]==S2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends