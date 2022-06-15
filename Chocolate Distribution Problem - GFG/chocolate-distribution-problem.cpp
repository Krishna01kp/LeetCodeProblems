// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    if(n==0 or m==0)
    return 0;
    if(n<m)return -1;
    sort(a.begin(),a.end());
    int long long res=INT_MAX,dif;
    for(int i=0;i<n-m+1;i++)
    {
       dif=(a[i+m-1]-a[i]);
       res=min(res,dif);
    }
    return res;
}   
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}  // } Driver Code Ends