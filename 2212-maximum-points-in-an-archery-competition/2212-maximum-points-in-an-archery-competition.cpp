class Solution {
public:
    int dp[13][100005];
    int solve(int idx, int cap,vector<int>& arr)
    {
        if(idx==0 or cap==0)return 0;
        if(dp[idx][cap]!=-1)return dp[idx][cap];
        int one=0,two;
        if(arr[idx-1]<cap)
        one=idx-1+solve(idx-1,cap-(arr[idx-1]+1),arr);
        two=solve(idx-1,cap,arr);
        return dp[idx][cap]= max(one,two);
    }
    vector<int> maximumBobPoints(int n, vector<int>& arr) {
        vector<int> res(12,0);
        memset(dp,-1,sizeof dp);
        solve(12,n,arr);
        int bobTotal=dp[12][n];
        int currTotal=0;
        for(int i=12,j=n;i>0 and bobTotal>0;i--)
        {
            if(bobTotal==dp[i-1][j])continue;
            else
            {
                res[i-1]=arr[i-1]+1;
                bobTotal-=(i-1);
                j-=(arr[i-1]+1);
                currTotal+=(arr[i-1]+1);
            }
        }
        if(currTotal < n)
        {
            res[0]=(n-currTotal);
        }
        return res;
    }
};