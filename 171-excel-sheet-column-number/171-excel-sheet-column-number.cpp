class Solution {
public:
    int titleToNumber(string s) {
        int n=s.length();
        int ans=0;
        long long cnt=1;
        for(int i=n-1;i>=0;i--)
        {
            ans+=(s[i]-'A'+1)*cnt;
            cnt*=26;
        }
        return ans;
    }
};