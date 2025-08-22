#include <vector>
using namespace std;
// O(m + n) O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int target1 = -1, target2 = -1;
        double res1 = -1, res2 = -1;
        if (size % 2 == 1) target1 = target2 = size / 2;
        else {
            target1 = size / 2 - 1;
            target2 = size / 2;
        }

        int p2 = 0;
        for (int p1 = 0; p1 < nums1.size(); p1++) {
            while (p2 < nums2.size() && nums2[p2] <= nums1[p1]) {
                if (p1 + p2 == target1) res1 = nums2[p2];
                if (p1 + p2 == target2) res2 = nums2[p2];
                p2++;
            }

            if (p1 + p2 == target1) res1 = nums1[p1];
            if (p1 + p2 == target2) res2 = nums1[p1];
        }

        while (p2 < nums2.size()) {
            if (nums1.size() + p2 == target1) res1 = nums2[p2];
            if (nums1.size() + p2 == target2) res2 = nums2[p2];
            p2++;
        }

        return (res1 + res2) / 2;
    }
};