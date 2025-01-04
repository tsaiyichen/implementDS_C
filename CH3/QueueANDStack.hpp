#ifndef IMPLEMENTDS_C_QUEUEANDSTACK_HPP
#define IMPLEMENTDS_C_QUEUEANDSTACK_HPP
#include <stack>
#include <queue>

using namespace std;

class StackImplementsQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void enQueue(int x);
    int deQueue();
};

class QueueImplementsStack{
private:
    queue<int> q;
public:
    void push(int x);
    int pop();
};


#endif //IMPLEMENTDS_C_QUEUEANDSTACK_HPP
