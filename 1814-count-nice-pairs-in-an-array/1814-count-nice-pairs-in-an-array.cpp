class Solution {
public:
    int rev(int x)
    {
        int y=0;
        while(x)
        {
            y=y*10 + x%10;
            x/=10;
        }
        return y;
    }
    int countNicePairs(vector<int>& nums) {
        int res=0, MOD=1e9+7;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(auto x:nums)
        {
            res=(res+mp[x-rev(x)]++)%MOD;
        }
        return res;
    }
};