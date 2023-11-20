# Basic Calculator (Problem 224)

Ignore the `'+'` and `' '` characters.  
If you see a `'-'`, then store a sign as `-1`.  
When you see a number, multiply the number by the sign and add to the sum.  
When you see a `'('`, store the current sum and current sign to the stack.  
When you see a `')'`, pop the stack, and current sum to it using the sign.

```cpp
class Solution {
   public:
    int calculate(string s) {
        stack<pair<int, int>> stk;
        long sum = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                long num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                i--;
                sum += num * sign;
                sign = +1;
            } else if (ch == '(') {
                stk.push({sum, sign});
                sum = 0;
                sign = +1;
            } else if (ch == ')') {
                sum = stk.top().first + stk.top().second * sum;
                stk.pop();
            } else if (ch == '-') {
                sign *= -1;
            }
        }

        return sum;
    }
};
```
