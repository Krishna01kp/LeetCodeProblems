class Solution {
public:
    //Unbounded Knapsac
    string dp[5001] = {};
   string largestNumber(vector<int>& cost, int t) {
        if (t <= 0)
            return t == 0 ? "" : "0";
        if (dp[t].empty()) {
            dp[t] = "0";
            for (int n = 1; n <= 9; ++n) {
                auto res = largestNumber(cost, t - cost[n - 1]);
                if (res != "0" && res.size() + 1 >= dp[t].size())
                    dp[t] = to_string(n) + res;
            }
        }
        return dp[t];
    }
};