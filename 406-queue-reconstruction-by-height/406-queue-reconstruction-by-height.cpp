class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        int n=p.size();
        vector<vector<int>>ans;
        sort(p.begin(),p.end(),[](vector<int>v1,vector<int>v2){
            return v1[0]>v2[0] or (v1[0]==v2[0] and v1[1]<v2[1]);});
        for(auto x:p)
        {
            ans.insert(ans.begin()+x[1],x);
        }
        return ans;
    }
};