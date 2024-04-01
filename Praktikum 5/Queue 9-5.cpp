#include <iostream>
#include <stack>
#include <stdexcept> // for std::runtime_error

class QueueUsingStack {
private:
    std::stack<int> stk1;
    std::stack<int> stk2;

public:
    QueueUsingStack() {}

    void add(int value) {
        stk1.push(value);
    }

    int remove() {
        int value;
        if (!stk2.empty()) {
            value = stk2.top();
            stk2.pop();
            return value;
        }

        while (!stk1.empty()) {
            value = stk1.top();
            stk1.pop();
            stk2.push(value);
        }

        if (stk2.empty()) {
            throw std::runtime_error("QueueEmptyException");
        }

        value = stk2.top();
        stk2.pop();
        return value;
    }
};

int main() {
    QueueUsingStack que;
    que.add(1);
    que.add(11);
    que.add(111);
    std::cout << que.remove() << std::endl;
    que.add(2);
    que.add(21);
    que.add(211);
    std::cout << que.remove() << std::endl;
    std::cout << que.remove() << std::endl;

    return 0;
}

/*Kode ini menunjukkan cara mengimplementasikan Queue (Antrian) menggunakan dua buah Stack (Tumpukan) di C++. */