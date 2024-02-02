# [Stringoholics InterviewBit](https://www.interviewbit.com/problems/stringoholics/)

## Brute Force Approach

Working solution but inefficient time. get_time function is inefficient.

### Code for brute force approach

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

## KMP based Approach

If we take a given string `abbaa`, and append it to itself `abbaaabbaa`, any
occurences of `abbaa` in the doubled string correspond to rotations of `abbaa`
that are the same as the original.

For example, let A = `abbabbabb`, let's double it up B = `abbabbabbabbabbabb`,
now if we look for all occurences of A in B we get the following

```txt
index:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17
char:    a  b  b  a  b  b  a  b  b  a  b  b  a  b  b  a  b  b
@ 0:     a  b  b  a  b  b  a  b  b
@ 3:              a  b  b  a  b  b  a  b  b
@ 6:                       a  b  b  a  b  b  a  b  b
@ 9:                                a  b  b  a  b  b  a  b  b
```

We find matches at indices: `0, 3, 6, 9`, we can also see that rotating `A` by
`0, 3, 6, 9` gives us the original string `A` again. We will be using this
property later in the solution but before that we need to notice that if we look
for this list of matches `matches = {0, 3, 6, 9}` naively like above then we
still take `O(N^2)` time. We also know that this time can be improved to
`O(N + 2N) ~= O(N)` by using the KMP string matching algorithm.

So, for the first step, that is what we will do, we will get a list of matches
of `A` in the doubled up string `B = A + A`.

> Note: we don't need to consider the last match, since it corresponds to
> rotating the string by it's own length, and we know trivially that if we
> rotate by `n` times, it is the same as rotating by `n % A.size()` times. To
> ignore the last match we remove the last element of the doubled string
> `B.pop_back()`.

Now for the next step.

At time `t == 1`, we do `1` rotation.  
At time `t == 2`, we do `2` additional rotations, so `1 + 2 = 3` total rotations
from initial state.  
At time `t == 3`, we do `3` additional rotations, so `1 + 2 + 3 = 6` total
rotations from initial state.  
At time `t == 4`, we do `4` additional rotations, so `1 + 2 + 3 + 4 = 10` total
rotations from initial state. .  
...  
At time `t == n`, we do `n` additional matches, so `n(n + 1) / 2` total
rotations from initial state.

To get the earliest time `t` at which we get the original string again we find
the smallest `t` for which `(t(t + 1) / 2) % A.size` occurs in our list of
matches. Worst case complexity for this is `O(N)`.

> Note: `N(N-1)/2 % N == 0` if N is odd, and `2N(2N+1)/2 % N == 0` if N is even,
> these are the worst case senarios for finding the smallest `t` and both take
> `O(N)` time to find.

Now, in our problem we are not given one string by many strings, and we are
asked to find the minimum time at which a maximum number of strings are their
original self.

For this we ignore all empty strings if there are any, and then we get the
minimum time for each string individually as described above say
`t1, t2, t3, t4 ...`. Now we take the LCM of these times to get the result.

### Complexity for KMP based approach

- Say we are given M strings with a maximum size of N for each string then for
  each string we do:
  - `O(N)` to get the `matched_rotations` array
  - `O(N)` time to get the minimum `t` for this string
- `O(M*N)` to get minimum `t` for each string to populate `array<int> minimum_t`
- `O(M)` to find LCM of all t's in `minimum_t`.

### Code for KMP based approach

- [ ] To-Do: Improve Readability

```cpp
#include <bits/stdc++.h>

#include <cstdio>

using namespace std;

class Solution {
   public:
    int solve(vector<string> &A);
};

////////////////////////////// SUBMISSION //////////////////////////////

const long long mod = 1e9 + 7;

vector<int> get_lps(const string &needle) {
    vector<int> lps(needle.size());

    lps[0] = 0;
    int len = 0;
    for (int i = 1; i < needle.size();) {
        if (needle[len] == needle[i]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

unordered_set<int> get_matched_rotations(const string &haystack,
                                         const string &needle) {
    // Get LPS for KMP String Matching Algorithm
    vector<int> lps = get_lps(needle);

    unordered_set<int> matched_rotations;

    int i = 0, j = 0;
    while (i < haystack.size() && j < needle.size()) {
        if (haystack[i] == needle[j]) {
            i++;
            j++;
        }

        if (j == needle.size()) {
            matched_rotations.insert(i - j);
            j = lps[j - 1];
        } else if (i < haystack.size() && haystack[i] != needle[j]) {
            if (j)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return matched_rotations;
}

int get_time(const string &needle) {
    if (needle.size() < 2)
        return 1;

    // Define a haystack with string appended to itself
    string haystack(needle.begin(), needle.end());
    haystack.append(needle.begin(), needle.end() - 1);

    // Find all occurences of needle in haystack
    unordered_set<int> matched_rotations =
        get_matched_rotations(haystack, needle);

    long long rotations = 0;

    for (long long time = 1;; time++) {
        rotations += time;
        long long rotations_modulo = rotations % needle.size();
        if (matched_rotations.find(rotations_modulo) != matched_rotations.end())
            return time;
    }
    assert(false && "We should not have found ourselves here.");
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
    if (num > 2)
        result[num]++;
    return result;
}

int get_lcm(const unordered_set<long long> &times) {
    unordered_map<int, int> powerOfPrimes;
    for (auto time : times) {
        unordered_map<int, int> powerOfPrimes1 = get_primes(time);
        for (auto [prime, power] : powerOfPrimes1) {
            powerOfPrimes[prime] = max(powerOfPrimes[prime], power);
        }
    }
    long long result = 1;
    for (auto [prime, power] : powerOfPrimes) {
        for (int i = 0; i < power; i++) {
            result = (result * (prime % mod)) % mod;
        }
    }
    return result;
}

int Solution::solve(vector<string> &A) {
    unordered_set<long long> times;
    for (string &s : A) {
        times.insert(get_time(s));
    }
    return get_lcm(times);
}

////////////////////////////// SUBMISSION //////////////////////////////

int main() {
    vector<pair<vector<string>, int>> testcases;
    testcases.push_back({vector<string>{"a", "ababa", "aba"}, 4});
    testcases.push_back({vector<string>{"aaaa", "ababa", "aba"}, 4});

    for (auto &testcase : testcases) {
        vector<string> &A = testcase.first;
        int result = testcase.second;
        Solution sol;
        cout << sol.solve(A) << " : " << result << endl << endl;
    }
}
```
