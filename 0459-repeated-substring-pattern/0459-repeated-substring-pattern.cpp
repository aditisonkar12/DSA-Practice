class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0)
                continue;

            string subst = s.substr(0, i);
            string temp = "";

            for (int j = 0; j < n / i; j++) {
                temp += subst;
            }

            if (temp == s)
                return true;
            // s = "abcabcabcabc" n=12
            // i=1 n%i = 12%1 != 0 continue
            // i=2 12%2=0 subst=s.substr(0,2)=ab temp=abababababab != s 
            // i=3 12%3=0 subst=s.substr(0,3)=abc temp=abcabcabcabc == s return true
        }
        return false;
    }
};