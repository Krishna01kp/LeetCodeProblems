class Solution {
public:
    int dp[105];
    int solve(int pos, string s)
    {
        if(pos==s.size())return 1;
        if(s[pos]=='0')return 0;
        if(dp[pos]!=-1)return dp[pos];
        int res=solve(pos+1,s);
        if(pos<s.size()-1 and (s[pos]=='1' or s[pos]=='2' and s[pos+1]<'7'))
        {
            res+=solve(pos+2,s);
        }
        return dp[pos]=res;
    }
    int numDecodings(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        if(n==0)return 0;
        return solve(0,s);
        
    }
};