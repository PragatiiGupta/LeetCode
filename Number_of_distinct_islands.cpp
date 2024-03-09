/*
Number of Distinct Islands
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Intuition:
The intuition behind the code is to find and count distinct islands in a given grid. An island is considered distinct if its shape and relative positions of cells are unique, regardless of its absolute position in the grid.

Approach:
DFS Traversal: The depth-first search (DFS) algorithm is used to traverse each island in the grid. Starting from a cell of a new island, DFS explores its adjacent cells recursively until the entire island is traversed. During traversal, we track the relative positions of cells with respect to the starting cell.
Visited Array: We maintain a visited array to mark cells that have been visited during island traversal, ensuring that we don't revisit cells from the same island.
Set for Distinct Islands: We use a set data structure to store the relative positions of cells for each distinct island. Sets automatically handle duplicates, so each unique island will be stored only once.
Counting Distinct Islands: After traversing the entire grid and identifying all distinct islands, we count the number of unique sets in the set data structure to determine the total count of distinct islands.
Time Complexity:
DFS Traversal: The worst-case time complexity for DFS traversal is O(n * m), where n is the number of rows and m is the number of columns in the grid. This is because we might have to traverse the entire grid to identify all islands.
Set Insertion: Inserting each island into the set takes O(log k) time, where k is the size of the set. Since there can be at most O(n * m) distinct islands (worst case), the total time complexity for set insertion is O((n * m) * log(n * m)).
Total Time Complexity: O(n * m * log(n * m))
Space Complexity:
Visited Array: The visited array requires O(n * m) space to store the visited status of each cell in the grid.
Set: The set data structure requires additional space to store the distinct islands. In the worst case, where each cell forms a distinct island, the space complexity of the set would be O(n * m).
DFS Recursion: The depth of the recursion stack for DFS traversal can go up to O(n * m), depending on the size of the grid.
Total Space Complexity: O(n * m)

Code
*/
    void dfs(int r, int c,vector<vector<int>>& grid,vector<vector<int>>& vis, vector<pair<int,int>>&vec, int r0, int c0)
        {
            vis[r][c] = 1;
            vec.push_back({r-r0,c-c0});
            int n = grid.size();
            int m = grid[0].size();
            int row[] = {-1,0,1,0};
            int col[] = {0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow= r+row[i];
                int ncol = c+col[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&grid[nrow][ncol]==1)
                dfs(nrow,ncol,grid,vis,vec,r0,c0);
            }
        }
class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0)); 
        set<vector<pair<int,int>>>set;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    set.insert(vec);
                }
            }
        return set.size();
                
    }
};
