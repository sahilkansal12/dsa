# Smallest Index With Equal Value

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Easy |
| **Language** | cpp |
| **Solved On** | September 24, 2026 |
| **Tags** | Array |
| **Link** | [View Problem](https://leetcode.com/problems/smallest-index-with-equal-value/) |
| **Runtime** | 0 ms |
| **Memory** | 25.8 MB |

## Problem Description

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code>, return <em>the <strong>smallest</strong> index </em><code>i</code><em> of </em><code>nums</code><em> such that </em><code>i mod 10 == nums[i]</code><em>, or </em><code>-1</code><em> if such index does not exist</em>.</p>

<p><code>x mod y</code> denotes the <strong>remainder</strong> when <code>x</code> is divided by <code>y</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [0,1,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> 
i=0: 0 mod 10 = 0 == nums[0].
i=1: 1 mod 10 = 1 == nums[1].
i=2: 2 mod 10 = 2 == nums[2].
All indices have i mod 10 == nums[i], so we return the smallest index 0.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [4,3,2,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
i=0: 0 mod 10 = 0 != nums[0].
i=1: 1 mod 10 = 1 != nums[1].
i=2: 2 mod 10 = 2 == nums[2].
i=3: 3 mod 10 = 3 != nums[3].
2 is the only index which has i mod 10 == nums[i].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4,5,6,7,8,9,0]
<strong>Output:</strong> -1
<strong>Explanation:</strong> No index satisfies i mod 10 == nums[i].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 9</code></li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: [C++] Simple Solutions Explained, 100% Time (0ms), ~80% Space (22MB)
**Author**: [@Ajna2](https://leetcode.com/Ajna2/)
**Upvotes**: 4 👍
**Link**: [View Original Post](https://leetcode.com/problems/smallest-index-with-equal-value/solutions/1565344/)

---

I am not sure if there is a single problem easier than this on the whole suite of 2000+ problems published so far, as this one is literally just about following instructions, but, hey, whatever.

Still worth giving it a shot and in an interview you might still gain some points in the eyes of your interviewer if you mention that since modulo operations are rather expensive, we will not bother with them when the currently parsed argument is `> 9`.

Other than that, we will have a main loop to parse the whole `nums`, `return` the first index `i` matching our condition (if any) and otherwise, exiting the loop, `return` `-1`.

The code:

```cpp
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0, len = nums.size(), n; i < len; i++) {
            n = nums[i];
            if (n < 10 && n == i % 10) return i;
        }
        return -1;
    }
};
```

Even better if we rule out the modulo operation altogether:

```cpp
constexpr int mods[101] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};

class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0, len = nums.size(), n; i < len; i++) {
            n = nums[i];
            if (n < 10 && n == mods[i]) return i;
        }
        return -1;
    }
};
```

In constant space, maybe? Hell, yeah - this one gave me `0` ms \uD83D\uDC4D :

```cpp
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i = 0, j = 0, len = nums.size(), n; i < len; i++, j++) {
            n = nums[i];
            if (j == 10) j -= 10;
            if (n < 10 && n == j) return i;
        }
        return -1;
    }
};
```

</details>
