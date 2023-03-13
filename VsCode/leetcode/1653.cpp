#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int a = 0, b = 0;
        for (auto &&i : s) {
            if (i == 'a')
                a++;
        }
        int res = a;
        for (auto &&i : s) {
            if (i == 'a') {
                a--;
            } else {
                b++;
            }
            res = min(res, a + b);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}
