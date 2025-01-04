#include "Queue_LL.hpp"
#include <iostream>

using namespace std;

void Queue_LL_Single::enqueue(int x) {
    node* newNode = new node(x);
    if(front == nullptr){
        front = newNode;
    }else{
        rear->next = newNode;
    }
    rear = newNode;
}

int Queue_LL_Single::dequeue() {
    if(front == nullptr){
        cout << "Queue empty." << endl;
        return INT_MIN;
    }
    node* temp = front;
    front = front->next;
    if(front == nullptr){
        rear = nullptr;
    }
    int x = temp->data;
    delete temp;
    return x;
}

void Queue_LL_Circular::enqueue(int x) {
    node* newNode = new node(x);
    if(rear == nullptr){
        newNode->next = newNode;
    }else{
        newNode->next = rear->next;
        rear->next = newNode;
    }
    rear = newNode;
}

int Queue_LL_Circular::dequeue() {

    if(rear == nullptr){
        cout << "Queue empty." << endl;
        return INT_MIN;
    }else{
        node* temp = rear->next;
        if(temp == rear){
            rear = nullptr;
        }else{
            rear->next = rear->next->next;
        }
        int x = temp->data;
        delete temp; //free memory
        return x;
    }
}
