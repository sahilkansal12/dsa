# Matrix Diagonal Sum

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | October 19, 2026 |
| **Tags** | Array, Matrix |
| **Link** | [View Problem](https://leetcode.com/problems/matrix-diagonal-sum/) |
| **Runtime** | 1 ms |
| **Memory** | 15 MB |

## Problem Description

<p>Given a&nbsp;square&nbsp;matrix&nbsp;<code>mat</code>, return the sum of the matrix diagonals.</p>

<p>Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/08/14/sample_1911.png" style="width: 336px; height: 174px;">
<pre><strong>Input:</strong> mat = [[<strong>1</strong>,2,<strong>3</strong>],
&nbsp;             [4,<strong>5</strong>,6],
&nbsp;             [<strong>7</strong>,8,<strong>9</strong>]]
<strong>Output:</strong> 25
<strong>Explanation: </strong>Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> mat = [[<strong>1</strong>,1,1,<strong>1</strong>],
&nbsp;             [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;             [1,<strong>1</strong>,<strong>1</strong>,1],
&nbsp;             [<strong>1</strong>,1,1,<strong>1</strong>]]
<strong>Output:</strong> 8
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> mat = [[<strong>5</strong>]]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == mat.length == mat[i].length</code></li>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= mat[i][j] &lt;= 100</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: Python/JS/Java/Go/C++ O(n) by iteration [w/ Comment]
**Author**: [@brianchiang_tw](https://leetcode.com/brianchiang_tw/)
**Upvotes**: 104 👍
**Link**: [View Original Post](https://leetcode.com/problems/matrix-diagonal-sum/solutions/837795/)

---

O(n) by iteration

[\u4E2D\u6587\u8A73\u89E3 \u89E3\u984C\u6587\u7AE0](https://vocus.cc/article/6559d622fd89780001a1f96c)

[Tutorial video in Chinese \u4E2D\u6587\u89E3\u984C\u5F71\u7247](https://youtu.be/tTfkdaB4_hM)

![image](https://assets.leetcode.com/users/images/967ea20c-7acc-48ac-a4d5-60c8aa17316e_1615731413.5755115.png)

---

**Implementation**:

**Python**:

```
class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        
        n = len(mat)
        
        mid = n // 2
        
        summation = 0
        
        for i in range(n):
            
            # primary diagonal
            summation += mat[i][i]
            
            # secondary diagonal
            summation += mat[n-1-i][i]
            
            
        if n % 2 == 1:
            # remove center element (repeated) on odd side-length case
            summation -= mat[mid][mid]
            
            
        return summation
```

---

**Java**:

```
class Solution {
    public int diagonalSum(int[][] mat) {
        
        // side length
        int n = mat.length;
        
        // mid point index
        int mid = n / 2;
        
        // summation of diagonal element
        int summation = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            
            // primary diagonal
            summation += mat[i][i];
            
            // secondary diagonal
            summation += mat[n-1-i][i];
        }
        
        
        if( n % 2 == 1 ){
            
            // remove center element (repeated) on odd side-length case
            summation -= mat[mid][mid];
        }
        
        return summation;
    }
}
```

---

**Javascript**:

```
var diagonalSum = function(mat) {
    
    // side length
    let n = mat.length;
    
    // mid point index
    let mid = Math.floor( n / 2 );
    
    // summation of diagonal element
    let summation = 0;
    
    for( let i = 0 ; i < n ; i++ ){
        
        // primary diagonal
        summation += mat[i][i];
        
        // secondary diagonal
        summation += mat[n-1-i][i];
    }
    
    if( n % 2 == 1 ){
        
        // remoive center element (repeated) on odd side-length case
        summation -= mat[mid][mid];
    }
    
    return summation;
};
```

---

**Golang**:

```
func diagonalSum(mat [][]int) int {
    
    // side-length
    n := len(mat)
    
    // mid point index
    mid := n / 2
    
    // summation of diagonal element
    summation := 0
    
    for i := 0 ; i < n ; i++{
        
        // primary diagonal
        summation += mat[i][i]
        
        // secondary diagonal
        summation += mat[n-1-i][i]
        
    }
    
    if n % 2 == 1 {
        
        // remove center element (repeated) on odd side-length case
        summation -= mat[mid][mid]
    }
    
    
    return summation
}
```

---

**C++**:

```
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        // side length
        int n = mat.size();
        
        // mid point index
        int mid = n / 2;
        
        // summation of diagonal element
        int summation = 0;
        
        for( int i = 0 ; i < n ; i++ ){
            
            // primary diagonal
            summation += mat[i][i];
            
            // secondary diagonal
            summation += mat[n-1-i][i];
        }
        
        
        if( n % 2 == 1 ){
            
            // remove center element (repeated) on odd side-length case
            summation -= mat[mid][mid];
        }
        
        return summation;
    }
};
```

</details>
