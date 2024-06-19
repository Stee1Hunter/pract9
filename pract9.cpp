#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <complex>
#include <thread>
using namespace std;


class MergeSort {

public:
   void merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> leftArr(n1);
        vector<int> rightArr(n2);

        for (int i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k] = leftArr[i];
                i++;
            }
            else {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
    }

    void sort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            sort(arr, left, mid);
            sort(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }
};

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    int n=10;
    
    vector<int> arr(n);

    cout << "Пожалуйста, введите " << n << " чисел: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    MergeSort mergeSort;

    auto sortFunction = [&mergeSort, &arr]() {
        mergeSort.sort(arr, 0, arr.size() - 1);
    };

    thread mergeSortThread(sortFunction);

    mergeSortThread.join();

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}