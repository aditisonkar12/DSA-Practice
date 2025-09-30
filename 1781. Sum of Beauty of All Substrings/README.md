## [1781. Sum of Beauty of All Substrings](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)

The **beauty of a string** is the difference in frequencies between the most frequent and least frequent characters.  

For example, the beauty of `"abaacc"` is `3 - 1 = 2`.  

Given a string `s`, return the **sum of beauty of all of its substrings**.  

---

### Example 1:
**Input:**  
s = "aabcb"  

**Output:**  
5  

**Explanation:**  
The substrings with non-zero beauty are:  
- "aab" → beauty = 1  
- "aabc" → beauty = 1  
- "aabcb" → beauty = 1  
- "abcb" → beauty = 1  
- "bcb" → beauty = 1  
Total = 5.  

---

### Example 2:
**Input:**  
s = "aabcbaa"  

**Output:**  
17  

---

### Constraints:
- `1 <= s.length <= 500`  
- `s` consists of only lowercase English letters.  
