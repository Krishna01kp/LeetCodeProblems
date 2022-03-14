class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        string ans="";
        vector<string>res;
        for(int i=0;i<n;i++)
        {
            string temp="";
            while(i<n and path[i]!='/')
                temp.push_back(path[i++]);
            if(temp=="" or temp==".")continue;
            if(temp=="..")
            {
                if(res.size()>0)res.pop_back();
                continue;
            }
            res.push_back(temp);
        }
        if(res.size()==0)return "/";
        for(auto x:res)
            ans+="/"+x;
        return ans;
    }
};