
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mp[10005]={},dp[10005];
        for(int n:nums)
        {
           mp[n]++;
        }
        dp[0]=0;
        dp[1]=mp[1];
        for(int i=2;i<10005;i++)
        {
            int one=mp[i]*i + dp[i-2];
            int two=dp[i-1];
            dp[i]=max(one,two);
        }
        return dp[10004];
    }
};