# Evaluate Reverse Polish Notation (Problem 150)

Straightforward

```cpp
class Solution {
    inline bool isnum(string token) {
        return (token.size() != 1) || (token.size() == 1 && isdigit(token[0]));
    }
    int do_op(int A, int B, char op) {
        switch (op) {
            case '+':
                return A + B;
            case '-':
                return A - B;
            case '*':
                return A * B;
            case '/':
                return A / B;
            default:
                return INT_MIN;
        }
    }

   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto token : tokens) {
            if (isnum(token)) {
                stk.push(stoi(token));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                stk.push(do_op(num1, num2, token[0]));
            }
        }
        return stk.top();
    }
};
```
