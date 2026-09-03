# Stamping the Grid

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | cpp |
| **Solved On** | September 3, 2026 |
| **Tags** | Array, Greedy, Matrix, Prefix Sum |
| **Link** | [View Problem](https://leetcode.com/problems/stamping-the-grid/) |
| **Runtime** | 0 ms |
| **Memory** | 8.6 MB |

## Problem Description

<p>You are given an <code>m x n</code> binary matrix <code>grid</code> where each cell is either <code>0</code> (empty) or <code>1</code> (occupied).</p>

<p>You are then given stamps of size <code>stampHeight x stampWidth</code>. We want to fit the stamps such that they follow the given <strong>restrictions</strong> and <strong>requirements</strong>:</p>

<ol>
	<li>Cover all the <strong>empty</strong> cells.</li>
	<li>Do not cover any of the <strong>occupied</strong> cells.</li>
	<li>We can put as <strong>many</strong> stamps as we want.</li>
	<li>Stamps can <strong>overlap</strong> with each other.</li>
	<li>Stamps are not allowed to be <strong>rotated</strong>.</li>
	<li>Stamps must stay completely <strong>inside</strong> the grid.</li>
</ol>

<p>Return <code>true</code> <em>if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return</em> <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/ex1.png" style="width: 180px; height: 237px;">
<pre><strong>Input:</strong> grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
<strong>Output:</strong> true
<strong>Explanation:</strong> We have two overlapping stamps (labeled 1 and 2 in the image) that are able to cover all the empty cells.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/11/03/ex2.png" style="width: 170px; height: 179px;">
<pre><strong>Input:</strong> grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
<strong>Output:</strong> false 
<strong>Explanation:</strong> There is no way to fit the stamps onto all the empty cells without the stamps going outside the grid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[r].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= m * n &lt;= 2 * 10<sup>5</sup></code></li>
	<li><code>grid[r][c]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>1 &lt;= stampHeight, stampWidth &lt;= 10<sup>5</sup></code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: [C++] [Explained] Calculating prefix sums twice
**Author**: [@charizard21](https://leetcode.com/charizard21/)
**Upvotes**: 4 👍
**Link**: [View Original Post](https://leetcode.com/problems/stamping-the-grid/solutions/1676050/)

---

First things first, we want to take all the stamps which are not illegal (do not tread over an occupied cell) since we are not supposed to optimize the number of stamps
I have used the concept of prefix sums twice in the problem:
1) Firstly, to calculate all the positions in the grid which can be the leftmost and uppermost points for a particular stamp say at i, j. For this the logic that I use it that there needs to be 0 unoccupied cells in the rectangular region defined by i, j and i + stamp_height - 1, j + stamp_width - 1.
2) To check whether we have 0 unoccupied cells can be done by using the concept of prefix sums
3) Now we know all the indices which are stamps
4) Now we calculate the prefix sum over stamps such that stamps[i][j] now gives the the number of stamps located in the rectangular region defined by 0,0 to i,j
5) Now we require that all the points which are unocciped in the grid must be reachable by atleast one stamp
6) Using the same concept of prefix sums as above we can check that.

In the code the first loop calculate prefix sums of grid, second loop calculates valid stamps, third loop calculated prefix sums of stamps and the fourth one checks if all the points are valid.
Thanks for reading, this is my first post
```
bool possibleToStamp(vector<vector<int>>& grid, int sh, int sw) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> stamp(m, vector<int>(n));
	vector<vector<int>> gridc = grid;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			grid[i][j] += (i>0 ? grid[i-1][j] : 0) + (j > 0 ? grid[i][j-1] : 0) - (i > 0 && j > 0 ? grid[i-1][j-1]: 0);
		}
	}
	for(int i = 0; i + sh <= m; i++){
		for(int j = 0; j + sw <= n; j++){
			if(grid[i+sh-1][j+sw-1] == (j > 0 ? grid[i+sh-1][j-1] : 0) + (i > 0 ? grid[i-1][j+sw-1] : 0) - (i > 0 && j > 0 ? grid[i-1][j-1] : 0)){
				stamp[i][j] = 1;
			}
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			stamp[i][j] += (i>0 ? stamp[i-1][j] : 0) + (j > 0 ? stamp[i][j-1] : 0) - (i > 0 && j > 0 ? stamp[i-1][j-1]: 0);
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(gridc[i][j] == 1) continue;
			if(stamp[i][j] == 0 + (j >= sw ? stamp[i][j-sw]  : 0) + (i >= sh ? stamp[i-sh][j] : 0) - (i >= sh && j >= sw ? stamp[i-sh][j-sw] : 0)) return false;
		}
	}
	return true;
}
```

</details>
