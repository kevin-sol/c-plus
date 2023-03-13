#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost)
    {
        int num = 0, wait = 0, res = 0;
        int min = runningCost / boardingCost + 1;
        int n = customers.size();
        int i = 0;
        for (i = 0; i < n; i++) {
            if (customers[i] + wait > 4) {
                wait = customers[i] + wait - 4;
                num += 4;
            } else {
                num += customers[i] + wait;
                wait = 0;
            }
        }
        while (wait > 4) {
            wait -= 4;
            num += 4;
            i++;
        }
        if (wait < min) {
            res = num * boardingCost - i * runningCost;
            return res > 0 ? i : -1;
        }
        num += wait;
        i = wait > 0 ? i + 1 : i;
        res = num * boardingCost - i * runningCost;
        return res > 0 ? i : -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> c({10, 10, 6, 4, 7});
    cout << s.minOperationsMaxProfit(c, 3, 8);
    return 0;
}
