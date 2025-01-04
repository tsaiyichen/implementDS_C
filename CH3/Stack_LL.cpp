#include "Stack_LL.hpp"
#include <iostream>
using namespace std;

void Stack_LL::push(int item) {
    node* newNode = new node(item);
    newNode->next = top;
    top = newNode;
}

int Stack_LL::pop() {
    if(top == nullptr){
        cout << "Stack is empty. Go shit.";
        return INT_MIN;
    }else{
        auto curNode = top;
        top = top->next;
        int item = curNode->data;
        delete curNode;
        return item;
    }
}

int Stack_LL::peek() {
    return top->data;
}
