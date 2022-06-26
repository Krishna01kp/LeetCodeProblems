// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>dp;
    int solve(int n, int w, int val[], int wt[])
    {
        if(w<0)return INT_MIN;
        if(dp[w]!=-1)return dp[w];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,val[i]+solve(n,w-wt[i],val,wt));
        }
        return dp[w]=ans;
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        dp.assign(w+5,-1);
        return solve(n,w,val,wt);
        
        // int dp[w+5]={0};
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<=w;j++)
        //     {
        //         if(wt[i]<=j)
        //         {
        //             dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
        //         }
        //     }
        // }
        // return dp[w];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends