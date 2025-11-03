## [1752. Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)

Given an array `nums`, return `true` if the array was originally sorted in non-decreasing order and then rotated some number of positions (including zero).  
Otherwise, return `false`.

There may be duplicates in the original array.

> **Note:**  
> An array `A` rotated by `x` positions results in an array `B` such that  
> `B[i] == A[(i + x) % A.length]` for every valid index `i`.

---

### Input:
- An integer array `nums`.

---

### Output:
- Return `true` if the array is sorted and rotated, otherwise `false`.

---

### Example 1:
**Input:**  
nums = [3,4,5,1,2]  

**Output:**  
true  

**Explanation:**  
The original sorted array `[1,2,3,4,5]` was rotated by 2 positions to form `[3,4,5,1,2]`.

---

### Example 2:
**Input:**  
nums = [2,1,3,4]  

**Output:**  
false  

**Explanation:**  
There is no sorted array that can be rotated to make `[2,1,3,4]`.

---

### Example 3:
**Input:**  
nums = [1,2,3]  

**Output:**  
true  

**Explanation:**  
The array `[1,2,3]` is already sorted, so rotation by 0 positions keeps it valid.

---

### Constraints:
- `1 <= nums.length <= 100`  
- `1 <= nums[i] <= 100`
