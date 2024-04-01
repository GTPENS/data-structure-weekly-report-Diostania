#include <iostream>
#include <stdexcept>

class Queue {
private:
    class Node {
    public:
        int value;
        Node* next;
        Node(int v, Node* n) : value(v), next(n) {}
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

    void add(int value) {
        Node* temp = new Node(value, nullptr);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        count++;
    }

    int remove() {
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
    Queue q;
    for (int i = 1; i <= 100; i++) {
        q.add(i);
    }
    for (int i = 1; i <= 50; i++) {
        q.remove();
    }
    q.print();

    return 0;
}

/*Kode ini memiliki cara kerja Queue yang lebih lengkap dengan fungsi remove untuk dequeue (pengambilan elemen depan). */