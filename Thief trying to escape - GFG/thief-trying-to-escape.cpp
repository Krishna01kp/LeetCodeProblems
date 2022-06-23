// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int totalJumps(int X, int Y, int N, int arr[]){
        // code here
        int res=0;
        for(int i=0;i<N;i++)
        {
            if(arr[i]<=X)
            res++;
            else
            {
                res++;
                while(arr[i]-X>0)
                {
                    arr[i]=arr[i]-(X-Y);
                    res++;
                }
                
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int X, Y, N;
        cin>>X>>Y>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.totalJumps(X, Y, N, arr)<<"\n";
    }
    return 0;
}  // } Driver Code Ends