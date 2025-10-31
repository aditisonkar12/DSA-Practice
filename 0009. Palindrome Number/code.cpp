#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <bitset>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int org=x;
        long rev=0;
        while(x!=0){
            int y=x%10;
            rev=rev*10+y;
            x=x/10;
        }
        return org==rev;
    }
};
