# Median of two sorted arrays (Problem 4)

O((m+n)) method. get the smallest element from the arrays, (m+n)/2 times and
then remember the last two numbers encountered. Return the median on the basis
of odd or even total size.

```cpp
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int M = nums1.size();
        int N = nums2.size();
        int mid = (M + N + 2) / 2;
        int count = 0;
        double m1 = -1, m2 = -1;
        int i = 0, j = 0;
        while (count < mid) {
            m2 = m1;
            if (i < M && j < N)
                m1 = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
            else if (i < M)
                m1 = nums1[i++];
            else
                m1 = nums2[j++];
            count++;
        }
        return (M + N) % 2 ? m1 : (m1 + m2) / 2;
    }
};
```

O(log(m+n)) is possible
[refer](https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2471/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation/?envType=study-plan-v2&envId=top-interview-150)

`//refer below`, this is basically binary search. boils down to the correct cut
we are making one two arrays to get even cut to the left and to the right in
total number of elements.

```cpp
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = N2 * 2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;
            int mid1 = N1 + N2 - mid2;

            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1) / 2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2) / 2];

            if (L1 > R2)
                lo = mid2 + 1;
            else if (L2 > R1)
                hi = mid2 - 1;
            else
                return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};
```
