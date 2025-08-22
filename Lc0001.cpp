#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index(nums.size());
        for (int i = 0; i < index.size(); i++) index[i] = i;
        stable_sort(index.begin(), index.end(), [&nums](const int& a, const int& b) { return nums[a] < nums[b]; });
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            int j = i + 1;
            if (nums[i] + nums[j] > target) return { -1, -1 };
            for (int jump = nums.size() - j - 1; jump > 0; jump /= 2) {
                while (j + jump < nums.size() && nums[i] + nums[j + jump] <= target) {
                    j += jump;
                }
            }
            if (nums[i] + nums[j] == target) return { index[i], index[j] };
        }
        return { -1, -1 };
    }
};