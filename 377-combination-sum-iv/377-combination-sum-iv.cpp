class Solution {
public:
    int dp[1005][205];
    int solve(int i,int t,vector<int>&nums)
    {
        if(i==nums.size() or t<=0) return t==0;
        if(dp[t][i]!=-1)return dp[t][i];
        return dp[t][i]=(solve(i+1,t,nums)+solve(0,t-nums[i],nums));
    }
    int combinationSum4(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,t,nums);
    }
};