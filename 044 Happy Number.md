# Happy Number (Problem 202)

Simulate till you find a loop or find a halt

```cpp
class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> happy_set;
        while (1) {
            int n1 = happyness(n);
            // cout << n1 << endl;
            if (n1 == 1) return true;
            if (happy_set.find(n1) == happy_set.end()) {
                happy_set.insert(n1);
            } else {
                return false;
            }
            n = n1;
        }
        return false;
    }
    int happyness(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};
```

Same solution cleaner code

```cpp
class Solution {
private:
    unordered_set<int> ht = {1, 4, 16, 20, 37, 42, 58, 89, 145};
    int get_N(int n) {
        int result = 0;
        while(n) {
            int n1 = n%10;
            result += n1*n1;
            n /= 10;
        }
        return result;
    }
public:
    bool isHappy(int n) {
        while(ht.find(n)==ht.end())
            n = get_N(n);
        return n==1;

    }
};
```

Two Pointer Approach (not faster but interesting)

```cpp
class Solution {
   public:
    int cal(int i) {
        int result = 0;
        while (i) {
            result += (i % 10) * (i % 10);
            i /= 10;
        }
        return result;
    }
    bool isHappy(int n) {
        int fast = n, slow = n;
        do {
            slow = cal(slow);
            fast = cal(fast);
            fast = cal(fast);
        } while (fast != slow && fast != 1);
        return fast == 1;
    }
};
```

As clean as it gets

```cpp
class Solution {
   public:
    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            int sum = 0;
            while (n) {
                int d1 = n % 10;
                sum += d1 * d1;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
```
