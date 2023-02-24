#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    vector<int> circularPermutation(int n, int start)
    {
        vector<int> p(pow(2, n));
        p[0] = start;
        for (int i = 0; i < p.size(); i++) {
            p[i] = (i >> 1) ^ i ^ start;
        }
        return p;
    }
};