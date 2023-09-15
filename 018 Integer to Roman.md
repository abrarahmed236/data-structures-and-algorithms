# [Integer to Roman (Problem 12)](https://leetcode.com/problems/integer-to-roman/)

```cpp
class Solution {
   public:
    string intToRoman(int num) {
        // {0, 1, 2, 3}   {4} {5, 6, 7,  8}   {9}
        //     I  II III   IV  V  VI VII VIII  IX
        //     X  XX XXX   XL  L  LX LXX LXXX  XC
        //     C  CC CCC   CD  D  DC DCC DCCC  CM
        //     M  MM MMM

        //     c1, c2, c3 = I, V, X
        //     c1, c2, c3 = X, L, C
        //     c1, c2, c3 = C, D, M
        //     c1, c2, c3 = M, 0, 0

        vector<vector<int>> Roman{
            {'I', 'V', 'X'},
            {'X', 'L', 'C'},
            {'C', 'D', 'M'},
            {'M', '0', '0'}  // last two values are dummies
        };

        int place = 0;
        string result;
        while (num) {
            int digit = num % 10;
            char c1 = Roman[place][0];
            char c2 = Roman[place][1];
            char c3 = Roman[place][2];
            if (digit < 4) {
                result.append(digit, c1);
            } else if (digit == 4) {
                result.append(1, c2);
                result.append(1, c1);
            } else if (digit < 9) {
                result.append(digit - 5, c1);
                result.append(1, c2);
            } else if (digit == 9) {
                result.append(1, c3);
                result.append(1, c1);
            }
            place++;
            num /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
```

```cpp
class Solution {
   public:
    string intToRoman(int num) {
        vector<vector<string>> Roman{
            //    0   1    2     3      4     5    6     7      8       9
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"},
        };

        int thou_digit = num / 1000;
        int hund_digit = (num / 100) % 10;
        int tens_digit = (num / 10) % 10;
        int ones_digit = num % 10;

        return Roman[3][thou_digit] + Roman[2][hund_digit] +
               Roman[1][tens_digit] + Roman[0][ones_digit];
    }
};
```

```cpp
class Solution {
   public:
    string intToRoman(int num) {
        string ones_str[] = {"",  "I",  "II",  "III",  "IV",
                            "V", "VI", "VII", "VIII", "IX"};
        string tens_str[] = {"",  "X",  "XX",  "XXX",  "XL",
                            "L", "LX", "LXX", "LXXX", "XC"};
        string hund_str[] = {"",  "C",  "CC",  "CCC",  "CD",
                            "D", "DC", "DCC", "DCCC", "CM"};
        string thou_str[] = {"", "M", "MM", "MMM"};

        int thou_digit = num / 1000;
        int hund_digit = (num / 100) % 10;
        int tens_digit = (num / 10) % 10;
        int ones_digit = num % 10;

        return thou_str[thou_digit] + hund_str[hund_digit] +
               tens_str[tens_digit] + ones_str[ones_digit];
    }
};
```