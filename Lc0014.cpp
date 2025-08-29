#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int idx = 0;
        while (1) {
            if (strs[0].size() <= idx) strs[0].substr(0, idx);
            char c = strs[0][idx];
            for (string& s : strs) {
                if (idx >= s.size() || s[idx] != c) {
                    return s.substr(0, idx);
                }
            }
            idx++;
        }
        return "";
    }
};