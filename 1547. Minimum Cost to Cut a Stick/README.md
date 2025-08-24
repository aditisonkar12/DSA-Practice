## [1547. Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

You are given a wooden stick of length `n` (labelled from `0` to `n`) and an array `cuts`,  
where `cuts[i]` denotes a position where you should perform a cut.  

- You may perform the cuts in any order.  
- The **cost of one cut** is equal to the length of the stick being cut at that time.  
- After cutting, the stick splits into two smaller sticks (whose total length equals the original stick).  

Return the **minimum total cost** of performing all cuts.

---

### Example 1:
**Input:**  
n = 7, cuts = [1,3,4,5]  

**Output:**  
16  

**Explanation:**  
- Cutting in order `[1,3,4,5]` gives total cost = 20.  
- But cutting in order `[3,5,1,4]` yields cost = 16, which is minimal.  

---

### Example 2:
**Input:**  
n = 9, cuts = [5,6,1,4,2]  

**Output:**  
22  

**Explanation:**  
- The naive order gives cost = 25.  
- Optimal order (e.g., `[4,6,5,2,1]`) gives minimum cost = 22.  

---

### Constraints:
- `2 <= n <= 10^6`  
- `1 <= cuts.length <= min(n - 1, 100)`  
- `1 <= cuts[i] <= n - 1`  
- All cuts are distinct  

