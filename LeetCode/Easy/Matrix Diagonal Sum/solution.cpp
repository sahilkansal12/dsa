class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int sum=0;
        for (int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i==j)
                {sum+=mat[i][j];}

                if(i+j==c-1)
                {
                    sum+=mat[i][j];
                }

            }
        }
        if(r%2==1){
          int mid=r/2;
        //int midc=c/2;
         sum=sum-mat[mid][mid];
        }   
    return sum; 
    }
};