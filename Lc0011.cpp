#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int f = 0, b = height.size() - 1; f < b;) {
            res = max(res, min(height[f], height[b]) * (b - f));
            if (height[f] > height[b]) b--;
            else f++;
        }
        return res;
    }
};