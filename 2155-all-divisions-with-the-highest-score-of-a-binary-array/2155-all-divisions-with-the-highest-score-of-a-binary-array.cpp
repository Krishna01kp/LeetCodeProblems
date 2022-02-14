class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        int presum=nums[0],mx=max(sum,n-sum);
        unordered_map<int,vector<int>>mp;
        mp[sum].push_back(0);
        mp[n-sum].push_back(n);
        for(int i=1;i<n;i++)
        {
            int temp=i-presum +(sum-presum);
            mx=max(mx,temp);
            mp[temp].push_back(i);
            presum+=nums[i];
        }
        vector<int>ans= mp[mx];
       // sort(ans.begin(),ans.end());
        return ans;
    }
};