#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    bool ishui(string s)
    {
        string s1 = s;
        reverse(s.begin(), s.end());
        return s == s1;
    }
    bool judge(string a, string b)
    {
        int n = a.size();
        int i = 0, j = n - 1;
        while (a[i] == b[j] && i < j) {
            i++;
            j--;
        }
        string a1 = a.substr(i, j - i + 1);
        string b2 = b.substr(i, j - i + 1);
        if (ishui(a1) || ishui(b2)) {
            return true;
        }
        return false;
    }
    bool checkPalindromeFormation(string a, string b)
    {
        if (ishui(a) || ishui(b)) {
            return true;
        }
        return judge(a, b) || judge(b, a);
    }
};