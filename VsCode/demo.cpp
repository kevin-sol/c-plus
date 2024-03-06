#include <iostream>
using namespace std;

// 快速排序
void quickSort(int arr[], int left, int right)
{
    if (left < right) {
        int pivot = arr[left];
        int i = left, j = right;
        while (i < j) {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        arr[left] = arr[j];
        arr[j] = pivot;
        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);
    }
}
