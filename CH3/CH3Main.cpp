#include "QueueANDStack.hpp"
#include <iostream>

using namespace std;

int main(){
    QueueImplementsStack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    StackImplementsQueue q1;
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    cout << q1.deQueue() << endl;
    cout << q1.deQueue() << endl;
    cout << q1.deQueue() << endl;
    cout << q1.deQueue() << endl;
}
