# Generate Parenthesis (Problem 22)

Quick and Dirty

```cpp
class Solution {
    static const int debug = false;

   public:
    void util(int& open, int& close, string& curr, vector<string>& result) {
        if (close == 0) {
            result.push_back(curr);
            return;
        }
        if (open == 0) {
            open++;
            curr.push_back('(');
            util(open, close, curr, result);
            curr.pop_back();
            open--;
            return;
        }
        if (open == close) {
            open--;
            close--;
            curr.push_back(')');
            util(open, close, curr, result);
            curr.pop_back();
            open++;
            close++;
            return;
        }
        open++;
        curr.push_back('(');
        util(open, close, curr, result);
        curr.pop_back();
        open--;

        open--;
        close--;
        curr.push_back(')');
        util(open, close, curr, result);
        open++;
        close++;
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = n;
        string curr;
        vector<string> result;
        util(open, close, curr, result);
        return result;
    }
};
```

Much cleaner implemenation of the same method above. Performs well.

```cpp
class Solution {
    static const int debug = false;

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        util(0, n, "", result);
        return result;
    }
    void util(int open, int close, string curr, vector<string>& result) {
        if (close == 0) {
            result.push_back(curr);
            return;
        }
        if (open < close) util(open + 1, close, curr + "(", result);
        if (open > 0) util(open - 1, close - 1, curr + ")", result);
    }
};
```
