#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    map<char, int> m;
    for (int i = 0; i < 3; i++) {
        if (!m.count('b')) {
            m['b'] = 1;
        }
        cout << m['b'] << endl;
    }

    system("pause");
    return 0;
}
