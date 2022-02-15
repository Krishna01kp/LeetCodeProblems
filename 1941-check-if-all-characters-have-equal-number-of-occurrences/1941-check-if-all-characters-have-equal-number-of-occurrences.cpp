class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int>fre(26,0);
        for(auto c:s)
        {
            fre[c-'a']++;
        }
        int cnt=fre[s[0]-'a'];
        for(auto c:s)
        {
            if(fre[c-'a']!=cnt)return 0;
        }
        return 1;
    }
};