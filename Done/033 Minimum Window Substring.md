# Minimum Window Substring (Problem 76) 

Similar to previous problem
```cpp
const bool debug = false;

class Solution {
    unordered_map<char, int> counter;
    unordered_map<char, int> used;
    int matched_letters;
    int win_beg, win_size;

    void push(char c) {
        if(counter.count(c)) {
            used[c]++;
            if(used[c] == counter[c]) {
                matched_letters++;
            } 
            // else if(used[c] == counter[c] + 1) {
            //     matched_letters--;
            // }
        }
    }

    void pop(char c) {
        if(counter.count(c)) {
            used[c]--;
            // if(used[c] == counter[c]) {
            //     matched_letters++;
            // } else 
            if(used[c] <= counter[c] - 1) {
                matched_letters--;
            }
        }
    }

    void consider_window(int beg, int size) {
        // cout <<matched_letters<< counter.begin()->second << endl;
        if(matched_letters == counter.size() && size < win_size) {
            win_beg = beg;
            win_size = size;
        }
    }

public:

    string minWindow(string s, string t) {
        for(char c: t) counter[c]++;
        matched_letters = 0;
        win_beg = 0;
        win_size = INT_MAX;

        int beg = 0;
        int size = 1;
        push(s[beg]);
        consider_window(beg, size);
        if(debug) cout << beg << size << endl;
        while(beg + size < s.size()) {
            while(matched_letters < counter.size() && beg + size < s.size()) {
                push(s[beg+size]);
                size++;
                consider_window(beg, size);
                if(debug) cout << "here1" << endl;
            
            if(debug) {
                string subs = s.substr(beg, size);
                cout << subs << ":" << matched_letters << endl;
            }
            }
            while(matched_letters >= counter.size() && beg < s.size()) {
                pop(s[beg]);
                beg++; size--;
                consider_window(beg, size);
                if(debug) cout << "here2" << endl;
            
            if(debug) {
                string subs = s.substr(beg, size);
                cout << subs << ":" << matched_letters << endl;
            }
            }
            if(debug) {
                string subs = s.substr(beg, size);
                cout << subs << ":" << matched_letters << endl;
            }
        }

        return win_size==INT_MAX ? "" : s.substr(win_beg, win_size);
    }
};
```


good solution but can do better.

...
