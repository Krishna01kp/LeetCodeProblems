class Solution {
public:
    int countCollisions(string dir) {
        int n=dir.size(),cnt=0;
        int x=0,y=n-1;
        while(x<n and dir[x]=='L')x++;
        while(y>=0 and dir[y]=='R')y--;
        for(int i=x;i<=y;i++)
        {
            if(dir[i]!='S')cnt++;
        }
        return cnt;
    }
};