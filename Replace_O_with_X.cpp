/**
Replace O's with X's
Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

Intuition:
The problem requires identifying 'O' cells that are completely surrounded by 'X' cells and replacing them with 'X'. We can achieve this by performing a depth-first search (DFS) traversal starting from the boundary 'O' cells. During the traversal, we mark all reachable 'O' cells as a temporary marker, and then we replace all remaining 'O' cells with 'X', as they are not completely surrounded by 'X'.

Approach:
Depth-First Search (DFS): We perform a DFS traversal starting from the boundary cells of the matrix. If a cell is 'O', we mark it as 'x' to indicate that it is reachable from the boundary.
Replace 'O's: After DFS traversal, we iterate through the entire matrix. We replace all 'O' cells with 'X', as they are not surrounded by 'X'. We also revert the temporary marker 'x' back to 'O', as those cells are not surrounded by 'X' either.

Time Complexity:
DFS Traversal: Performing DFS traversal requires visiting each cell of the matrix once. The time complexity of DFS traversal is O(N * M), where N is the number of rows and M is the number of columns.
Replacing Cells: After DFS traversal, we iterate through the entire matrix once to replace 'O' cells with 'X' and revert temporary markers back to 'O'. This process also takes O(N * M) time.
Overall Time Complexity: The overall time complexity is O(N * M).
Space Complexity:
Space for Visited Cells: We use a boolean matrix to keep track of visited cells during DFS traversal. The space complexity for this matrix is O(N * M).
Overall Space Complexity: The overall space complexity is O(N * M).
Code
*/

class Solution {
public:
    void dfs(int n, int m, vector<vector<char>>& mat) {
        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        mat[n][m] = 'x'; // Mark the current cell as 'x'
        for (int i = 0; i < 4; i++) {
            int nrow = row[i] + n;
            int ncol = col[i] + m;
            if (nrow >= 0 && nrow < mat.size() && ncol >= 0 && ncol < mat[0].size() && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, mat); // Recursively traverse neighboring cells
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat) {
        // Iterate over the boundary cells and call DFS from 'O' cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && mat[i][j] == 'O') {
                    dfs(i, j, mat);
                }
            }
        }
        // Finally, restore any remaining 'O' cells to their original value and change 'x' to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                } else if (mat[i][j] == 'x') {
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};
