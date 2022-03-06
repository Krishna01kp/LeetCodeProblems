class Solution {
public:
    #define ll long long 
    #define MOD 1000000007;
    int countOrders(int n) {
        ll dp[n+1];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            ll gap=2*i+1;
            ll curr_way=(gap*gap -gap*(gap-1)/2)%MOD;
            dp[i]=(dp[i-1]*curr_way)%MOD;
        }
        return dp[n-1]%MOD;
    }
};