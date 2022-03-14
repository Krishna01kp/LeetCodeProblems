class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n=arr.size();
        int i=n-2;
        while(i>=0 and arr[i]<=arr[i+1])
        {
            i--;  
        }
        if(i<0)return arr;
        int idx1=i,idx2=i+1;
        for(int j=idx1;j<n;j++)
        {
            if(arr[j]<arr[idx1] and arr[j]>arr[idx2])
            {
                idx2=j;
            }
        }
        
        swap(arr[idx1],arr[idx2]);
        return arr;
    }
};