class Solution {
public:
    int minimumSwap(string s1, string s2) {
       int cnt_xy=0,cnt_yx=0,n1=s1.size(),n2=s2.size(); 
        if(n1!=n2)
            return -1;
        for(int i=0;i<n1;i++)
        {
            if(s1[i]=='x' && s2[i]=='y')
                cnt_xy++;
            if(s1[i]=='y' && s2[i]=='x')
                cnt_yx++;
        }
        if(cnt_xy%2==0 && cnt_yx%2==0)
            return (cnt_xy/2 + cnt_yx/2);
        if(cnt_xy%2!=0 && cnt_yx%2!=0)
            return (cnt_xy/2 + cnt_yx/2 +2);
        return -1;
    }
};