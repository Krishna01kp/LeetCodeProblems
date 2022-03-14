class Solution {
public:
    int const MOD=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        long long ans=0;
        int n=nums.size();
        vector<int>fre(n,0);
        for(auto x:req)
        {
            fre[x[0]]++;
            if(x[1]+1<n)
            fre[x[1]+1]--;
        }
        for(int i=1;i<n;i++)
        {
            fre[i]+=fre[i-1];
        }
      
        sort(fre.begin(),fre.end());
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            long long temp=((long)fre[i]*(long)nums[i]);
            temp%=MOD;
            ans+=temp;
            ans%=MOD;
        }
        return ans%MOD;
    }
};