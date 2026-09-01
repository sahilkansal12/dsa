# Range Sum Query 2D - Immutable

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 1, 2026 |
| **Tags** | Array, Design, Matrix, Prefix Sum |
| **Link** | [View Problem](https://leetcode.com/problems/range-sum-query-2d-immutable/) |
| **Runtime** | 20 ms |
| **Memory** | 148.9 MB |

## Problem Description

<p>Given a 2D matrix <code>matrix</code>, handle multiple queries of the following type:</p>

<ul>
	<li>Calculate the <strong>sum</strong> of the elements of <code>matrix</code> inside the rectangle defined by its <strong>upper left corner</strong> <code>(row1, col1)</code> and <strong>lower right corner</strong> <code>(row2, col2)</code>.</li>
</ul>

<p>Implement the <code>NumMatrix</code> class:</p>

<ul>
	<li><code>NumMatrix(int[][] matrix)</code> Initializes the object with the integer matrix <code>matrix</code>.</li>
	<li><code>int sumRegion(int row1, int col1, int row2, int col2)</code> Returns the <strong>sum</strong> of the elements of <code>matrix</code> inside the rectangle defined by its <strong>upper left corner</strong> <code>(row1, col1)</code> and <strong>lower right corner</strong> <code>(row2, col2)</code>.</li>
</ul>

<p>You must design an algorithm where <code>sumRegion</code> works on <code>O(1)</code> time complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/14/sum-grid.jpg" style="width: 415px; height: 415px;">
<pre><strong>Input</strong>
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
<strong>Output</strong>
[null, 8, 11, 12]

<strong>Explanation</strong>
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 200</code></li>
	<li><code>-10<sup>4</sup> &lt;= matrix[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= row1 &lt;= row2 &lt; m</code></li>
	<li><code>0 &lt;= col1 &lt;= col2 &lt; n</code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>sumRegion</code>.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Clean C++ Solution and Explaination - O(mn) space with O(1) time
**Author**: [@haoel](https://leetcode.com/haoel/)
**Upvotes**: 738 👍
**Link**: [View Original Post](https://leetcode.com/problems/range-sum-query-2d-immutable/solutions/75350/)

---

Construct a 2D array `sums[row+1][col+1]`

(**notice**: we add additional blank row `sums[0][col+1]={0}` and blank column `sums[row+1][0]={0}` to remove the edge case checking), so, we can have the following definition 

`sums[i+1][j+1]` represents the sum of area from `matrix[0][0]` to `matrix[i][j]`

To calculate sums, the ideas as below

    +-----+-+-------+     +--------+-----+     +-----+---------+     +-----+--------+
    |     | |       |     |        |     |     |     |         |     |     |        |
    |     | |       |     |        |     |     |     |         |     |     |        |
    +-----+-+       |     +--------+     |     |     |         |     +-----+        |
    |     | |       |  =  |              |  +  |     |         |  -  |              |
    +-----+-+       |     |              |     +-----+         |     |              |
    |               |     |              |     |               |     |              |
    |               |     |              |     |               |     |              |
    +---------------+     +--------------+     +---------------+     +--------------+
    
       sums[i][j]      =    sums[i-1][j]    +     sums[i][j-1]    -   sums[i-1][j-1]   +  

                            matrix[i-1][j-1]

So, we use the same idea to find the specific area\'s sum.



    +---------------+   +---------+----+   +---+-----------+   +---------+----+   +---+----------+
    |               |   |         |    |   |   |           |   |         |    |   |   |          |
    |   (r1,c1)     |   |         |    |   |   |           |   |         |    |   |   |          |
    |   +------+    |   |         |    |   |   |           |   +---------+    |   +---+          |
    |   |      |    | = |         |    | - |   |           | - |      (r1,c2) | + |   (r1,c1)    |
    |   |      |    |   |         |    |   |   |           |   |              |   |              |
    |   +------+    |   +---------+    |   +---+           |   |              |   |              |
    |        (r2,c2)|   |       (r2,c2)|   |   (r2,c1)     |   |              |   |              |
    +---------------+   +--------------+   +---------------+   +--------------+   +--------------+

And we can have the following code

   
    class NumMatrix {
    private:
        int row, col;
        vector<vector<int>> sums;
    public:
        NumMatrix(vector<vector<int>> &matrix) {
            row = matrix.size();
            col = row>0 ? matrix[0].size() : 0;
            sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
            for(int i=1; i<=row; i++) {
                for(int j=1; j<=col; j++) {
                    sums[i][j] = matrix[i-1][j-1] + 
                                 sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
                }
            }
        }
    
        int sumRegion(int row1, int col1, int row2, int col2) {
            return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
        }
    };

</details>
