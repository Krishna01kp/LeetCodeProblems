// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[205][205][2];
int modul=1003;
    int solve(int i,int j,string &s,bool istrue)
    {
        if(i>j)
        return 0;
        if(i==j)
        {
            if(istrue)
            return s[i]=='T';
            else
            return s[i]=='F';
            
        }
        if(dp[i][j][istrue]!=-1)return dp[i][j][istrue];
        int ans=0;
        for(int k=i+1;k<=j-1;k++)
        {
            int lt=solve(i,k-1,s,true);
            int lf=solve(i,k-1,s,false);
            int rt=solve(k+1,j,s,true);
            int rf=solve(k+1,j,s,false);
            if(s[k]=='&')
            {
                if(istrue==true)
                ans+=lt*rt;
                else
                ans+=lf*rf + lt*rf + lf*rt;
            }
            else if(s[k]=='|')
            {
                if(istrue==true)
                ans+=lt*rf + lf*rt + lt*rt;
                else
                ans+=lf*rf;
            }
            else if(s[k]=='^')
            {
                if(istrue)
                ans+=lf*rt + lt*rf;
                else 
                ans+=lf*rf + lt*rt;
            }
        }
        return dp[i][j][istrue]=ans%modul;
    }
    int countWays(int n, string s){
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(0,n-1,s,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends