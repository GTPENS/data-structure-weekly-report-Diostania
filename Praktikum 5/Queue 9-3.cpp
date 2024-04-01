#include <iostream>

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
};

int main() {
    Queue myQueue;

    // Example operations
    myQueue.add(10);
    myQueue.add(20);
    myQueue.add(30);

    std::cout << "Queue size: " << myQueue.size() << std::endl;
    std::cout << "Front element: " << myQueue.peek() << std::endl;

    return 0;
}

/* Program ini akan mengalokasikan memori secara dinamis untuk membuat node baru dengan nilai yang diberikan dan mengatur pointer selanjutnya
 jika antrian tidak kosong, node baru temp ditambahkan ke akhir antrian dengan mengatur pointer selanjutnya dari node tail saat ini ke temp, dan kemudian tail diperbarui menjadi temp.
*/