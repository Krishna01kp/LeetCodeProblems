class Solution {
public:
    string longestPalindrome(string S) {
        int n=S.size();
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        int max_len=1,start=0;
        
        // fill all diagonal elements
        for(int i=0;i<n;i++)
        dp[i][i]=1;
        
        // for all 2 length strings
        for(int i=0;i<n-1;i++)
        {
            if(S[i]==S[i+1])
            {
                dp[i][i+1]=1;
                if(2>max_len)
                {
                    max_len=2;
                    start=i;
                }
                
            }
        }
        
        // for rest of substrings
        for(int k=3;k<=n;k++)  // k gives length of substring 
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(dp[i+1][j-1] && (S[i]==S[j]))
                {
                    dp[i][j]=1;
                   if(k>max_len)
                   {
                        max_len=k;
                        start=i;
                   }
                }
            }
        }
        return S.substr(start,max_len);
    }
};