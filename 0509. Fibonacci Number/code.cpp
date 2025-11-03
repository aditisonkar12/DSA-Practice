class Solution {
public:
    int fib(int n) {
        int sum = 0;
        if (n <= 1)
            return n;
        int last = fib(n - 1);
        int seclast = fib(n - 2);
        return last + seclast;
        // return fib(n - 1) + fib(n - 2);
    }
};