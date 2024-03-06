#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int quicksort(int *a, int low, int high)
{
    int p = a[low];
    while (low < high) {
        while (a[high] >= p && low < high) {
            high--;
        }
        a[low] = a[high];
        while (a[low] <= p && low < high) {
            low++;
        }
        a[high] = a[low];
    }
    a[low] = p;
    return low;
}
void sort(int *a, int low, int high)
{
    if (low >= high) {
        return;
    }
    int mid = quicksort(a, low, high);
    sort(a, low, mid - 1);
    sort(a, mid + 1, high);
}
int main(int argc, char const *argv[])
{
    int a[10] = {11, 5, 9, 4, 45, 32, 1, 26, 46, 8};
    sort(a, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}
