// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> nums){
        // code here
        int n=nums.size(),index1, index2;
        if(n<=1)
            return nums;
        index1=n-2;
        while(index1>=0 && nums[index1]>=nums[index1+1]) index1--;
        if(index1>=0){
            index2=n-1;
            while(nums[index2]<=nums[index1])index2--;
            swap(nums[index1], nums[index2]);
        }
        reverse(nums.begin() +index1+1, nums.end());
        return nums;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends