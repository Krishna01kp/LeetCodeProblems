class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        string ans;
        int cnt[26]{};
        int used[26]{};
        for(char c:s)
            cnt[c-'a']++;
        for(int i=0;i<n;i++)
        {
            cnt[s[i]-'a']--;
            if(used[s[i]-'a'])continue;
            while(!ans.empty() and (ans.back()> s[i]) and cnt[ans.back()-'a']){
                used[ans.back()-'a'] = 0;
                ans.pop_back();
                
            }
            if(!used[s[i]-'a'])
            {
                ans.push_back(s[i]);
                used[s[i]-'a']=1;
            }
        }
        return ans;
    }
};