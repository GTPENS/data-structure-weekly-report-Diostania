#include <iostream>
#include <stack>

template<typename T>
void insertAtBottom(std::stack<T>& stk, const T& value) {
    if (stk.empty()) {
        stk.push(value);
    } else {
        T temp = stk.top();
        stk.pop();
        insertAtBottom(stk, value);
        stk.push(temp);
    }
}

template<typename T>
void reverseStack(std::stack<T>& stk) {
    if (stk.empty()) {
        return;
    } else {
        T value = stk.top();
        stk.pop();
        reverseStack(stk);
        insertAtBottom(stk, value);
    }
}

int main() {
    std::stack<int> stk;

    // Push elements onto the stack
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    // Print the original stack
    std::cout << "Original Stack: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << std::endl;

    // Push elements again onto the stack
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    // Reverse the stack
    reverseStack(stk);

    // Print the reversed stack
    std::cout << "Reversed Stack: ";
    while (!stk.empty()) {
        std::cout << stk.top() << " ";
        stk.pop();
    }
    std::cout << std::endl;

    return 0;
}

/*Kode ini menunjukkan cara menggunakan template untuk membuat fungsi generik yang dapat bekerja dengan tipe data apapun dan teknik rekursi untuk membalikkan isi stack.*/