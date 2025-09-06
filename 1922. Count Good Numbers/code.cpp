class Solution {
#define ll long long
    int MOD = 1000000007;

    ll goodNumbers(ll a, ll b) {
        ll ans = 1;
        while (b) {
            if (b & 1) {
                ans = (ans * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        return (goodNumbers(4, n / 2) * goodNumbers(5, n - n / 2)) % MOD;
    }
};