class Solution {
public:
    long long int dp[505][505];
    long long int solve(vector<int>&nums, int l, int r)
    {
        if(l>r)
            return 0LL;
        if(dp[l][r]!=-1)
            return dp[l][r];
        long long int ans=0;
        for(int k=l;k<=r;k++)
        {
            long long temp=solve(nums,l,k-1) + solve(nums,k+1,r)+ (nums[r+1]*nums[l-1]*nums[k]);
        //ans=max(ans,(solve(nums,l,k-1)+solve(nums,k+1,r)+nums[r+1]*nums[l-1]*nums[k]));
            ans=max<long long>(ans,temp);
        }
        return (dp[l][r]=ans);
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        memset(dp,-1,sizeof(dp));
        return solve(nums,1,n);
    }
};