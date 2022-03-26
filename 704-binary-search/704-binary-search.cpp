class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0, e=n-1,mid;
        while(s<=e)
        {
            mid=(s+e)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
                e=mid-1;
            else
                s=mid+1;
        }
        return -1;
    }
};