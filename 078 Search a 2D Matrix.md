# Search a 2D matrix (Problem 74)

Binary search along the vectors first,  
then binary search within the vector
```cpp
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int begin = 0;
        int end = matrix.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (target < matrix[mid].front()) {
                end = mid - 1;
            } else if (target > matrix[mid].back()) {
                begin = mid + 1;
            } else {
                return binary_search(matrix[mid].begin(), matrix[mid].end(),
                                     target);
            }
        }
        return false;
    }
};
```
