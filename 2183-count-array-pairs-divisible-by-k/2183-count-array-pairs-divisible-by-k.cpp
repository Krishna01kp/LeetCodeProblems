class Solution {
public:
    #define ll long long
    ll coutPairs(vector<int> &a, int k){
      ll ans=0;
     unordered_map<ll,ll>mp;
     for(int x:a)
     {
         int rem=(k/ __gcd(x,k));
         ans+=mp[rem];
         for(int i=1;i*i<=x;i++)
         {
             if(x%i==0)
             {
                 mp[i]++;
                 if(i*i !=x)
                 {
                     mp[x/i]++;
                 }
             }
         }
      }
     return ans;
 }
};