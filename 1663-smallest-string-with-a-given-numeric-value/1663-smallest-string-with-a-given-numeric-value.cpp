class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        ans.resize(n);
        for(int i=n-1;i>=0;i--)
        {
            int x=min(26,k-i);
           // int x=(k-i)%26;
            ans[i]=((x-1)+'a');
            k-=x;
        }
        return ans;
    }
};