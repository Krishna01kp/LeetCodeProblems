class Solution {
public:
    #define ll long long 
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans=0;
        int n=nums.size();
        vector<ll>presum(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            presum[i]=presum[i-1]+nums[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            ll temp=-1;
            int l=i,h=n;
            while(l<=h)
            {
                int mid=l+(h-l)/2;
                ll sum=presum[mid]-presum[i-1];
                sum*=(mid-i+1);
                if(sum>=k)h=mid-1;
                else
                {
                    temp=mid;
                    l=mid+1;
                }
            }
            if(temp!=-1)
            ans+=(temp-i+1);
        }
        return ans;
    }
};