#ifndef IMPLEMENTDS_C_HEAP_HPP
#define IMPLEMENTDS_C_HEAP_HPP
#include <iostream>
using namespace std;

class Heap {
    //max heap
private:
    static constexpr int MAX = 256;
    int heap[MAX]{};
    int size = 0;
public:
    Heap(int arr[], int n, string method);
    void insertNode(int x);
    int deleteMax();
    void adjust(int i);
    int findMax();
    void setSize(int x);
    int getSize(){
        return size;
    }
    void mergeTwoHeap(Heap &h2);
    void printHeap();
};


#endif //IMPLEMENTDS_C_HEAP_HPP
