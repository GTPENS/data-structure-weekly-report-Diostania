#include <iostream>


class ListStack {
private:
    struct Node {
        int value; 
        Node* next; 
        Node(int v, Node* n) : value(v), next(n) {} 
    };

    Node* head = nullptr; 
    int count = 0; 

public:
    int size() {
        return count; 
    }

    bool empty() {
        return count == 0;
    }

    int peek() {
        if (empty()) {
            throw std::runtime_error("ListStackEmptyException");
        }
        return head->value;
    }

    void push(int value) {
        head = new Node(value, head);
        count++;
    }

    int pop() {
        if (empty()) {
            throw std::runtime_error("ListStackEmptyException");
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }

    void insertAtBottom(int value) {
        if (empty()) {
            push(value);
        } else {
            int temp = pop();
            insertAtBottom(value);
            push(temp);
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    ListStack s;
    for (int i = 1; i <= 100; i++)
        s.push(i);
    for (int i = 1; i <= 50; i++)
        s.pop();
    s.print();

    return 0;
}

/* Kode C++ ini menerapkan struktur data ListStack, yang merupakan implementasi dari tumpukan (stack) menggunakan linked list. 
Stack adalah struktur data yang mengikuti prinsip LIFO (Last-In-First-Out).
Yang berarti elemen terakhir yang dimasukkan adalah yang pertama kali dikeluarkan.

Kelas ListStack memiliki beberapa atribut: head yang merupakan pointer ke (top stack) dan count yang menyimpan jumlah elemen dalam stack.*/