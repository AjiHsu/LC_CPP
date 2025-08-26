#include <vector>
using namespace std;
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int dLen = 0;
        int area = 0;
        for (vector<int> &d : dimensions) {
            int dd = d[0] * d[0] + d[1] * d[1];
            if (dd > dLen) {
                dLen = dd;
                area = d[0] * d[1];
            }
            else if (dd == dLen) {
                area = max(area, d[0] * d[1]);
            }
        }
        return area;
    }
};