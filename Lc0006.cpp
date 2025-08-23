#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<vector<char>> vec(numRows);
        int idx = 0;
        int val = 1;
        for (char c : s) {
            vec[idx].push_back(c);
            if (idx == numRows - 1 && val == 1) val = -1;
            else if (idx == 0 && val == -1) val = 1;
            idx += val;
        }
        string res;
        for (int i = 0; i < numRows; i++)
            res.append(vec[i].begin(), vec[i].end());

        return res;
    }
};