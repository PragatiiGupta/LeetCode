/*
Rotten Oranges
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.

Intuition:
The intuition behind this code is to simulate the process of rotting oranges using a breadth-first search (BFS) approach. The algorithm traverses the grid and performs BFS from each rotten orange to its neighboring fresh oranges, updating their state and tracking the time taken for oranges to rot completely.

Approach:
Initialization: Initialize a queue to store the positions of rotten oranges along with the time taken for them to rot. Also, initialize a 2D visited array to keep track of the state of each cell in the grid.
BFS Traversal: While there are still rotten oranges in the queue, pop a rotten orange and explore its neighboring cells. If a neighboring cell contains a fresh orange, mark it as rotten, update its state in the visited array, and enqueue it with the incremented time.
Time Calculation: Track the maximum time taken during the BFS traversal, which represents the minimum time required for all oranges to rot.
Validation: After BFS traversal, ensure that all fresh oranges have been visited. If not, it means some oranges are unreachable or can't be rotten, returning -1 in such cases.
Return: Return the maximum time taken for oranges to rot completely.

Time Complexity:
Grid Traversal: In the worst case, we may traverse each cell of the grid once, resulting in O(n * m) time complexity, where n is the number of rows and m is the number of columns.
BFS Traversal: Each cell is enqueued and dequeued at most once during BFS traversal. Therefore, the overall time complexity of BFS is also O(n * m).
Total Time Complexity: O(n * m)

Space Complexity:
Queue: The queue may contain at most all the rotten oranges, resulting in O(n * m) space complexity.
Visited Array: The visited array has the same size as the grid, resulting in O(n * m) space complexity.
Other Variables: The other variables used in the algorithm have constant space requirements.
Total Space Complexity: O(n * m)
Overall:
The given code effectively finds the minimum time required to rot all oranges in the grid with a time complexity of O(n * m) and a space complexity of O(n * m).

Code
*/

public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      queue < pair < pair < int, int > , int >> q;
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 

            vis[i][j] = 2;
          }
          // if not rotten
          else {
            vis[i][j] = 0;
          }
          if (grid[i][j] == 1) cntFresh++;
        }
      }

      int tm = 0;
      int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, 1, 0, -1}; 
      int cnt = 0;
      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for (int i = 0; i < 4; i++) {
          int nrow = r + drow[i];
          int ncol = c + dcol[i];
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
             q.push({{nrow, ncol}, t + 1}); 
            vis[nrow][ncol] = 2;
            cnt++;
          }
        }
      }

      if (cnt != cntFresh) return -1;

      return tm;
    } 
