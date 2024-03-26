/**
36. Valid Sudoku

Intuition
The problem asks to determine if a 9x9 Sudoku board is valid. To solve this problem, we can use sets to keep track of the numbers in each row, column, and 3x3 subgrid. We iterate through the board and add each number to the corresponding sets. If we encounter a number that already exists in the set for its row, column, or subgrid, then the Sudoku board is not valid.

Approach
Initialize three vectors of sets: rows for tracking numbers in each row, cols for tracking numbers in each column, and blocks for tracking numbers in each 3x3 subgrid.
Iterate through each cell in the Sudoku board.
For each cell, if the cell contains a number (not a '.'), check if that number already exists in the corresponding row, column, or 3x3 subgrid.
If the number already exists, return false, indicating that the Sudoku board is not valid.
If the number doesn't exist, add it to the corresponding sets.
After iterating through the entire board, return true, indicating that the Sudoku board is valid.

Complexity
Time complexity: O(1)O(1) since the size of the Sudoku board is fixed (9x9).
Space complexity: O(1)O(1) since the size of the sets is fixed.
Code
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), cols(9), blocks(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') continue;
                
                int curr = board[i][j] - '0';
                if (rows[i].count(curr) || cols[j].count(curr) || blocks[(i/3)*3+j/3].count(curr)) 
                    return false;
                
                rows[i].insert(curr);
                cols[j].insert(curr);
                blocks[(i/3)*3+j/3].insert(curr);
            }
        }
        
        return true;
    }
};
