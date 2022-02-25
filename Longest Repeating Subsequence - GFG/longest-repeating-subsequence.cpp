// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string s2){
		    // Code here
		    string s1=s2;
		    int n=s1.size();
		    int dp[n+1][n+1];
		    for(int i=0;i<=n;i++)
		    {
		        for(int j=0;j<=n;j++)
		        {
		            if(i==0 or j==0)
		            {
		                dp[i][j]=0;
		            }
		            else if(s1[i-1]==s2[j-1] and (i-1!=j-1))
		            {
		                dp[i][j]=1+dp[i-1][j-1];
		            }
		            else
		            dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		        }
		    }
		    return dp[n][n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends