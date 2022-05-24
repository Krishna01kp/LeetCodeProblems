class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans=0;
        if(n<2)
            return 0;
        int dp[n+5];
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]=='(')
                dp[i]=0;
            else
            {
                if(s[i-1]=='(')
                    dp[i]=((i-2 >= 0)? dp[i-2] : 0) + 2;
                else
                {
                    if((i-dp[i-1]-1)>=0 && s[i-dp[i-1]-1]=='(')
                        dp[i]=dp[i-1] + 2 + ((i-dp[i-1]-2>=0)?dp[i-dp[i-1]-2]:0);
                    else
                        dp[i]=0;
                }
                    
               } 
              ans=max(ans,dp[i]);
          }
          return ans;  
    }
};