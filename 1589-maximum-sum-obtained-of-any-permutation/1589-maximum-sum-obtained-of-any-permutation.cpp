class Solution {
public:
    int const MOD=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        long long ans=0;
        int n=nums.size();
        vector<int>mp(n,0);
        for(auto x:req)
        {
            mp[x[0]]++;
            if(x[1]+1<n)
            mp[x[1]+1]--;
        }
        for(int i=1;i<mp.size();i++)
        {
            mp[i]+=mp[i-1];
        }
        // vector<int>fre;
        // for(auto m:mp)
        // {
        //     if(m>0)
        //     fre.push_back(m);
        // }
        sort(mp.begin(),mp.end());
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            long long temp=((long)mp[i]*(long)nums[i]);
            temp%=MOD;
            ans+=temp;
            ans%=MOD;
        }
        return ans%MOD;
    }
};