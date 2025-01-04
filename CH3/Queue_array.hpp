#ifndef IMPLEMENTDS_C_QUEUE_ARRAY_HPP
#define IMPLEMENTDS_C_QUEUE_ARRAY_HPP


class Queue_array_Linear {
    private:
        static constexpr int MAX = 256;
        int array[MAX]{};
        int rear = -1;
        int front = -1;
    public:
        void enqueue(int);
        int dequeue();
};
class Queue_array_Circular1 {
private:
    static constexpr int MAX = 256;
    int array[MAX]{};
    int rear = 0;
    int front = 0;
public:
    void enqueue(int);
    int dequeue();
};
class Queue_array_Circular2 {
private:
    static constexpr int MAX = 256;
    int array[MAX]{};
    int rear = 0;
    int front = 0;
    bool tag = false;
public:
    void enqueue(int);
    int dequeue();
};


#endif //IMPLEMENTDS_C_QUEUE_ARRAY_HPP
