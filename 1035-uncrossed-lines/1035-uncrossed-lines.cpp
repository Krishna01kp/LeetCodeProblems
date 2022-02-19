class Solution {
public:
    // Based on Longest Common Sunsequence
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int dp2[505][505]={0};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    dp2[i][j]=dp2[i-1][j-1]+1;
                else
                    dp2[i][j]=max(dp2[i-1][j],dp2[i][j-1]);
            }
        }
        return dp2[n][m];
    }
};