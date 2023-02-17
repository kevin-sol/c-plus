#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        int n = nums.size();
        int cnt = 0;
        vector<int> nums2(2);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == nums[i]) {
                    nums.erase(nums.begin() + j);
                    nums.erase(nums.begin() + i);
                    j -= 2;
                    i--;
                    n -= 2;
                    cnt++;
                    break;
                }
            }
        }
        nums2[0] = cnt;
        nums2[1] = nums.size();
        return nums2;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    vector<int> nums2 = s.numberOfPairs(nums);
    cout << nums2[0] << " " << nums2[1] << endl;
    return 0;
}
