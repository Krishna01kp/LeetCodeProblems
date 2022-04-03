class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),index1, index2;
        if(n<=1)
            return;
        index1=n-2;
        while(index1>=0 && nums[index1]>=nums[index1+1]) index1--;
        if(index1>=0){
            index2=n-1;
            while(nums[index2]<=nums[index1])index2--;
            swap(nums[index1], nums[index2]);
        }
        reverse(nums.begin() +index1+1, nums.end());
    }
};