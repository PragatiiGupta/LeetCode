/*
Find the number of islands
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Intuition:
An island is a connected component of '1's in the grid, where each '1' is adjacent to another '1' horizontally, vertically, or diagonally. To find the number of islands, we need to traverse the grid and identify each connected component of '1's.

Approach:
DFS Traversal: We can use depth-first search (DFS) to traverse the grid and identify connected components. Starting from each '1' cell that hasn't been visited, we explore all its neighboring cells (horizontally, vertically, and diagonally) to form an island.
Visited Array: We maintain a visited array to mark cells that have been visited during island traversal, ensuring that we don't revisit cells from the same island.
Counting Islands: We iterate through each cell in the grid. Whenever we encounter an unvisited '1', we start a new DFS traversal to explore and mark all cells connected to it. After completing the traversal, we increment the count of islands by 1.

Time and Space Complexity: The time complexity of DFS traversal is O(n * m), where n is the number of rows and m is the number of columns in the grid. The space complexity is also O(n * m) due to the visited array.
Time Complexity:
The DFS traversal visits each cell in the grid once, leading to a time complexity of O(n * m), where n is the number of rows and m is the number of columns in the grid.

Code
*/

void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis)
    {
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int row[] = {-1, -1, -1, 0, 0, 1, 1, 1}; // Horizontal and diagonal neighbors
        int col[] = {-1, 0, 1, -1, 1, -1, 0, 1}; // Vertical and diagonal neighbors
        for (int i = 0; i < 8; i++)
        {
            int nrow = r+row[i];
            int ncol = c+col[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&grid[nrow][ncol]=='1')
            dfs(nrow,ncol,grid,vis);
        }
    }
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 0) return 0; 
        if (m == 0) return 0; 
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!vis[i][j] && grid[i][j] == '1')
                {
                    dfs(i,j,grid,vis);
                    count++;
                }
        return count;
    }
};
