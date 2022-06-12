class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        int n=p.size();
        if(n<8)return false;
        int l=0,u=0,sp=0,d=0;
       
        for(int i=0;i<n;i++)
        {
            if(i>0 and p[i]==p[i-1])return false;
            if(islower(p[i])) l=1;
            else if(isupper(p[i])) u=1;
            else if(isdigit(p[i])) d=1;
            else sp=1;
        }
        if(l and u and sp and d)return 1;
        return 0; 
    }
};