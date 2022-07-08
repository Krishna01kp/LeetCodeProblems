// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
     int fun(int price[], int i, int n, vector<vector<int>>&dp)
  {
      if(n==0)
      return 0;
      if(i>=n )
      return 0;
      
      if(dp[i][n]!=-1)
      return dp[i][n];
      
      return dp[i][n]=max(fun(price,i,n-i-1,dp)+price[i], fun(price,i+1, n,dp));
      
  }
  
  
    int cutRod(int price[], int n) {
        
    vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
     return fun(price, 0, n,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends