#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int p, q;
        int n = nums.size();
        int *nums1 = new int[n];
        p = 0;
        q = n - 1;
        int i = n - 1;
        while (p <= q) {
            if (abs(nums[p]) > abs(nums[q])) {
                nums1[i] = (nums[p] * nums[p]);
                i--;
                p++;
            } else {
                nums1[i] = (nums[q] * nums[q]);
                i--;
                q--;
            }
        }
        for (int i = 0; i < n; i++) {
            nums[i] = nums1[i];
        }
        return nums;
    }
};
