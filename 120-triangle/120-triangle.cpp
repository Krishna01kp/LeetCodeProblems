class Solution {
public:
    // DP bottom up approach
       int minimumTotal(vector<vector<int> > &t) {
        int n = t.size();
        vector<int> res(t.back());
        for (int layer = n-2; layer >= 0; layer--) 
        {
            for (int i = 0; i <= layer; i++) // Check its every 'node'
            {
                // Find the lesser of its two children, and sum the current value in the triangle with it.
                res[i] = min(res[i], res[i+1]) + t[layer][i]; 
            }
        }
        return res[0];
    }
};