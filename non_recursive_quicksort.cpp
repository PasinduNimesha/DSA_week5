#include <iostream>
#include <stack>
#include <chrono>
using namespace std;


void quickSort(int arr[], int l, int h)
{
    stack<int> pStack;
    int temp;

    pStack.push(l);
    pStack.push(h);

    while (!pStack.empty())
    {
        h = pStack.top();
        pStack.pop();
        l = pStack.top();
        pStack.pop();

        int pivot = arr[h];
        int i = (l - 1);
        for (int j = l; j <= h - 1; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
  
            }
        }
        temp = arr[i+1];
        arr[i+1] = arr[h];
        arr[h] = temp;

        int pivotIndex = i + 1;

        if (pivotIndex - 1 > l)
        {
            pStack.push(l);
            pStack.push(pivotIndex - 1);
        }

        if (pivotIndex + 1 < h)
        {
            pStack.push(pivotIndex + 1);
            pStack.push(h);
        }
    }
}


int main() {
    int arr[] = {113, 175, 19, 187, 272, 322, 960, 389, 876, 285, 138, 592};
    int n = sizeof(arr) / sizeof(arr[0]);


    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "array size: "<< n;
    cout << endl;
    cout << "Time taken: " << duration.count() << " microseconds." << endl;
    //To print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
