class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n=nums.size();
        int dup,mis;
        for(int i=0;i<n;i++)
        {
            nums[nums[i]%n]+=n;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]/n>=2) //To find Duplicate
                dup=i;
            if(nums[i]/n==0) // To find mising
                mis=i;
            nums[i]%=n;      //Given array is restored
        }
        //cout<<dup<<" "<<mis;
        return dup;
    }
};

