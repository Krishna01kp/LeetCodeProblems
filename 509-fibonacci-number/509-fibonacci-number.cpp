class Solution {
public:
    int fib(int n) {
        if(n<2)
            return n;
        int dp[35];
        dp[0]=0,dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        // int a=0,b=1,c;
        // for(int i=2;i<=n;i++)
        // {
        //     c=a+b;
        //     a=b;
        //     b=c;
        // }
        // //return fib(n-1)+fib(n-2);
        // return c;
        return dp[n];
    }
};