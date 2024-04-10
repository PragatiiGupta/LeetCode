/**
Find whether path exist
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.

Intuition:
The problem requires determining whether there exists a path from the source cell to the destination cell in a grid with certain cell values representing different meanings (1 for source, 2 for destination, 3 for blank cell, and 0 for wall). We need to perform a depth-first search (DFS) traversal starting from the source cell and exploring neighboring cells until we reach the destination cell or exhaust all possible paths.

Approach:
Initialization: Initialize a boolean grid to mark visited cells during DFS traversal.
DFS Traversal: Perform DFS traversal starting from the source cell. During traversal, explore neighboring cells in all four directions (up, down, left, right) that are not walls (value 0) and not already visited.
Base Cases:
If the current cell is the destination cell, return true.
If no path is found after traversing all reachable cells, return false.
Recursion: Recursively call the DFS function for blank cells (value 3) or the destination cell encountered during traversal.
Output: Return true if a path is found, false otherwise.

Time Complexity:
The DFS traversal visits each cell in the grid at most once.
In the worst case, the DFS traversal explores all reachable cells from the source until it reaches the destination or exhausts all possible paths.
Hence, the time complexity is O(N^2), where N is the size of the grid.
Space Complexity:
The additional space complexity is mainly due to the boolean visited grid to track visited cells during DFS traversal, which requires O(N^2) space.
Apart from that, the space complexity of the recursive function calls is O(N) due to the call stack.
Thus, the overall space complexity is O(N^2 + N), which simplifies to O(N^2).
Code
*/

void util(vector<vector<int>>& grid, pair<int,int> s, pair<int,int> d, vector<vector<bool>>& visited, int &flag)
{
    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};
    visited[s.first][s.second] = true;
    if (s == d) {
        flag = 1;
        return;
    }

    for(int i = 0; i < 4; i++)
    {
       int nrow = s.first + row[i];
       int ncol = s.second + col[i];
       if(nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] != 0 && !visited[nrow][ncol])
       {
           if (grid[nrow][ncol] == 3 || grid[nrow][ncol] == 2)
                util(grid, {nrow, ncol}, d, visited, flag);
       }
    }
}

class Solution
{
public:
    bool is_Possible(vector<vector<int>>& grid)
    {
        int flag = 0; 
        pair<int, int> s, d;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    s = {i, j};
                if(grid[i][j] == 2)
                    d = {i, j};
            }
        }
        util(grid, s, d, visited, flag);
        return flag == 1;
    }
};
