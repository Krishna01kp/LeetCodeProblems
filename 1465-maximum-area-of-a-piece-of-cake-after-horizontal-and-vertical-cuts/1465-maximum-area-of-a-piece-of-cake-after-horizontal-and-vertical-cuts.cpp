class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int n=hc.size(),m=vc.size();
        int hm,vm;
        hm=max(hc[0],h-hc[n-1]);
        vm=max(vc[0],w-vc[m-1]);
        for(int i=1;i<hc.size();i++)
        {
            hm=max(hm,abs(hc[i]-hc[i-1]));
        }
        hm%=1000000007;
        for(int i=1;i<vc.size();i++)
        {
            vm=max(vm,(vc[i]-vc[i-1]));
        }
        vm%=1000000007;
        return ((long)hm*vm)%1000000007;
    }
};