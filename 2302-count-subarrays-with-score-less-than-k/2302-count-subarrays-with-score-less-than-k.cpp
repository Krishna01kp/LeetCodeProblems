class Solution {
public:
    #define ll long long 
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        ll ans=0,sum=0;
        for(int i=0,j=0;j<n;j++)
        {
            sum+=nums[j];
            while(i<n and (sum*(j-i+1))>=k)
            {
                sum-=nums[i++];
            }
            ans+=(j-i+1);
        }
        return ans;
    }
};