class Solution {
public:
    long long int mod=1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        int n=arr.size(),cnt=0;
        if(n<3)
            return 0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            int T=target-arr[i],L=i+1,R=n-1;
            while(L<R)
            {
                int sum=arr[L]+arr[R];
                if(sum<T)
                    L++;
                else if(sum>T)
                    R--;
                else if(arr[L]!=arr[R])
                {
                    int left=1,right=1;
                    while(L<R-1 && (arr[L]==arr[L+1]))
                    {
                        left++;
                        L++;
                    }
                    while(R>L+1 && (arr[R]==arr[R-1]))
                    {
                        right++;
                        R--;
                    }
                    cnt+=(left*right);
                    cnt%=mod;
                    L++;
                    R--;
                }
                else
                {
                    cnt+= (R-L+1)*(R-L)/2;
                    cnt%=mod;
                    break;
                }
            
            }
        }
        return cnt;
    }
};