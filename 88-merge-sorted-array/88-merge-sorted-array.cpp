class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>num3(n+m);
        int i=0,j=0,k=0;
        while(i<m and j<n)
        {
            if(nums1[i]<nums2[j])
            {
                num3[k++]=nums1[i++];
            }
            else 
                num3[k++]=nums2[j++];
        }
        while(i<m)
            num3[k++]=nums1[i++];
        while(j<n)
            num3[k++]=nums2[j++];
        for(int l=0;l<num3.size();l++)
            nums1[l]=num3[l];
         return;
    }
   
};
