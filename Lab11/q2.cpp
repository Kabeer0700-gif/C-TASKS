#include <iostream>
#include <exception>
using namespace std;


class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
private:
    T* data;
    int front, rear, size, capacity;

public:
    Queue(int cap) : capacity(cap), front(0), rear(0), size(0) {
        data = new T[capacity];
    }

    void enqueue(const T& item) {
        if (size == capacity)
            throw QueueOverflowException();
        data[rear] = item;
        rear = (rear + 1) % capacity;
        ++size;
    }

    T dequeue() {
        if (size == 0)
            throw QueueUnderflowException();
        T item = data[front];
        front = (front + 1) % capacity;
        --size;
        return item;
    }

    ~Queue() {
        delete[] data;
    }
};

int main() {
    Queue<int> q(2);

    // Test overflow
    try {
        cout << "Attempting to enqueue to a full queue...\n";
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3); 
    } catch (const QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

   
    try {
        q.dequeue();
        q.dequeue();
    } catch (...) {} 

    // Test underflow
    try {
        cout << "\nAttempting to dequeue from an empty queue...\n";
        q.dequeue(); 
    } catch (const QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
