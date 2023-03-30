#include <iostream>
#include <chrono>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;   
    int temp;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  
            temp = (arr[i]);
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return (i + 1); 
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 100, 12, 53, 312, 1};  
    int n = sizeof(arr) / sizeof(arr[0]);

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout<<"array size : " << n;
    cout << endl;
    std::cout << "Time taken: " << duration.count() << " microseconds." << endl;
    //To print sorted array
    // cout << "Sorted array: ";
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }

    return 0;
}
