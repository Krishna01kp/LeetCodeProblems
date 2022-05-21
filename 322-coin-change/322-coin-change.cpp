class Solution {
public:
    vector<vector<int>>dp;
    int solve(int n,int amount,vector<int>&coin)
    {
        if(amount==0)return 0;
        if(amount<0 or n==0)return INT_MAX/10;
        if(dp[n][amount]!=-1)return dp[n][amount];
        return dp[n][amount]=min(solve(n-1,amount,coin),solve(n,amount-coin[n-1],coin)+1);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.assign(n+5,vector<int>(amount+5,-1));
        int ans=solve(n,amount,coins);
        return ans>=INT_MAX/10?-1:ans;
    }
};