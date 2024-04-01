#include <iostream>
#include <stack>
#include <string>

bool isBalancedParenthesis(const std::string& expn) {
    std::stack<char> stk;
    for (char ch : expn) {
        switch (ch) {
            case '{':
            case '[':
            case '(':
                stk.push(ch);
                break;
            case '}':
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
                break;
            case ']':
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
                break;
            case ')':
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
                break;
        }
    }
    return stk.empty();
}

int main() {
    std::string expn = "{()}[";
    bool value = isBalancedParenthesis(expn);
    std::cout << "Given Expn: " << expn << std::endl;
    std::cout << "Result after isParenthesisMatched: " << std::boolalpha << value << std::endl;

    return 0;
}

/* Program dalam bahasa C++ ini bertujuan untuk memverifikasi struktur data stack untuk menyimpan kurung buka dan memastikan bahwa setiap kurung buka memiliki pasangannya yang sesuai dengan kurung tutup.
fungsi isBalancedParenthesis, program menerima input dan melakukan iterasi pada setiap karakternya. 
Setiap kali menemukan kurung buka, program akan menambahkannya ke dalam stack.
Ketika menemukan kurung tutup, program akan memeriksa apakah kurung tersebut sesuai dengan kurung buka yang berada di puncak stack. 
Jika tidak sesuai, program akan mengembalikan nilai false. Namun, jika sesuai, program akan menghapus kurung buka yang sesuai dari stack.
Tujuan dari program ini adalah untuk memastikan bahwa setiap kurung dalam memiliki pasangannya dengan benar, sehingga meminimalkan kesalahan dalam analisis dan eksekusi ekspresi tersebut
*/