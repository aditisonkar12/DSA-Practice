## [Longest Bitonic Sequence](https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688?leftPanelTabValue=PROBLEM)


A **Bitonic Sequence** is a sequence of numbers that is first strictly increasing and then strictly decreasing.  

- A strictly ascending sequence is also considered bitonic (with the decreasing part empty).  
- A strictly descending sequence is also considered bitonic (with the increasing part empty).  

For example:  
- `[1, 3, 5, 3, 2]` and `[1, 2, 3, 4]` are bitonic.  
- `[5, 4, 1, 4, 5]` and `[1, 2, 2, 3]` are **not** bitonic.  

You are given an array `arr` consisting of `n` positive integers.  
Find the **length of the longest bitonic subsequence** of `arr`.  

---

### Example 1:
**Input:**  
arr = [1, 2, 1, 2, 1]  

**Output:**  
3  

**Explanation:**  
The longest bitonic subsequence is `[1, 2, 1]`.  
`[1, 2, 2, 1]` is not valid since consecutive `2`s are neither strictly increasing nor strictly decreasing.  

---

### Example 2:
**Input:**  
arr = [1, 2, 1, 3, 4]  

**Output:**  
4  

**Explanation:**  
The longest bitonic subsequence is `[1, 2, 3, 4]`.  

---

### Constraints:
- `1 <= n <= 10^3`  
- `1 <= arr[i] <= 10^5`  
- Expected Time Complexity: `O(n^2)`  
- Time Limit: `1 sec`  
