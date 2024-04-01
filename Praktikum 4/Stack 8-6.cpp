#include <iostream>
#include <stack>
#include <string>

int precedence(char op) {
    switch (op) {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

std::string infixToPrefix(const std::string& expn) {
    std::stack<char> operators;
    std::string prefixExpn = "";

    for (int i = expn.length() - 1; i >= 0; i--) {
        char ch = expn[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            prefixExpn = ch + prefixExpn;
        } else if (ch == ')') {
            operators.push(ch);
        } else if (ch == '(') {
            while (!operators.empty() && operators.top() != ')') {
                prefixExpn = operators.top() + prefixExpn;
                operators.pop();
            }
            operators.pop(); // Discard ')'
        } else {
            while (!operators.empty() && precedence(ch) < precedence(operators.top())) {
                prefixExpn = operators.top() + prefixExpn;
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        prefixExpn = operators.top() + prefixExpn;
        operators.pop();
    }

    return prefixExpn;
}

int main() {
    std::string expn = "10+((3))*5/(16-4)";
    std::string value = infixToPrefix(expn);
    std::cout << "Infix Expn: " << expn << std::endl;
    std::cout << "Prefix Expn: " << value << std::endl;

    return 0;
}

//Program ini membantu mengubah ekspresi infix ke prefix, yang memungkinkan evaluasi ekspresi dengan cara berbeda menggunakan stack.