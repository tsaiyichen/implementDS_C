#ifndef IMPLEMENTDS_C_STACK_LL_HPP
#define IMPLEMENTDS_C_STACK_LL_HPP


class Stack_LL{
protected:
    struct node{
        int data;
        node* next = nullptr;
        explicit node(const int d){
            data = d;
        }
    };
    node* top = nullptr;
public:
    void push(int);
    int pop();
    int peek();

};


#endif //IMPLEMENTDS_C_STACK_LL_HPP
