class Solution {
public:
    int dp[31][31][31], preSum[31];
    int solve(int l, int r, int piles, int k)
    {
       if(l == r && piles == 1) return dp[l][r][piles] = 0;
       if((r - l + 1 - piles) % (k - 1) != 0)
          return INT_MAX/2;
       int &ret = dp[l][r][piles];
       if(ret!=-1) return ret;
       ret = INT_MAX/2;
       if(piles == 1)
          ret = solve(l, r, k, k) + preSum[r + 1] - preSum[l];
       else
       {
         for(int i = l; i <= r; i++)
         {
           ret = min(ret, solve(l, i, 1, k) + solve(i + 1, r, piles - 1, k));
         }
       }
       return ret;
    }
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        memset(preSum, 0, sizeof preSum);
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++)
            preSum[i + 1] = preSum[i] + stones[i];
        int fin = solve(0, n - 1, 1, K);
        if(fin >= INT_MAX / 2) fin = -1;
        return fin;
    }
};