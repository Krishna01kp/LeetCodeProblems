class Solution {
public:
    unordered_map<string,int>mp;
    bool solve(string s1, string s2)
    {
        if(s1.compare(s2)==0)return true;
        if(s1.size()<=1)return false;
        int n=s1.size();
        string key=s1;
        key.push_back('#');
        key+=s2;
        if(mp.count(key))return mp[key];
        bool flag=false;
        for(int i=1;i<n;i++)
        {
            int cond1,cond2;
            cond1=solve(s1.substr(0,i),s2.substr(n-i,i)) and solve(s1.substr(i,n-i),s2.substr(0,n-i));
            cond2=solve(s1.substr(0,i),s2.substr(0,i)) and solve(s1.substr(i,n-i),s2.substr(i,n-i));
            if(cond1 or cond2)
            {
                flag=true;
                break;
            }
        }
        return mp[key]=flag;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n!=m)return false;
        if(n==0 and m==0)return true;
        mp.clear();
        return solve(s1,s2);
    }
};