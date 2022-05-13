class Solution {
public:
    int n;
    vector<vector<int>>res;
    void solve(vector<int>&nums, int indx)
    {
        if(indx==n)
        {
            res.push_back(nums);
            return;
        }
        vector<int>seen(20,0);
        for(int i=indx;i<n;i++)
        {
            if(!seen[nums[i]+10]){
                swap(nums[i],nums[indx]);
                solve(nums,indx+1);
                swap(nums[i],nums[indx]);
                seen[nums[i]+10]=1;
            }
           
        } 
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        if(n<2) return {nums};
        //seen.resize(20,0);
        solve(nums,0);
        return res;
    }
};