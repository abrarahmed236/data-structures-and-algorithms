# Min Stack (Problem 155)

Maintain another stack that has the minimum value uptil now.

```cpp
class MinStack {
    stack<int> stk;
    stack<int> min_stk;

   public:
    MinStack() {}

    void push(int val) {
        stk.push(val);
        if (!min_stk.size())
            min_stk.push(val);
        else
            min_stk.push(min(min_stk.top(), val));
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return min_stk.top(); }
};
```
