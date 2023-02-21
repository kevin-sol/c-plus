#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /*classes数量太大时不可用，时间超出*/
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        for (int i = 0; i < extraStudents; i++) {
            int k = maxsub(classes);
            classes[k][0] += 1;
            classes[k][1] += 1;
        }
        double average;
        for (int i = 0; i < classes.size(); i++) {
            average += (double)classes[i][0] / (double)classes[i][1];
        }
        average = average / classes.size();
        return average;
    }
    int maxsub(vector<vector<int>> classes)
    {
        vector<double> sub;
        for (int i = 0; i < classes.size(); i++) {
            sub.push_back((((double)classes[i][0] + 1) / ((double)classes[i][1] + 1)) -
                          ((double)classes[i][0] / (double)classes[i][1]));
        }
        auto max = max_element(sub.begin(), sub.end());
        return max - sub.begin();
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> classes;
    int extraStudents = 4;
    classes.push_back({2, 4});
    classes.push_back({3, 9});
    classes.push_back({4, 5});
    classes.push_back({2, 10});

    cout << s.maxAverageRatio(classes, extraStudents) << endl;
    system("pause");
    return 0;
}
