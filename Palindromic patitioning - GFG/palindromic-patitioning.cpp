// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[505][505];
bool ispalindrom(int i,int j,string str)
{
    if(i>=j)return true;
    while(i<j)
    {
        if(str[i]!=str[j])
        return false;
        i++,j--;
    }
    return true;
}
int solve(int i, int j, string &str)
{
    if(i>=j)return 0;
    if(ispalindrom(i,j,str))
    return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int left,right;
        if(dp[i][k]!=-1)left=dp[i][k];
        else
        left=solve(i,k,str);
        if(dp[k+1][j]!=-1)right=dp[k+1][j];
        else
        right=solve(k+1,j,str);
        int temp=1+left+right;
        mn=min(temp,mn);
    }
    return dp[i][j]=mn;
}

    int palindromicPartition(string str)
    {
        // code here
        
        int n=str.size();
        memset(dp,-1,sizeof(dp));
        solve(0,n-1,str);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends