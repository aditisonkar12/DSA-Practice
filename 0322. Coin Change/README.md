## [322. Coin Change](https://leetcode.com/problems/coin-change/)

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.  

Return the fewest number of coins needed to make up that amount.  
If it is not possible to make the amount using the given coins, return `-1`.  

You may assume you have an infinite number of each coin.

---

### Example 1:
**Input:**  
coins = [1, 2, 5], amount = 11  
**Output:**  
3  
**Explanation:**  
11 can be made with three coins: `5 + 5 + 1`.

---

### Example 2:
**Input:**  
coins = [2], amount = 3  
**Output:**  
-1  
**Explanation:**  
It is not possible to make the amount 3 using only coin 2.

---

### Example 3:
**Input:**  
coins = [1], amount = 0  
**Output:**  
0  
**Explanation:**  
No coins are needed to make amount 0.

---

### Constraints:
- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 2^31 - 1`
- `0 <= amount <= 10^4`
