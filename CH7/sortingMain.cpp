#include "Sorting.hpp"
#include <iostream>

using namespace std;

void printArray(int* arr, int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main(){
    int arr[] {5, 3, 1, 8, 6, 9, 7, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    //printArray(arr, n);
    //cout << "\n" << endl;
    //Elementary_Sorting::insertionSort(arr, n);
    //Elementary_Sorting::selectionSort(arr, n);
    //Elementary_Sorting::bubbleSort(arr, n);
    //Advanced_Sorting::quickSort(arr, 0, n - 1);
    //Advanced_Sorting::mergeSort(arr, 0, n - 1);
    //Advanced_Sorting::heapSort(arr, n);
    //printArray(arr, n);
    int arr2[]{151, 97, 61, 367, 54, 87, 764, 152, 648, 792, 123, 467, 571};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    //printArray(arr2, n2);
    //Linear_Sorting::redixSort(arr2, n2);
    //Linear_Sorting::bucketSort(arr2, n2);
    //printArray(arr2, n2);
    int arr3[]{0, 2, 2, 6, 4, 2, 8, 8, 9, 9, 6, 4, 2, 3, 3, 3, 1, 7, 1, 5,1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printArray(arr3, n3);
    Linear_Sorting::countingSort(arr3, n3);
    printArray(arr3, n3);

}