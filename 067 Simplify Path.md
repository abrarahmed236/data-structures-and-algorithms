# Simplify Path (Problem 71)

Push filenames / directory names on a stack.
Pop if ".."
Use the stack to construct the final result
```cpp
class Solution {
   public:
    string simplifyPath(string path) {
        for (char& c : path)
            if (c == '/') c = ' ';
        stringstream ss(path);
        string word;
        vector<string> stk;

        string result = "/";
        while (ss >> word) {
            if (word == ".." && stk.size()) stk.pop_back();
            if (word == "." || word == "..") continue;
            stk.push_back(word);
        }
        for (string& word : stk) result += word + "/";
        if (result.size() > 1) result.pop_back();

        return result;
    }
};
```

Same approach but without using stringstream
```cpp
class Solution {
   public:
    string simplifyPath(string path) {
        int N = path.size();
        vector<string> stk;
        stk.reserve(256);
        string result = "/";

        for (int i = 0; i < N; i++) {
            if (path[i] == '/') continue;
            string word;
            while (i < N && path[i] != '/') word.push_back(path[i++]);

            if (word == ".")
                continue;
            else if (word == "..") {
                if (stk.size()) stk.pop_back();
            } else
                stk.push_back(word);
        }

        for (string& word : stk) result += word + "/";
        if (result.size() > 1) result.pop_back();

        return result;
    }
};
```
