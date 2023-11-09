# Valid Sudoku (Problem 36)

```cpp
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unsigned row_marks[9] {0};
        unsigned col_marks[9] {0};
        unsigned box_marks[3][3] {0};
        unsigned i, j, mark;
        for(i=0; i<9; i++) {
            for(j=0; j<9; j++) {
                if(board[i][j] != '.') {
                    mark = 1 << (board[i][j] - '1');
                    if(row_marks[i] & mark 
                        || col_marks[j] & mark 
                        || box_marks[i/3][j/3] & mark) 
                        return false;
                    row_marks[i] |= mark;
                    col_marks[j] |= mark;
                    box_marks[i/3][j/3] |= mark;
                }                
            }
        }


        return true;
    }
};
```