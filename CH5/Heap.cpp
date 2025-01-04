#include "Heap.hpp"
#include <iostream>
using namespace std;

Heap::Heap(int arr[], int n, string method) {
    if(method == "bottom-up"){
        for(int i = 0; i < n; i++){
            heap[i] = arr[i];
        }
        setSize(n);
        int lastParent = size / 2 - 1;
        for(int i = lastParent; i >= 0; i--){
            adjust(i);
        }
    }else{
        for(int i = 0; i < n; i++){
            insertNode(arr[i]);
        }
    }
}

void Heap::setSize(int x) {
    size = x;
}

void Heap::insertNode(int x) {
    heap[size] = x;
    int child = size;
    int parent = (size - 1) / 2;
    while(child != 0){
        if(x > heap[parent]){
            heap[child] = heap[parent];
            child = parent;
            parent = (parent - 1) / 2;
        }else{
            break;
        }
    }
    heap[child] = x;
    size++;
}

int Heap::deleteMax() {
    int ans = heap[0];
    heap[0] = heap[--size];
    adjust(0);
    return ans;
}

void Heap::adjust(int i) {
    int x = heap[i];
    int parent = i;
    int child = parent * 2 + 1;
    while(child < size){
        if(child + 1 < size && heap[child] < heap[child + 1]){
            child++;
        }
        if(heap[child] > x){
            heap[parent] = heap[child];
            parent = child;
            child = child * 2 + 1;
        }else{
            break;
        }
    }
    heap[parent] = x;
}

int Heap::findMax() {
    return heap[0];
}

void Heap::mergeTwoHeap(Heap &h2) {
    int arr[size + h2.size];
    for(int i = 0; i < size; i++){
        arr[i] = heap[i];
    }
    for(int j = 0; j < h2.size; j++){
        arr[j + size] = h2.heap[j];
    }
    Heap h3(arr, size + h2.size, "bottom-up");
    for(int i = 0; i < size + h2.size; i++){
        heap[i] = h3.heap[i];
    }
    setSize(size + h2.size);
}

void Heap::printHeap() {
    cout << "heap: ";
    for(int i = 0; i < size; i++){
        cout << heap[i] << "  ";
    }
}
