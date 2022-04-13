class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int dir=0,left=0,right=n-1,top=0,bottom=n-1;
        int i,j=1;
        while(left<=right && top<=bottom)
        {
            if(dir==0)
            {
                for(i=left;i<=right;i++)
                matrix[top][i]=j++;
                top++;
                dir=1;
            }
            else if(dir==1)
            {
                for(i=top;i<=bottom;i++)
                    matrix[i][right]=j++;
                right--;
                dir=2;
            }
            else if(dir==2)
            {
                for(i=right;i>=left;i--)
                    matrix[bottom][i]=j++;
                bottom--;
                dir=3;
                
            }
            else if(dir==3)
            {
                for(i=bottom;i>=top;i--)
                    matrix[i][left]=j++;
                left++;
                dir=0;
            }
        }
        return matrix;
    }
};