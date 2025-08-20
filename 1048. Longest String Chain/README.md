## [1048. Longest String Chain](https://leetcode.com/problems/longest-string-chain/)

You are given an array of words where each word consists of lowercase English letters.  

A word `wordA` is a **predecessor** of `wordB` if and only if we can insert exactly one letter anywhere in `wordA` (without changing the order of the other characters) to make it equal to `wordB`.  

For example:  
- `"abc"` is a predecessor of `"abac"`  
- `"cba"` is **not** a predecessor of `"bcad"`  

A **word chain** is a sequence of words `[word1, word2, ..., wordk]` with `k >= 1`, where:  
- `word1` is a predecessor of `word2`  
- `word2` is a predecessor of `word3`  
- and so on.  

A single word is trivially a word chain with `k == 1`.  

Return the length of the **longest possible word chain** with words chosen from the given list.  

---

### Example 1:
**Input:**  
words = ["a","b","ba","bca","bda","bdca"]  

**Output:**  
4  

**Explanation:**  
One of the longest word chains is `["a","ba","bda","bdca"]`.  

---

### Example 2:
**Input:**  
words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]  

**Output:**  
5  

**Explanation:**  
All the words can be arranged into a chain:  
`["xb","xbc","cxbc","pcxbc","pcxbcf"]`.  

---

### Example 3:
**Input:**  
words = ["abcd","dbqca"]  

**Output:**  
1  

**Explanation:**  
The trivial chain `["abcd"]` is the longest.  
`["abcd","dbqca"]` is **not** valid since the order of letters changes.  

---

### Constraints:
- `1 <= words.length <= 1000`  
- `1 <= words[i].length <= 16`  
- `words[i]` only consists of lowercase English letters.  
