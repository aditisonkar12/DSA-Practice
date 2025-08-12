## [494. Target Sum](https://leetcode.com/problems/target-sum/)

You are given an integer array `nums` and an integer `target`.  
You want to build an expression using `nums` by adding one of the symbols `'+'` or `'-'` before each integer, then concatenate all the integers to form the expression.

For example, if `nums = [2, 1]`, you could build the expression `"+2-1"`.

Return the number of different expressions that can be built that evaluate to `target`.

---

### Example 1:

**Input:**  
nums = [1,1,1,1,1], target = 3  

**Output:**  
5  

**Explanation:**  
There are 5 ways to assign symbols to make the sum equal to target 3:

-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

---

### Example 2:

**Input:**  
nums = [1], target = 1

**Output:**  
1  

---

### Constraints:

- 1 <= nums.length <= 20  
- 0 <= nums[i] <= 1000  
- 0 <= sum(nums) <= 1000  
- -1000 <= target <= 1000  


