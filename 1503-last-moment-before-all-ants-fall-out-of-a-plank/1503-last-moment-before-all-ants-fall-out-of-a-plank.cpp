class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ma=0;
        for(auto i:right)ma=max(ma,n-i);
        for(auto i:left)ma=max(ma,i);
        return ma;
    }
};