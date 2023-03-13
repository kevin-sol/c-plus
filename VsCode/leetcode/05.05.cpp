#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
    string printBin(double num)
    {
        string s = "0.";
        int i;
        for (i = 0; i < 32; i++) {
            num = num * 2;
            if (num >= 1) {
                s.push_back('1');
                num -= 1;
            } else
                s.push_back('0');
            if (num == 0) {
                break;
            }
        }
        if (i > 30)
            return "ERROR";
        else
            return s;
    }
};
