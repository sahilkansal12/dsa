# Remove All Occurrences of a Substring

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Medium |
| **Language** | cpp |
| **Solved On** | September 16, 2026 |
| **Tags** | String, Stack, Simulation |
| **Link** | [View Problem](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/) |
| **Runtime** | 0 ms |
| **Memory** | 9.8 MB |

## Problem Description

<p>Given two strings <code>s</code> and <code>part</code>, perform the following operation on <code>s</code> until <strong>all</strong> occurrences of the substring <code>part</code> are removed:</p>

<ul>
	<li>Find the <strong>leftmost</strong> occurrence of the substring <code>part</code> and <strong>remove</strong> it from <code>s</code>.</li>
</ul>

<p>Return <code>s</code><em> after removing all occurrences of </em><code>part</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "daabcbaabcbc", part = "abc"
<strong>Output:</strong> "dab"
<strong>Explanation</strong>: The following operations are done:
- s = "da<strong><u>abc</u></strong>baabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "daba<strong><u>abc</u></strong>bc", remove "abc" starting at index 4, so s = "dababc".
- s = "dab<strong><u>abc</u></strong>", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "axxxxyyyyb", part = "xy"
<strong>Output:</strong> "ab"
<strong>Explanation</strong>: The following operations are done:
- s = "axxx<strong><u>xy</u></strong>yyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axx<strong><u>xy</u></strong>yyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "ax<strong><u>xy</u></strong>yb", remove "xy" starting at index 2 so s = "axyb".
- s = "a<strong><u>xy</u></strong>b", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>1 &lt;= part.length &lt;= 1000</code></li>
	<li><code>s</code>​​​​​​ and <code>part</code> consists of lowercase English letters.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: C++, Simple solution, Faster than 100%
**Author**: [@samyak_uttam](https://leetcode.com/samyak_uttam/)
**Upvotes**: 109 👍
**Link**: [View Original Post](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/solutions/1298766/)

---

**Logic:**
* We make a copy of our string s (x in code) and then iterate over the string s. 
* Now in the current iteration if j is greater than or equal to m that means that we have seen at least m elements, so we can check whether the substring of last m characters is equal to part or not. If it is equal, we reduce the variable \'j\' by m showing that we have removed this substring and now we will overwrite the characters from index j.
* Finally we will return the substring of x of length j.
```
string removeOccurrences(string s, string part) {
	string x = s;
	int n = s.size(), m = part.size(), i, j;
	for (i = 0, j = 0; i < n; i++) {
		x[j++] = s[i];
		if (j >= m && x.substr(j - m, m) == part)
			j -= m;
	}
	return x.substr(0, j);
}
```

</details>
