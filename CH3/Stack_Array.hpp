#ifndef IMPLEMENTDS_C_STACK_ARRAY_HPP
#define IMPLEMENTDS_C_STACK_ARRAY_HPP

class Stack_Array{
protected:
    static constexpr int MAX = 256;
    int array[MAX]{}; //clean
    int top = -1;
public:
    void push(int);
    int pop();
    int peek();
    bool isEmpty();
};


#endif //IMPLEMENTDS_C_STACK_ARRAY_HPP
