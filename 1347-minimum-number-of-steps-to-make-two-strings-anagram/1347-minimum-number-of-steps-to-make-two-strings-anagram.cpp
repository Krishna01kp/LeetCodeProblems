class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        for(auto c:s)
            mp[c]++;
        for(auto c:t)
            mp[c]--;
        int ans=0;
        for(auto m:mp)
        {
            ans+=abs(m.second);
        }
        return (ans+1)/2;
    }
};