class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size(), l,r,mid;
        l=0,r=n-1;
        while(l<=r)
        {
            mid = (l+r)/2;
            if(nums[mid]==target)
                return true;
            if(nums[mid]>nums[l])
            {
                if(target<nums[mid] && target>=nums[l])
                    r=mid-1;
                else
                    l=mid+1;
            }
            else if(nums[mid]<nums[l])
            {
                if(target>nums[mid] && target<=nums[r])
                    l=mid+1;
                else
                    r=mid-1;
            }
            else l+=1;
        }
        return false;
    }
};