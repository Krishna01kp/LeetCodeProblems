class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int>preSum(n,0),postSum(n,0);
        int maxi=arr[0];
        preSum[0]=arr[0],postSum[n-1]=arr[n-1];
        int sum=arr[0];
        for(int i=1;i<n;i++)
        {
            //sum+=arr[i];
            preSum[i]=max(preSum[i-1]+arr[i],arr[i]);
            maxi=max(preSum[i],maxi);
        }
        for(int i=n-2;i>=0;i--)
        {
            postSum[i]=max(postSum[i+1]+arr[i],arr[i]);
            maxi=max(postSum[i],maxi);
        }
        int mx=INT_MIN;
        for(int i=1;i<n-1;i++)
        {
            mx=max(mx,preSum[i-1]+postSum[i+1]);
        }
        return max(mx,maxi);
    }
};