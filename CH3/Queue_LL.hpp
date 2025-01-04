#ifndef IMPLEMENTDS_C_QUEUE_LL_HPP
#define IMPLEMENTDS_C_QUEUE_LL_HPP


class Queue_LL_Single {
    private:
        struct node {
            int data;
            node *next = nullptr;

            explicit node(const int d) {
                data = d;
            }
        };
        node* front = nullptr;
        node* rear = nullptr;
    public:
        void enqueue(int x);
        int dequeue();
};

class Queue_LL_Circular{
    private:
        struct node {
            int data;
            node *next = nullptr;

            explicit node(const int d) {
                data = d;
            }
        };
        node* rear = nullptr;
    public:
        void enqueue(int x);
        int dequeue();
};


#endif //IMPLEMENTDS_C_QUEUE_LL_HPP
