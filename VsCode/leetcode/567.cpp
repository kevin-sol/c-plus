#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s2.size();
        int win = s1.size();
        if (win > n) {
            return false;
        }
        vector<int> hash(26, 0);
        vector<int> hash2(26, 0);
        for (int i = 0; i < win; i++) {
            hash[s1[i] - 'a']++;
            hash2[s2[i] - 'a']++;
        }
        for (int i = win; i < n; i++) {
            if (hash == hash2) {
                return true;
            }
            hash2[s2[i] - 'a']++;
            hash2[s2[i - win] - 'a']--;
        }
        if (hash == hash2) {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    system("pause");
    return 0;
}