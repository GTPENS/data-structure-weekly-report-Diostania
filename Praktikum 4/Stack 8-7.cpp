#include <iostream>
#include <stack>
#include <string>
#include <sstream> 
#include <cctype> 

int postfixEvaluate(const std::string& expn) {
    std::stack<int> stk;
    std::stringstream ss(expn);
    std::string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            if (token == "+") stk.push(num1 + num2);
            else if (token == "-") stk.push(num1 - num2);
            else if (token == "*") stk.push(num1 * num2);
            else if (token == "/") stk.push(num1 / num2);
        } else {
            // Check if the token is a number
            bool isNumber = true;
            for (char c : token) {
                if (!std::isdigit(c)) {
                    isNumber = false;
                    break;
                }
            }
            if (isNumber) {
                stk.push(std::stoi(token));
            } else {
                // Handle invalid token (not an operator or a number)
                std::cerr << "Invalid token encountered: " << token << std::endl;
                exit(1);
            }
        }
    }

    return stk.top();
}

int main() {
    std::string expn = "6 5 2 3 + 8 * + 3 + *";
    int value = postfixEvaluate(expn);
    std::cout << "Given Postfix Expn: " << expn << std::endl;
    std::cout << "Result after Evaluation: " << value << std::endl;

    return 0;
}

/*
Program ini bertujuan untuk mengevaluasi input matematika dalam notasi postfix (notasi belakang).
Evaluasi ini dilakukan menggunakan struktur data stack (tumpukan).*/