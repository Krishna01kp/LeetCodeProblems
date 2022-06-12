class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            ans+=mp[sum-goal]; // check the number of subarray with the sum-goal (excess)
            mp[sum]++;
        }
        return ans;
    }
};