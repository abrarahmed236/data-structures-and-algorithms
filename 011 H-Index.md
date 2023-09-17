# [H-Index (Problem 274)](https://leetcode.com/problems/h-index/)

## Description

Given an array of integers `citations` where `citations[i]` is the number of
citations a researcher received for their `i-th` paper, return the researcher's
h-index.

The h-index is defined as the maximum value of `h` such that the given
researcher has published at least `h` papers that have each been cited at least
`h` times.

### Example 1

> **Input**: citations = [3,0,6,1,5]  
> **Output**: 3  
> **Explanation**: [3,0,6,1,5] means the researcher has 5 papers in total and
> each of them had received 3, 0, 6, 1, 5 citations respectively. Since the
> researcher has 3 papers with at least 3 citations each (3, 5, 6) and the
> remaining two with no more than 3 citations each (0, 1), their h-index is 3.

### Example 2

> **Input**: citations = [1,3,1]  
> **Output**: 1

### Constraints

- `n == citations.length`
- `1 <= n <= 5000`
- `0 <= citations[i] <= 1000`

## Approach 1 - Counting

### Approach

A simple approach would be to count how many papers have a citation count
greater than a certain number. viz. we scan over the array once to see the
number of papers which have `>= 1` citation if that number is >=1 then h-index
of one is possible. then we check how many papers have `>= 2` citations and if
the number of papers is `>= 2` then `h-index == 2` is also possible. we stop
this when we check for number of citations `>= x` and the number of papers is
not `>= x`, then we know `h-index == n` is not possible. then stop the whole
process and report the previously stored `h-index`.

### Code

```cpp
class Solution {
   public:
    int hIndex(vector<int>& citations) {
        int h_index = 0;
        int h_candidate = 1;
        while (h_candidate < citations.size()) {
            int count = 0;
            for (int i = 0; i < citations.size(); i++) {
                if (citations[i] < h_candidate) {
                    break;
                }
                count++;
            }
            if (count >= h_candidate)
                h_index = h_candidate;
            else
                break;
            h_candidate++;
        }
        return h_index;
    }
};
```

## Approach 2 - Sorting

### Approach

Another approach would be to sort the citations in reverse order and count the
number of papers with citations greater than the count of papers we have looked
at. That gives us the h-index.

### Code

```cpp
class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] < i + 1) return i;
        }
        return citations.size();
    }
};
```
