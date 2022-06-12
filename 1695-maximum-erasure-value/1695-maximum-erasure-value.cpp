class Solution {
public:
    // Sliding window + map
    int maximumUniqueSubarray(vector<int>& nums) {
       map<int,int>mp;
        int n=nums.size();
        int ans=0, sum=0;
        for(int i=0,j=0;j<n;j++)
        {
            sum+=nums[j];
            mp[nums[j]]++;
            while(mp[nums[j]]>1)
            {
                mp[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};