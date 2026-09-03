class Solution {
public:

// int sum(vector<vector<int>> prefix, int r1, int c1, int r2, int c2)
//         {
//         int total = prefix[r2][c2];

//         if (r1 > 0)
//             total -= prefix[r1 - 1][c2]; 
//         if (c1 > 0)
//             total -= prefix[r2][c1 - 1]; 
//         if (r1 > 0 && c1 > 0)
//             total += prefix[r1 - 1][c1 - 1]; 

//         return total;
//     }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
      vector<vector<int>> ans;  
       int n=mat.size();
        int m=mat[0].size();
        
        ans=mat;
       for(int i=0;i<n;i++)
        {
        for(int j=1;j<m;j++)
         {
            ans[i][j]=ans[i][j-1]+mat[i][j];
          }
        }
       for(int i=1;i<n;i++)
       {
         for(int j=0;j<m;j++)
         {
            ans[i][j]=ans[i-1][j]+ans[i][j];
         }
       }
        int r1, c1, r2,c2;
     
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                r1=max(i-k,0);
                c1=max(j-k,0);
                r2=min(i+k,n-1);
                c2=min(j+k,m-1);
                int sum=ans[r2][c2];
             
             if(r1>0) sum=sum-ans[r1 - 1][c2];
             if(c1>0) sum=sum-ans[r2][c1 - 1];
             if(r1>0&&c1>0) sum=sum+ans[r1 - 1][c1 - 1];
            mat[i][j]=sum;
            }

        }
        return mat;
        
        
    }
};


// class Solution {
// public:
//     vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
//         int m = mat.size(), n = mat[0].size();
//         vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
//         // Step 1: Compute the prefix sum
//         for (int i = 1; i <= m; i++) {
//             for (int j = 1; j <= n; j++) {
//                 prefix[i][j] = mat[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
//             }
//         }

//         vector<vector<int>> result(m, vector<int>(n, 0));

//         // Step 2: Compute block sum using prefix sum
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 int r1 = max(0, i - k), c1 = max(0, j - k);
//                 int r2 = min(m - 1, i + k), c2 = min(n - 1, j + k);
                
//                 // Convert (r2, c2) to 1-based indexing for prefix array
//                 r2++, c2++; 
                
//                 result[i][j] = prefix[r2][c2] 
//                              - prefix[r1][c2] 
//                              - prefix[r2][c1] 
//                              + prefix[r1][c1];
//             }
//         }

//         return result;
//     }
// };
