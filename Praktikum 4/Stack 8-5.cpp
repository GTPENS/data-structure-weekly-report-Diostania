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

std::string infixToPostfix(const std::string& expn) {
    std::stack<char> stk;
    std::string output = "";

    for (char ch : expn) {
        if (ch >= '0' && ch <= '9') {
            output += ch;
        } else {
            switch (ch) {
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while (!stk.empty() && precedence(ch) <= precedence(stk.top())) {
                        output += " ";
                        output += stk.top();
                        stk.pop();
                    }
                    stk.push(ch);
                    output += " ";
                    break;
                case '(':
                    stk.push(ch);
                    break;
                case ')':
                    while (!stk.empty() && stk.top() != '(') {
                        output += " ";
                        output += stk.top();
                        stk.pop();
                    }
                    stk.pop(); // Pop '('
                    break;
            }
        }
    }

    while (!stk.empty()) {
        output += " ";
        output += stk.top();
        stk.pop();
    }

    return output;
}

int main() {
    std::string expn = "10+((3))*5/(16-4)";
    std::string value = infixToPostfix(expn);
    std::cout << "Infix Expn: " << expn << std::endl;
    std::cout << "Postfix Expn: " << value << std::endl;

    return 0;
}

/*Program ini membantu mengonversi ekspresi infix ke postfix, yang berguna untuk evaluasi ekspresi menggunakan stack. 
Program menentukan prioritas operator untuk memastikan operasi dilakukan dengan urutan yang benar.
*/