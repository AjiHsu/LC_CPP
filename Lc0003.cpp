#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_set<char> set;
        for (int f = 0, b = 0; b < s.size(); b++) {
            if (set.find(s[b]) != set.end()) {
                do {
                    set.erase(s[f++]);
                } while (s[f - 1] != s[b]);
            }
            set.insert(s[b]);
            res = max(res, b - f + 1);
        }
        return res;
    }
};