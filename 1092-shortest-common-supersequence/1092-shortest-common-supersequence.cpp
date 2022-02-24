class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        //DP for LCS
        int n=s1.size(),m=s2.size();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=m;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        
        //Finding LCS string
        string lcs;
        int i=n,j=m;
        while(i>0 && j>0)
        {    
            if(s1[i-1]==s2[j-1])
            {
                lcs+=s1[i-1];
                i--;j--;
            }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])j--;   
                else i--;
            }
        }
        reverse (lcs.begin(),lcs.end());  
        
        //Finding SCS string
        string scs;
        i=0,j=0;
        int k=0;
        while(k<lcs.size())
        {
            if(s1[i]==lcs[k])
            {
                while(j<m and s2[j]!=lcs[k])
                {
                    scs+=s2[j++];
                }
                scs+=lcs[k++];
                i++;
                j++;
            }
            else
            {
                scs+=s1[i++];
            }
        }
        if(i<n)
            scs+=s1.substr(i);
        if(j<m)
            scs+=s2.substr(j);
        return scs;
    }
};