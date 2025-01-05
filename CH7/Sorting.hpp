#ifndef IMPLEMENTDS_C_SORTING_HPP
#define IMPLEMENTDS_C_SORTING_HPP


class Elementary_Sorting {
public:
    static void arrSwap(int* arr, int i, int j);
    static void insertionSort(int* arr, int n);
    static void selectionSort(int* arr, int n);
    static void bubbleSort(int* arr, int n);
};

class Advanced_Sorting{
public:
    static void arrSwap(int* arr, int i, int j);
    static void quickSort(int* arr, int l, int r);
    static void mergeSort(int* arr, int l, int r);
    static void heapSort(int* arr, int n);
private:
    static int HoarePartition(int* arr, int l, int r);
    static int ComenPartition(int* arr, int l, int r);
    static void heapAdjust(int* arr, int i, int n);
};

class Linear_Sorting{
    //assume that the domain 0 ~ 999, R = 10 base
public:
    static void redixSort(int* arr, int n);
    static void bucketSort(int* arr, int n);
    static void countingSort(int* arr, int n);

};

#endif //IMPLEMENTDS_C_SORTING_HPP
