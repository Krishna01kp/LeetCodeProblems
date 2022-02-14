class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int x=max_element(nums.begin(),nums.end())-nums.begin();
        for(int i=0;i<n;i++)
        {
            if(x==i) continue;
            if(nums[x]<2*nums[i])
                return -1;
        }
        return x;
    }
};