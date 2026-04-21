#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}


int evaluateInfix(string expression) {
    stack<int> values; 
    stack<char> ops;   

    for (int i = 0; i < expression.length(); i++) {
        // Bỏ qua khoảng trắng
        if (expression[i] == ' ') {
            continue;
        }

        if (expression[i] == '(') {
            ops.push(expression[i]);
        }
        else if (isdigit(expression[i])) {
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = (val * 10) + (expression[i] - '0');
                i++;
            }
            i--; 
            values.push(val);
        }
        else if (expression[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty()) {
                ops.pop();
            }
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                
                values.push(applyOp(val1, val2, op));
            }
            // Đẩy toán tử hiện tại vào stack
            ops.push(expression[i]);
        }
    }

    while (!ops.empty()) {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}

int main() {
    string expression;
    
    cout << "Nhap bieu thuc trung to (ho tro +, -, *, /, dau ngoac): ";
    getline(cin, expression);

    int result = evaluateInfix(expression);
    cout << "Gia tri cua bieu thuc: " << result << endl;

    return 0;
}