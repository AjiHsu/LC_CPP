#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int zeroPos = -1;
        for (int f = 0, b = 0; b < nums.size(); b++) {
            if (nums[b] == 0) {
                f = zeroPos + 1;
                zeroPos = b;
            }
            res = max(res, b - f);
        }
        return res;
    }
};