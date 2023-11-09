# Letter Combinations of Phone Number (Problem 17)

As good as it gets for this problem.

```cpp
class Solution {
    unordered_map<char, string> mp;
    vector<string> result;
    string curr;
    void init() {
        curr = "";
        result.reserve(128);
        curr.reserve(16);
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
    }
    void back_track(string& digits, int ind) {
        if (ind == digits.size()) {
            if (curr != "") result.push_back(curr);
        } else {
            for (auto c : mp[digits[ind]]) {
                curr.push_back(c);
                back_track(digits, ind + 1);
                curr.pop_back();
            }
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        init();
        back_track(digits, 0);
        return result;
    }
};
```
