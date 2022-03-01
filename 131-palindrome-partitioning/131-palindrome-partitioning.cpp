class Solution {
public:
    vector<vector<int>>ispalin;
    vector<vector<string>>res;
    vector<string>ans;
    void solve(int idx,string &str)
    {
        if(idx==str.size())
        {
            res.push_back(ans);
            return;
        }
        string curr="";
        for(int i=idx;i<str.size();i++)
        {
            if(i==idx or (str[idx]==str[i] and (idx+1==i or ispalin[idx+1][i-1])))
            {
                ispalin[idx][i]=1;
            }
            curr+=str[i];
            if(ispalin[idx][i]){
                ans.push_back(curr);
                solve(i+1,str);
                ans.pop_back();
            }
        }
    }
   
    vector<vector<string>> partition(string s) {
        int n=s.size();
        ispalin.resize(n+1,vector<int>(n+1,0));
        solve(0,s);
        return res;
    }
};