#include "Queue_array.hpp"
#include <iostream>

using namespace std;

void Queue_array_Linear::enqueue(int x) {
    if(rear >= MAX - 1){
        cout << "Queue full." << endl;
        return;
    }
    rear++;
    array[rear] = x;
}

int Queue_array_Linear::dequeue() {
    if(front == rear){
        cout << "Queue empty." << endl;
        return INT_MIN;
    }else{
        front++;
        return array[front];
    }
}

void Queue_array_Circular1::enqueue(int x) {
    //use N - 1 space
    rear = (rear + 1) % MAX;
    if(rear == front){
        rear = (rear - 1) % MAX;
        cout << "Queue full." << endl;
        return;
    }else{
        array[rear] = x;
    }
}

int Queue_array_Circular1::dequeue() {
    if(front == rear){
        cout << "Queue empty." << endl;
        return INT_MIN;
    }else{
        front = (front + 1) % MAX;
        return array[front];
    }
}

void Queue_array_Circular2::enqueue(int x) {
    if((rear == front) && tag){
        cout << "Queue full." << endl;
        return;
    }else{
        rear = (rear + 1) % MAX;
        array[rear] = x;
        if(rear == front) tag = true;
    }
}

int Queue_array_Circular2::dequeue() {
    if((rear == front) && !tag){
        cout << "Queue empty." << endl;
        return INT_MIN;
    }else{
        front = (front + 1) % MAX;
        if(front == rear) tag = false;
        return array[front];
    }
}


