# Stringoholics InterviewBit

Working solution but inefficient time. get_time function is inefficient.

```cpp

#include <numeric>
const long long mod = 1e9 + 7;
static const bool debug = false;

void print_map(unordered_map<int, int> mp) {
    for (auto [a, b] : mp) cout << a << "^" << b << " ";
    cout << endl;
}

void rotate(string &s, long long k) {
    if (s.empty()) return;
    k = k % s.size();
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    reverse(s.begin(), s.end());
}

unordered_map<int, int> get_primes(int num) {  // check with int
    unordered_map<int, int> result;
    while (num % 2 == 0) {
        result[2]++;
        num /= 2;
    }
    for (int i = 3; i * i <= num; i++) {
        while (num % i == 0) {
            result[i]++;
            num /= i;
        }
    }
    if (num > 2) result[num]++;
    if (debug) print_map(result);
    return result;
}

long long get_time(const string &s) {
    string s1 = s;
    long long t = 0;
    do {
        t++;
        rotate(s1, t);
    } while (s1 != s);
    return t;
}

int Solution::solve(vector<string> &A) {
    unordered_set<long long> times;
    for (string &s : A) {
        times.insert(get_time(s));
    }
    if (debug) {
        for (auto time : times) cout << time << " ";
        cout << endl;
    }
    unordered_map<int, int> powerOfPrimes;
    for (auto time : times) {
        unordered_map<int, int> powerOfPrimes1 = get_primes(time);
        for (auto [prime, power] : powerOfPrimes1) {
            powerOfPrimes[prime] = max(powerOfPrimes[prime], power);
        }
    }
    if (debug) print_map(powerOfPrimes);
    long long result = 1;
    for (auto [prime, power] : powerOfPrimes) {
        for (int i = 0; i < power; i++) {
            result *= prime % mod;
            result %= mod;
        }
    }
    return result;
}
```

1. For the Nth Operation, the string is rotated by (N*(N+1))/2 When (N*(N+1))/2
   % S.len == 0 we know we will have the original string. This takes O(N) time.
   But we could have a smaller N if the string has recurrent subsequences.
2. Use KMP algorithm to check for recurrent substrings in O(S.len) time
