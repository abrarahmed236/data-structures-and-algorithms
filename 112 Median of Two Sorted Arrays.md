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

