// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int dp[1005][1005];
    int solve(int idx, int t, int wt[], int val[], int n)
    {
        if(t<0)return INT_MIN;
        if(t==0 or idx>=n)
        return 0;
        if(dp[idx][t]!=-1)return dp[idx][t];
        int one=solve(idx+1,t-wt[idx],wt,val,n)+val[idx];
        int two=solve(idx+1,t,wt,val,n);
        return dp[idx][t]=max(one,two);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp,-1,sizeof(dp));
       return solve(0,W,wt,val,n);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends