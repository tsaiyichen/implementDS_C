#include <iostream>
#include "Heap.hpp"

using namespace std;

int main(){
    int arr1[]{2, 5, 7, 3, 8, 6, 9, 10};
    Heap heap1(arr1, 8, "top-down");
    heap1.printHeap();
    printf("heap1 size: %d\n", heap1.getSize());
    Heap heap2(arr1, 8, "bottom-up");
    heap2.printHeap();
    printf("heap2 size: %d\n", heap2.getSize());
    printf("heap2: deleteMax: %d\n", heap2.deleteMax());
    heap2.printHeap();
    printf("heap2 size: %d\n", heap2.getSize());
    printf("heap2: insert 10: \n");
    heap2.insertNode(10);
    heap2.printHeap();
    printf("heap2 size: %d\n", heap2.getSize());

    int arr2[]{12, 1, 4, 11, 15, 20};
    Heap heap3(arr2, 6, "bottom-up");
    heap3.printHeap();
    printf("heap3 size: %d\n", heap3.getSize());

    heap1.mergeTwoHeap(heap3);
    heap1.printHeap();
    printf("heap1 size: %d\n", heap1.getSize());
}