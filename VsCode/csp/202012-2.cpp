#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int main(int argc, char const *argv[])
{
    int m;
    scanf("%d", &m);
    vector<int> y(m), result(m);
    for (int i = 0; i < m; i++) {
        int yi, resulti;
        scanf("%d %d", &yi, &resulti);
        y[i] = yi;
        result[i] = resulti;
    }
    int o;
    map<int, int> o_cnt;
    int last_cnt = -1;
    for (int i = 0; i < m; i++) {
        o = y[i];
        if (o == last_cnt) {
            continue;
        }
        int rightCnt = 0;
        for (int j = 0; j < m; j++) {
            if (y[j] < o && result[j] == 0) {
                rightCnt++;
            } else if (y[j] >= o && result[j] == 1) {
                rightCnt++;
            }
        }
        last_cnt = o;
        o_cnt.insert(pair<int, int>(o, rightCnt));
    }
    int k, max = 0;
    for (map<int, int>::iterator i = o_cnt.begin(); i != o_cnt.end(); i++) {
        if (max <= i->second) {
            max = i->second;
            k = i->first;
        }
    }
    printf("%d\n", k);
    system("pause");
    return 0;
}
