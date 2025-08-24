## [1106. Parsing A Boolean Expression](https://leetcode.com/problems/parsing-a-boolean-expression/)

A **boolean expression** is a string that evaluates to either `true` or `false`.  
It follows one of these forms:

- `"t"` → evaluates to `true`
- `"f"` → evaluates to `false`
- `"!(subExpr)"` → logical NOT of the inner expression
- `"&(subExpr1, subExpr2, ..., subExprn)"` → logical AND of all sub-expressions (`n >= 1`)
- `"|(subExpr1, subExpr2, ..., subExprn)"` → logical OR of all sub-expressions (`n >= 1`)

Given a valid expression string, return its **evaluated boolean result**.

---

### Example 1:
**Input:**  
`expression = "&(|(f))"`

**Output:**  
`false`  

**Explanation:**  
- `|(f)` → `f`  
- `&(f)` → `f` → result is **false**

---

### Example 2:
**Input:**  
`expression = "|(f,f,f,t)"`

**Output:**  
`true`  

**Explanation:**  
- `(false OR false OR false OR true)` → **true**

---

### Example 3:
**Input:**  
`expression = "!(|(f,t))"`

**Output:**  
`false`  

**Explanation:**  
- `|(f,t)` → `true`  
- `!(true)` → `false`

---

### Constraints:
- `1 <= expression.length <= 2 * 10^4`  
- Expression contains only: `'(' , ')' , '&' , '|' , '!' , 't' , 'f' , ','`  
- The given expression is guaranteed to be valid.
