#include <list>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if (x == 0) return 0;
        long long y = x;
        bool isNeg = y < 0;
        if (isNeg) y *= -1;

        list<int> lst;
        while (y > 0) {
            lst.push_back(y % 10);
            y /= 10;
        }
        while (lst.front() == 0) lst.pop_front();
        long long res = 0;
        while (!lst.empty()) {
            res *= 10;
            res += lst.front();
            lst.pop_front();
            if (res > 2147483647) return 0;
        }
        if (isNeg) res *= -1;
        return (int)res;
    }
};