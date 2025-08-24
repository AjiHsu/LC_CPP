#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        bool isNeg = false;
        while (index < s.size() && s[index] == ' ') index++;
        if (index < s.size() && s[index] == '-') {
            isNeg = true;
            index++;
        }
        else if (index < s.size() && s[index] == '+') {
            index++;
        }

        long long res = 0;
        while (index < s.size() && '0' <= s[index] && s[index] <= '9') {
            res *= 10;
            res += s[index++] - '0';
            if (isNeg && -res <= INT_MIN) return INT_MIN;
            if (!isNeg && res >= INT_MAX) return INT_MAX;
        }

        return (int) (isNeg ? -res : res);
    }
};