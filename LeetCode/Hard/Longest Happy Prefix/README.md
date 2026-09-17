# Longest Happy Prefix

| Field | Value |
|-------|-------|
| **Platform** | LeetCode |
| **Difficulty** | Hard |
| **Language** | cpp |
| **Solved On** | September 17, 2026 |
| **Tags** | String, Rolling Hash, String Matching, Hash Function, Z Algorithm, Knuth–Morris–Pratt Algorithm |
| **Link** | [View Problem](https://leetcode.com/problems/longest-happy-prefix/) |
| **Runtime** | 13 ms |
| **Memory** | 24.5 MB |

## Problem Description

<p>A string is called a <strong>happy prefix</strong> if it is a <strong>non-empty</strong> prefix which is also a suffix (excluding itself).</p>

<p>Given a string <code>s</code>, return <em>the <strong>longest happy prefix</strong> of</em> <code>s</code>. Return an empty string <code>""</code> if no such prefix exists.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "level"
<strong>Output:</strong> "l"
<strong>Explanation:</strong> s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "ababab"
<strong>Output:</strong> "abab"
<strong>Explanation:</strong> "abab" is the largest prefix which is also suffix. They can overlap in the original string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
</ul>


##  Top Community Optimal Approach

<details>
<summary>Click to expand</summary>

**Title**: ✅ C++ || KMP ALGO || explained properly with pictures
**Author**: [@rab8it](https://leetcode.com/rab8it/)
**Upvotes**: 7 👍
**Link**: [View Original Post](https://leetcode.com/problems/longest-happy-prefix/solutions/2146100/)

---

* ***APPROACH*** : 

# KMP ALGORITHM:
![image](https://assets.leetcode.com/users/images/bfdd9557-6db6-4421-8344-a97119aa8ddf_1655105030.201723.png)

![image](https://assets.leetcode.com/users/images/ed9187ed-b827-4ba9-bcc7-b19126558eee_1655105049.7562804.png)

![image](https://assets.leetcode.com/users/images/cf30ee7f-47c3-46ad-9f68-fe06b49054e2_1655105065.3050194.png)

![image](https://assets.leetcode.com/users/images/341e210b-d545-47ef-843b-6b57e6e51057_1655105107.747692.png)

![image](https://assets.leetcode.com/users/images/ef409bfd-9a5c-4abf-b452-bf809cd21c37_1655105118.5619612.png)

in this way as the above figures shows we gather the lps values.
```
string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        int i=1,len=0;
        while(i<n){
            if(s[i]==s[len])lps[i++]=++len;     //if the chars are same then simply increase index and length
            else{
                if(len)len=lps[len-1];            //if length is not zero then it will become the length upto the previous longest prefix
                else lps[i++]=0;     //if length is zero then just increase index
            }
        }
        return s.substr(0,len);
    }
```

if this is a little confusing i am suggesting a youtube video that can be helpful(**not sponsored or my channel**)----->https://www.youtube.com/watch?v=4jY57Ehc14Y

\u2705 HAPPY CODING \uD83D\uDE0E\uD83D\uDE4C

![image](https://assets.leetcode.com/users/images/e6208ef7-7ea7-4efc-864a-b4f6f373ab95_1655105430.3294883.png)




</details>
