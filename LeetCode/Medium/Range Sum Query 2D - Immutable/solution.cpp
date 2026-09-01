class NumMatrix {
public:
vector<vector<int>> ans;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        ans=matrix;
       for(int i=0;i<n;i++)
       {
        for(int j=1;j<m;j++)
        {
        ans[i][j]=ans[i][j-1]+matrix[i][j];
        }
       }
       for(int i=1;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            ans[i][j]=ans[i-1][j]+ans[i][j];
        }
       }

        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int ans1 = ans[row2][col2];

        if(row1 > 0)
            ans1 -= ans[row1 - 1][col2];

        if(col1 > 0)
            ans1 -= ans[row2][col1 - 1];

        if(row1 > 0 && col1 > 0)
            ans1 += ans[row1 - 1][col1 - 1];

        return ans1;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */