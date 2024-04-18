/**
Number Of Enclaves
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Intuition:
The problem asks us to find the number of land cells in the grid for which we cannot walk off the boundary of the grid in any number of moves. This implies that we need to identify the land cells that are connected to the boundary of the grid. We can achieve this by performing a depth-first search (DFS) starting from each land cell that is on the boundary.

Approach:
Define a DFS function that traverses adjacent land cells recursively and marks them as visited.
Iterate through the boundary land cells (top, bottom, left, and right sides of the grid) and perform DFS from each of them.
After DFS traversal, count the number of unvisited land cells. These are the land cells that are not connected to the boundary and thus cannot be walked off the boundary.

Time Complexity:
Let nn be the number of rows and mm be the number of columns in the grid.
Performing DFS from each boundary cell takes O(4nm)O(4nm) time, where 4nm4nm is the total number of boundary cells.
Counting unvisited land cells takes O(nm)O(nm) time.
Overall, the time complexity is O(nm)O(nm).
Space Complexity:

We use an additional O(nm)O(nm) space for the visited array.
Therefore, the space complexity is O(nm)O(nm).
Code
*/
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();

    // Base cases for out of bounds or sea cell
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || visited[i][j]) {
        return;
    }

    // Mark current cell as visited
    visited[i][j] = true;

    // Explore neighboring land cells
    dfs(grid, visited, i - 1, j); 
    dfs(grid, visited, i + 1, j); 
    dfs(grid, visited, i, j - 1); 
    dfs(grid, visited, i, j + 1); 
}
class Solution {
public:
   int numberOfEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // Initialize visited array
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Traverse top and bottom rows
    for (int j = 0; j < m; ++j) {
        dfs(grid, visited, 0, j);           
        dfs(grid, visited, n - 1, j);     
    }

    // Traverse left and right columns (excluding first and last row)
    for (int i = 1; i < n - 1; ++i) {
        dfs(grid, visited, i, 0);          
        dfs(grid, visited, i, m - 1);      
    }

    // Count unvisited land cells
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                ++count;
            }
        }
    }
    return count;
}
};
