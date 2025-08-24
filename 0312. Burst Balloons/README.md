## [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/)

You are given `n` balloons, indexed from `0` to `n - 1`.  
Each balloon has a number on it, given in `nums`.  

When you burst the `i-th` balloon, you gain `nums[i-1] * nums[i] * nums[i+1]` coins.  
- If `i - 1` or `i + 1` goes out of bounds, treat it as if there is a balloon with number `1`.  
- After bursting a balloon, it disappears, and you continue with the remaining balloons.  

Return the **maximum coins** you can collect by bursting all balloons wisely.

---

### Example 1:
**Input:**  
nums = [3,1,5,8]  

**Output:**  
167  

**Explanation:**  
Burst in this order:  
- `[3,1,5,8] → [3,5,8] → [3,8] → [8] → []`  
- Coins = (3*1*5) + (3*5*8) + (1*3*8) + (1*8*1) = **167**

---

### Example 2:
**Input:**  
nums = [1,5]  

**Output:**  
10  

---

### Constraints:
- `n == nums.length`  
- `1 <= n <= 300`  
- `0 <= nums[i] <= 100`  

