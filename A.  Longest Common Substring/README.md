## [Longest Common Substring](https://www.codingninjas.com/studio/problems/longest-common-substring_1235207)

You are given two strings `str1` and `str2`. You have to find the length of their longest common **substring**.  
A substring is a continuous segment of a string.

For example, `"bcd"` is a substring of `"abcd"`, while `"acd"` or `"cda"` are not.

---

### Example 1:
**Input:**  
str1 = "abcjklp", str2 = "acjkp"  
**Output:**  
3  
**Explanation:**  
The longest common substring between `str1` and `str2` is `"cjk"`, and its length is `3`.

---

### Example 2:
**Input:**  
str1 = "wasdijkl", str2 = "wsdjkl"  
**Output:**  
3  
**Explanation:**  
The longest common substring is `"jkl"`, of length `3`.

---

### Example 3:
**Input:**  
str1 = "tyfg", str2 = "cvbnuty"  
**Output:**  
2  
**Explanation:**  
The longest common substring is `"ty"`, of length `2`.

---

### Expected Time Complexity:
`O(n * m)` — where `n` and `m` are the lengths of `str1` and `str2` respectively.

---

### Constraints:
- `1 <= str1.length <= 1000`
- `1 <= str2.length <= 1000`
- `str1` and `str2` consist of only lowercase English characters.
