class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
        int cnt[256]{};
        int ans=0,j=0;
        for(int i=0;i<n;i++)
        {
            cnt[s[i]]++;
            while(cnt[s[i]]>=2)
            {
                cnt[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};