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
        
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> prefix(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {                
                prefix[i][j]=mat[i-1][j-1]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
                
            }

        }
        int r1, c1, r2,c2;
        vector<vector<int>> result(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                r1=max(i-k,0);
                c1=max(j-k,0);
                r2=min(i+k,m-1);
                c2=min(j+k,n-1);
                r1++, r2++,c1++, c2++;
               mat[i][j]=prefix[r2][c2]-prefix[r1 - 1][c2]-prefix[r2][c1 - 1]+prefix[r1 - 1][c1 - 1];
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
