## [Boolean Evaluation](https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650?leftPanelTabValue=PROBLEM&count=25&search=boolean%20evaluation&sort_entity=order&sort_order=ASC&customSource=studio_nav)
You are given a boolean expression `exp` in the form of a string consisting of:
- Operands: `T` (True), `F` (False)
- Operators: `&` (AND), `|` (OR), `^` (XOR)

Your task is to count the **number of ways to parenthesize** the expression so that it evaluates to **True**.  
Since the number of ways can be large, return the result modulo `1000000007`.

---

### Example 1:
**Input:**  
`exp = "T|T&F"`

**Output:**  
`1`

**Explanation:**  
Two possible parenthesizations:  
1. `(T | T) & F = F`  
2. `T | (T & F) = T` ✅  

Only one evaluates to **True**, so the answer is `1`.

---

### Example 2:
**Input:**  
`exp = "T^T^F"`

**Output:**  
`0`

**Explanation:**  
1. `(T ^ T) ^ F = F ^ F = F`  
2. `T ^ (T ^ F) = T ^ T = F`  

Both evaluate to **False**, so the answer is `0`.

---

### Example 3:
**Input:**  
`exp = "F|T^F"`

**Output:**  
`2`

**Explanation:**  
1. `(F | T) ^ F = T ^ F = T` ✅  
2. `F | (T ^ F) = F | T = T` ✅  

Both evaluate to **True**, so the answer is `2`.

---

### Constraints:
- `3 <= |exp| <= 200`  
- Expression contains only `'T', 'F', '&', '|', '^'`  
- Time Limit: `1 sec`  
- Expected Time Complexity: **O(n³)**, where `n` is the length of `exp`.

