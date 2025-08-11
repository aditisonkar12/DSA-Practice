## [1312. Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

Given a string `s`. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make `s` a palindrome.

A **Palindrome** is a string that reads the same backward as forward.

---

### Example 1:
**Input:**  
s = "zzazz"  
**Output:**  
0  
**Explanation:**  
The string `"zzazz"` is already a palindrome, so no insertions are needed.

---

### Example 2:
**Input:**  
s = "mbadm"  
**Output:**  
2  
**Explanation:**  
One way is `"mbdadbm"`, another is `"mdbabdm"`.

---

### Example 3:
**Input:**  
s = "leetcode"  
**Output:**  
5  
**Explanation:**  
By inserting 5 characters, the string becomes `"leetcodocteel"`.

---

### Constraints:
- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.
