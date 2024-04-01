#include <iostream>

class Queue {
private:
    class Node {
    public:
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };

    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    int size() {
        return count;
    }

    bool Empty() {
        return count == 0;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
    }

    int peek() {
        if (Empty()) {
            throw std::runtime_error("QueueEmptyException");
        }
        return head->value;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (Empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    int dequeue() {
        if (Empty()) {
            throw std::runtime_error("QueueEmptyException");
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }
};

int main() {
    Queue myQueue;

    // Example operations
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Queue size: " << myQueue.size() << std::endl;
    std::cout << "Front element: " << myQueue.peek() << std::endl;

    myQueue.dequeue();
    std::cout << "Queue size after dequeue: " << myQueue.size() << std::endl;

    return 0;
}

/*Kode ini ditulis dalam C++ untuk mengimplementasikan struktur data Queue menggunakan Linked List. 
Queue bersifat FIFO (First-In-First-Out), yang dimana elemen yang pertama masuk akan keluar terlebih dahulu.
*/