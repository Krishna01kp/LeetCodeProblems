class Solution {
public:
    //calculate last occurence of 1 using binary search,bcuz lastOccurence+1=countOf(1)
    int lastOcc(vector<int>&a){
        
        int l=0,h=a.size()-1;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(a[mid]==1){
                ans=mid;
                l=mid+1;
            }else if(a[mid]<1){
                h=mid-1;
            }
        }
        return ans;
    }
    vector<int> kWeakestRows(vector<vector<int>>&a, int k) {
        
        int n=a.size();
    
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            int cnt=lastOcc(a[i])+1;
            
            v.push_back({cnt,i});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};