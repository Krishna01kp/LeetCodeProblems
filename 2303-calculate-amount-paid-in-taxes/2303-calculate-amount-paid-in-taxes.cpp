class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int income) {
        double balance=income;
        double ans=(b[0][0]<balance?b[0][0]:balance)*b[0][1];
        ans/=100;
        balance-=b[0][0];
        for(int i=1;i<b.size();i++)
        {
            if(balance<=0)break;
            double x=(b[i][0]-b[i-1][0]);
            x=(x<balance?x:balance);
            balance-=x;
            x*=b[i][1];
            x/=100;
            ans+=x;
        }
        return ans;
    }
};