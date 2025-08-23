#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            int f = i - 1;
            int b = i + 1;
            sol(f, b, s, resLen, res);

            // double center
            if (i < s.size() - 1 && s[i] == s[i + 1]) {
                f = i - 1;
                b = i + 2;
                sol(f, b, s, resLen, res);
            }
        }
        return res;
    }

private:
    void sol(int& f, int& b, string& s, int& resLen, string& res) {
        while (f >= 0 && b < s.size() && s[f] == s[b]) {
            f--;
            b++;
        }
        if (b - f - 1 > resLen) {
            res = s.substr(f + 1, b - f - 1);
            resLen = b - f - 1;
        }
    }
};