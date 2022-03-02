class Solution {
public:
    int dp[105][10005];
    int solve(int e,int f)
    {
        if(f==0 or f==1)return f;
        if(e==1)return f;
        if(dp[e][f]!=-1)return dp[e][f];
        int ans=INT_MAX,low=0,hig=f,temp=0;
        while(low<=hig)
        {
            int mid=(low+hig)/2;
            int left=solve(e-1,mid-1);
            int right=solve(e,f-mid);
            temp=1+max(left,right);
            if(left < right) 
                low = mid+1;
            else 
                hig = mid-1;
            ans=min(ans,temp);
        }
        return dp[e][f]=ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};