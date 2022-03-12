class Solution {
public:
    int dp[10][2][2];
    int solve(int idx, int c, int f, vector<string>& digits, string s)
    {
        if(idx>=s.size())
            return 1;
        if(dp[idx][c][f]!=-1)return dp[idx][c][f];
        int ans=0;
        if(f)ans+=solve(idx+1,0,f,digits,s);
        if(c)
        {
            for(auto ch:digits)
            {
                if(ch[0]<=s[idx])
                {
                    ans+=solve(idx+1,ch[0]==s[idx],0,digits,s);
                }
            }
        }
        else
        {
            for(auto ch:digits)
            {
                ans+=solve(idx+1,0,0,digits,s);
            }
        }
        return dp[idx][c][f]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s=to_string(n);
        memset(dp,-1,sizeof dp);
        return solve(0,1,1,digits,s)-1;
    }
};