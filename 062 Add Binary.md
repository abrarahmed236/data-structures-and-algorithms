# Add Binary (Problem 67)

Reverse both strings  
Add zero padding to smaller string  
Add Binary numbers  
Reverse the resulting string

```cpp
class Solution {
   public:
    string addBinary(string a, string b) {
        if (a.size() > b.size()) swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() < b.size()) a.push_back('0');
        int carry = 0, sum;
        string result;
        for (int i = 0; i < a.size(); i++) {
            sum = carry + a[i] - '0' + b[i] - '0';
            result.push_back(sum & 1 ? '1' : '0');
            carry = sum & 2 ? 1 : 0;
        }
        if (carry) result.push_back('1');
        reverse(result.begin(), result.end());
        return result;
    }
};
```
