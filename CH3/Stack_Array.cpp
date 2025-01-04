#include "Stack_Array.hpp"
#include <iostream>

using namespace std;

void Stack_Array::push(const int x) {
    if(top >= MAX - 1){
        cout << "Stack is full. Go shit.";
        return;
    }
    array[++top] = x;
}

int Stack_Array::pop() {
    if(top < 0){
        cout << "Stack is empty. Go shit.";
        return INT_MIN;
    }

    return array[top--];
}

int Stack_Array::peek() {
    return array[top];
}

bool Stack_Array::isEmpty() {
    if(top < 0) return true;
    else return false;
}
