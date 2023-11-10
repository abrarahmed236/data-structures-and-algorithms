# Text Justification (Problem 68)

Rough solution. Needs cleanup

```cpp

class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        queue<string, deque<string>> word_q(
            deque<string>(words.begin(), words.end()));

        vector<string> result;
        vector<string> line;
        int line_size = 0;
        vector<string> padding;
        while (!word_q.empty()) {
            if (line_size == 0) {
                line.push_back(word_q.front());
                line_size += word_q.front().size();
                word_q.pop();
            } else {
                if (line_size + word_q.front().size() + 1 <= maxWidth) {
                    padding.push_back(" ");
                    line.push_back(word_q.front());
                    line_size += 1 + word_q.front().size();
                    word_q.pop();
                } else {
                    if (padding.size()) {
                        int i = 0;
                        while (line_size < maxWidth) {
                            padding[i] += " ";
                            line_size++;
                            i = (i + 1) % (int)padding.size();
                        }
                    }

                    result.push_back("");
                    for (int i = 0; i < padding.size(); i++) {
                        result.back() += line[i] + padding[i];
                    }
                    result.back() += line.back();

                    while (line_size < maxWidth) {
                        result.back() += " ";
                        line_size++;
                    }

                    padding.clear();
                    line.clear();
                    line_size = 0;
                }
            }
        }
        if (!line.empty()) {
            result.push_back("");
            for (int i = 0; i < padding.size(); i++) {
                result.back() += line[i] + padding[i];
            }
            result.back() += line.back();
            while (line_size < maxWidth) {
                result.back() += " ";
                line_size++;
            }
        }

        return result;
    }
};
```
