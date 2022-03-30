class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n=matrix.size(),m=matrix[0].size();
        int i=0,j=m-1;        //Start iterating the matrix from top right corner of the matrix
        while(i<n and j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            if(target>matrix[i][j])
                i++;
            else
                j--;
        }
        return false;
    }
};