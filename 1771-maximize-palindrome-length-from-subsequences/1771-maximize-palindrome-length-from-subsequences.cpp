class Solution {
public:
    int dp[2005][2005];
    int ans=0,n;
    int solve(int l, int r,string &s)
    {
        if(l>r)return 0;
        if(l==r)return 1;
        if(dp[l][r]!=-1)return dp[l][r];
        int len=0;
        if(s[l]==s[r])
        {
            len=2+solve(l+1,r-1,s);
            if(l<n and r>=n)
                ans=max(ans,len);
        }
        else
        {
            len=max(solve(l+1,r,s),solve(l,r-1,s));
        }
        return dp[l][r]=len;
    }
    int longestPalindrome(string w1, string w2) {
        n=w1.size();
        int m=w2.size();
        string s=w1+w2;
        memset(dp,-1,sizeof(dp));
        solve(0,n+m-1,s);
        
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=s.size()-1;j>=0;j--)
        //     {
        //         if(s[i]==s[j] and (i<n and j>=n))
        //         {
        //             ans=max(ans,dp[i][j]);
        //             break;
        //         }
        //     }
        // }
        return ans;
    }
};