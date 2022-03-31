// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    int isPossible(int max,int s,int A[],int n)
    {
        int curr=0;
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            
            if(curr+A[i]>max)
            {
                cnt++;
                curr=A[i];
                if(cnt>s)return 0;
            }
            else
            {
                curr+=A[i];
            }
        }
        return 1;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int b, int s) 
    {
        //code here
        int left=0,right=0;
        
        for(int i=0;i<b;i++)
        {
            left=max(left,A[i]);
            right+=A[i];
        }
        int ans=-1;
        while(left<=right)
        {
            int mid=(right+left)/2;
            if(isPossible(mid,s,A,b)){
                ans=mid;
                right=mid-1;
                
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends