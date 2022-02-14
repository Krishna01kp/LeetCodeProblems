class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
        }
        vector<int>res;
        int one=sum,zero=0,mx=0;
        
        
        for(int i=0;i<=n;i++)
        {
            int temp=zero + one;
            if(temp>mx)
            {
                mx=temp;
                res={i};
            }
            else if(temp==mx)
            {
                res.push_back(i);
            }
            if(i<n)
            {
                one-=(nums[i]==1);
                zero+=(nums[i]==0);
            }
        }
        return res;
    }
};