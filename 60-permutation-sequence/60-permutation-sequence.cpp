class Solution {
public:
    int fact[15];
    void solve(int n)
    {
        fact[0]=1,fact[1]=1;
        for(int i=2;i<=n;i++)
        {
            fact[i]=i*fact[i-1];
        }
    }
    string getPermutation(int n, int k) {
        
        solve(n);
        vector<int>digits;
        for(int i=1;i<=n;i++)
        {
            digits.push_back(i);
        }
        string ans="";
        
        while(n)
        {
            int idx= k/fact[n-1];
            if(k%fact[n-1]==0)idx-=1;
            ans+=to_string(digits[idx]);
            k-=fact[n-1]*idx;
            n--;
            digits.erase(digits.begin()+idx);
        }
        return ans;
    }
};