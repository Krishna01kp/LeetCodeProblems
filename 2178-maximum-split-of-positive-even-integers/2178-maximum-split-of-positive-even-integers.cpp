class Solution {
public:
    #define ll long long 
    vector<long long> maximumEvenSplit(long long sum) {
        if(sum%2!=0)return {};
        vector<long long>res;
        ll currs=0,i=2;
        while(currs+i<=sum)
        {
            res.push_back(i);
            currs+=i;
            i+=2;
        }
        int sz=res.size();
        res[sz-1]+=(sum-currs);
        return res;
    }
};