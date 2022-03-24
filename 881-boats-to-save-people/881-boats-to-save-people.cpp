class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int i=0,j=n-1;
        int cnt=0;
        while(i<=j)
        {
            if((people[i]+people[j])<=limit)
            {
                cnt++;
                i++,j--;
            }
            else if(people[j]<=limit)
            {
                cnt++;
                j--;
            }
            else 
            {
                cnt++;
                i++;
            }
        }
        return cnt;
    }
};