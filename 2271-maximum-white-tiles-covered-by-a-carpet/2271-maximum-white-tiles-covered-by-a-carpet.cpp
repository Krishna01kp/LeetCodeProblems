class Solution {
public:
    #define ll long long 
    int maximumWhiteTiles(vector<vector<int>>& t, int cl) {
        int n=t.size();
        sort(t.begin(),t.end());
        vector<ll>presum(n+1);
        presum[0]=0;
        vector<int>ep(n);
        for(int i=0;i<n;i++)
        {
            presum[i+1]=presum[i]+(t[i][1]-t[i][0]+1);
            ep[i]=t[i][1];
        }
        ll res=0;
        for(int i=0;i<n;i++)
        {
            int s=t[i][0];
            int e=s+cl-1;
            int idx=upper_bound(ep.begin(),ep.end(),e)-ep.begin();
            ll len=presum[idx]-presum[i];
            if(idx<n and e>=t[idx][0])len+=e-t[idx][0]+1;
            res=max(res,len);
        }
        
        
//         ll len=0,res=0,d=0;
//         for(int i=0,j=0;i<n;i++)
//         {
//             d+=gap[i];
//             len=t[i][1]-t[j][0]+1;
//             //len=min(len,l*1ll);
//             res=max(res,len-d-1);
//             res=min(res,l*1ll);
//             cout<<len<<" "<<d<<endl;
//             while(j<n and t[i][1]-t[j][0]+1>=cl)
//             {
//                 len=t[i][1]-t[j][0];
//                 res=max(res,l-d);
//                 d-=dif[j++];
//             }
            
            
//         }
        return res;
    }
};