#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;

        int x = 0, y = 0;
        bool transpose = true;
        while (y < mat.size()) {
            int cnt = 0;
            int i = y, j = x;
            while (i < mat.size() && j >= 0) {
                res.push_back(mat[i][j]);
                i++;
                j--;
                cnt++;
            }
            if (transpose) {
                reverse(res.end() - cnt, res.end());
            }

            transpose = !transpose;
            if (x + 1 >= mat[0].size()) y++;
            else x++;
        }

        return res;
    }
};