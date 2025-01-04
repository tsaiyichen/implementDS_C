#include "QueueANDStack.hpp"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void StackImplementsQueue::enQueue(int x) {
    s1.push(x);
}

int StackImplementsQueue::deQueue() {
    if(s2.empty()){
        if(s1.empty()){
            cout << "queue empty." << endl;
            return INT_MIN;
        }else{
            do{
                int x = s1.top();//because stack pop will not return element
                s1.pop();
                s2.push(x);
            }while(!s1.empty());

        }
    }
    int res = s2.top();
    s2.pop();
    return res;
}

void QueueImplementsStack::push(int x) {
    q.push(x); //because enqueue = push, dequeue = pop in C++
}

int QueueImplementsStack::pop() {
    if(q.empty()){
        cout << "stack empty." << endl;
        return INT_MIN;
    }
    for(int i = 0; i < q.size() - 1; i++){
        int x = q.front();
        q.pop();
        q.push(x);
    }
    int res = q.front();
    q.pop();
    return res;
}
