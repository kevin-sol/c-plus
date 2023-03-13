#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> getFolderNames(vector<string> &names)
    {
        int n = names.size();
        unordered_map<string, int> s_cnt;
        for (int i = 0; i < n; i++) {
            /*string name = names[i];
            while (s_cnt.find(names[i]) != s_cnt.end()) {
                names[i] = name + "(" + to_string(s_cnt[name]) + ")";
                s_cnt[name]++;
            }
            s_cnt[names[i]]++;*/
            if (s_cnt[names[i]] > 0) {
                string name = names[i];
                while (s_cnt.find(names[i]) != s_cnt.end()) {
                    names[i] = name + "(" + to_string(s_cnt[name]) + ")";
                    s_cnt[name]++;
                }
            }
            s_cnt[names[i]]++;
        }
        return names;
    }
};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> names({"asdas", "fsd", "asdfv", "fsd", "fsd"});
    vector<string> names1;
    names1 = s.getFolderNames(names);
    for (auto &&i : names1) {
        cout << i << " ";
    }
    system("pause");
    return 0;
}
