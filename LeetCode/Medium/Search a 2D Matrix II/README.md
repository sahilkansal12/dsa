# Search a 2D Matrix II

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | August 26, 2026 |
| **Tags** | Array, Binary Search, Divide and Conquer, Matrix |
| **Link** | [View Problem](https://leetcode.com/problems/search-a-2d-matrix-ii/) |
| **Runtime** | 56 ms |
| **Memory** | 18.7 MB |

## Approach

2D Array searching with Binary Search algorithm

## Problem Description

<p>Write an efficient algorithm that searches for a value <code>target</code> in an <code>m x n</code> integer matrix <code>matrix</code>. This matrix has the following properties:</p>

<ul>
	<li>Integers in each row are sorted in ascending from left to right.</li>
	<li>Integers in each column are sorted in ascending from top to bottom.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg" style="width: 300px; height: 300px;">
<pre><strong>Input:</strong> matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= n, m &lt;= 300</code></li>
	<li><code>-10<sup>9</sup> &lt;= matrix[i][j] &lt;= 10<sup>9</sup></code></li>
	<li>All the integers in each row are <strong>sorted</strong> in ascending order.</li>
	<li>All the integers in each column are <strong>sorted</strong> in ascending order.</li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++ search from top-right
**Author**: [@jianchao-li](https://leetcode.com/jianchao-li/)
**Upvotes**: 605 👍
**Link**: [View Original Post](https://leetcode.com/problems/search-a-2d-matrix-ii/solutions/66139/)

---

Search from the **top-right** element and reduce the search space by one row or column at each time.

```
[[ 1,  4,  7, 11, 15],
 [ 2,  5,  8, 12, 19], 
 [ 3,  6,  9, 16, 22],
 [10, 13, 14, 17, 24],
 [18, 21, 23, 26, 30]]
```

Suppose we want to search for `12` in the above matrix. compare `12` with the top-right element `nums[0][4] = 15`. Since `12 < 15`, `12` cannot appear in the column of `15` since all elements in that column are greater than or equal to `15`. Now we reduce the search space by one column (the last column).

We further compare `12` with the top-right element of the remaining matrix, which is `nums[0][3] = 11`. Since `12 > 11`, `12` cannot appear in the row of `11` since all elements in this row are less than or equal to `11` (the last column has been discarded). Now we reduce the search space by one row (the first row).

We move on to compare `12` with the top-right element of the remaining matrix, which is `nums[1][3] = 12`. Since it is equal to `12`, we return `true`.

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0, r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    }
};
```

</details>
