# Valid Parenthesis (Problem 20)

Straight Forward solution

```cpp
class Solution {
   public:
    bool isValid(string s) {
        stack<int> stk;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else {
                if (stk.empty()) return false;
                char top = stk.top();
                stk.pop();
                if (top == '(' && c != ')') return false;
                if (top == '[' && c != ']') return false;
                if (top == '{' && c != '}') return false;
            }
        }
        return stk.empty();
    }
};
```
