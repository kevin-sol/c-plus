#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int sum = 0;
        for (auto &&i : nums) {
            sum = (sum + i) % p;
        }
        if (sum == 0) {
            return 0;
        }
        unordered_map<int, int> M;
        int j = 0, res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            M[j] = i;
            j = (j + nums[i]) % p;
            if (M.count((j - sum + p) % p) > 0) {
                res = min(res, i - M[(j - sum + p) % p] + 1);
            }
        }
        return res == nums.size() ? -1 : res;
    }
};