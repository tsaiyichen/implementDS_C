#include "Sorting.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
void Elementary_Sorting::arrSwap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Elementary_Sorting::insertionSort(int *arr, int n) {
    for(int i = 1; i < n; i++){
        int x = arr[i];
        int j;
        for(j = i; j > 0; j--){
            if(x < arr[j - 1]){
                arr[j] = arr[j - 1];
            }else{
                break;
            }
        }
        arr[j] = x;
    }
}

void Elementary_Sorting::selectionSort(int *arr, int n) {
    for(int i = 0; i < n - 1; i++){
        int minIndex = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            arrSwap(arr, i, minIndex);
        }
    }
}

void Elementary_Sorting::bubbleSort(int *arr, int n) {
    for(int i = 0; i < n; i++){
        bool flag = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                arrSwap(arr, j, j+1);
                flag = true;
            }
        }
        if(!flag){
            break;
        }
    }
}

void Advanced_Sorting::arrSwap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Advanced_Sorting::quickSort(int *arr, int l, int r) {
    //arr[l] ~ arr[r] use Hoare Partition or Comen
    if(l >= r) return;
    //int q = HoarePartition(arr, l, r);
    int q = ComenPartition(arr, l, r);
    quickSort(arr, l, q-1);
    quickSort(arr, q+1, r);
}

int Advanced_Sorting::HoarePartition(int *arr, int l, int r) {
    int pk = arr[l]; //leftmost
    int i = l+1;
    int j = r;
    while(true){
        while(i <= r && arr[i] <= pk) i++;
        while(arr[j] >= pk) j--;
        if(i < j){
            arrSwap(arr, j, i);
            i++;j--;
        }else{
            arrSwap(arr, l, j);
            break;
        }
    }


    return j;
}

int Advanced_Sorting::ComenPartition(int *arr, int l, int r) {
    int pk = arr[r]; //right most
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(arr[j] <= pk){
            arrSwap(arr, j, ++i);
        }
    }
    arrSwap(arr, ++i, r);
    return i;
}

void Advanced_Sorting::mergeSort(int *arr, int l, int r) {
    if(l >= r) return;
    // not sorting in-place
    int temp[r - l + 1];
    int count = 0;

    int mid = (l + r) / 2;
    printf("%d, %d, %d\n", l, r, mid);
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    printf("%d, %d, %d finish\n", l, r, mid);
    // merge
    int i = l;
    int j = mid+1;

    while(i <= mid && j <= r){
        if(arr[i] > arr[j]){
            temp[count] = arr[j];
            count++;
            j++;
        }else{
            temp[count] = arr[i];
            count++;
            i++;
        }
    }
    while(i <= mid){
        temp[count] = arr[i];
        count++;
        i++;
    }

    while(j < r + 1){
        temp[count] = arr[j];
        count++;
        j++;
    }

    for(int i = 0; i < count; i++){
        arr[l + i] = temp[i];
    }
}

void Advanced_Sorting::heapSort(int *arr, int n) {
    //bottom-up to build Max-heap
    int lastParent = n / 2 - 1;
    for(int i = lastParent; i >= 0; i--){
        heapAdjust(arr, i, n);
    }
    for(int i = n - 1; i > 0; i--){
        arrSwap(arr, 0, i);
        heapAdjust(arr, 0, i);
    }
}

void Advanced_Sorting::heapAdjust(int* arr, int i, int n) {
    int p = i;
    int x = arr[i];
    int c = 2 * i + 1;

    while(c < n){
        if(c + 1 < n && arr[c + 1] > arr[c]){
            c++;
        }

        if(arr[c] > x){
            arr[p] = arr[c];
            p = c;
            c = 2 * c + 1;
        }else{
            break;
        }
    }
    arr[p] = x;
}

void Linear_Sorting::redixSort(int *arr, int n) {
    int d = 3;
    int R = 10;
    //set bucket
    vector<vector<int>> bucket(R);

    for(int i = 1; i <= d; i++){
        //distribution
        int div = pow(10, i);
        for(int j = 0; j < n; j++) {
            int num = (arr[j] % div) / pow(R, i - 1);
            bucket[num].push_back(arr[j]); //FIFO
        }
        //merge
        int arrCount = 0;
        for(int i = 0; i < bucket.size(); i++){
            vector<int> cur = bucket[i];
            for(int j = 0; j < cur.size(); j++){
                arr[arrCount] = cur[j];
                arrCount++;
            }
        }
        //flush
        bucket.clear();
        bucket.resize(10);
    }

}

void Linear_Sorting::bucketSort(int *arr, int n) {
    int d = 3;
    int R = 10;
    vector<vector<int>> bucket(R);

    //distribution
    for(int i = 0; i < n; i++){
        int num = arr[i] / pow(R, d - 1);
        bucket[num].push_back(arr[i]);
    }
    //sorting
    for(int i = 0; i < R; i++){
        std::sort(bucket[i].begin(), bucket[i].end());
    }
    //merge
    int arrCount = 0;
    for(int i = 0; i < bucket.size(); i++){
        vector<int> cur = bucket[i];
        for(int j = 0; j < cur.size(); j++){
            arr[arrCount] = cur[j];
            arrCount++;
        }
    }

}

void Linear_Sorting::countingSort(int *arr, int n) {
    //assume range is 0 ~ 9
    int start[10];
    int count[10];
    int result[n];
    //init
    for(int i = 0; i < 10; i++){
        count[i] = 0;
    }
    //count
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    //set start (or end)
    start[0] = 0;
    for(int i = 1; i < 10; i++){
        start[i] = count[i - 1] + start[i - 1];
    }

    //fill the result
    for(int i = 0; i < n; i++){
        result[start[arr[i]]] = arr[i];
        start[arr[i]]++;
    }
    //copy to array
    for(int i = 0; i < n; i++){
        arr[i] = result[i];
    }
}
