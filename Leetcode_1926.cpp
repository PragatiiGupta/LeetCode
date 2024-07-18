/*
1926. Nearest exit from entrance in a maze.
You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.
In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.
Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

Intuition
The code performs a breadth-first search (BFS) to find the nearest exit from a given entrance in a maze. The BFS algorithm is used because it explores all nodes at the present depth level before moving on to nodes at the next depth level, ensuring that the first exit found is the nearest one.

Approach
Initialize Variables:
n and m store the dimensions of the maze.
A queue q is initialized with the entrance coordinates.
A 2D vector vis is used to keep track of visited cells, initialized to 0 (not visited).
dir vector is used for movement in four directions (up, down, left, right).
Mark Entrance as Visited:
The entrance cell is marked as visited in the vis vector.
BFS Traversal:
While the queue is not empty:
Increment the steps counter.
For each cell in the current level:
Dequeue the cell coordinates.
For each of the four possible directions:
Calculate the new row and column indices.
Check if the new indices are within bounds, the cell is an open path ('.'), and it has not been visited.
If the new cell is on the boundary of the maze, return the current step count as the number of steps to the nearest exit.
Otherwise, mark the cell as visited and enqueue it.
No Exit Found:
If the queue is empty and no exit is found, return -1.

Time Complexity
The time complexity of the BFS algorithm is O(N \times M)O(N×M), where NN is the number of rows and MM is the number of columns in the maze. This is because each cell is processed at most once, and the algorithm explores all possible paths in the maze.
Space Complexity
The space complexity is also O(N \times M)O(N×M) because of the vis vector and the queue q. The vis vector requires O(N \times M)O(N×M) space to store the visited status of each cell, and in the worst case, the queue can hold up to O(N \times M)O(N×M) cells.

Code
*/
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            int n = maze.size();
    int m = maze[0].size();
    queue<pair<int,int>> q;
    q.push({entrance[0], entrance[1]});
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vis[entrance[0]][entrance[1]] = 1; 
    
    vector<int> dir = {-1, 0, 1, 0, -1}; 
    
    int steps = 0;
    
    while (!q.empty()) {
        int size = q.size();
        steps++;
        for (int i = 0; i < size; ++i) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int j = 0; j < 4; ++j) {
                int nr = r + dir[j];
                int nc = c + dir[j + 1];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == '.' && vis[nr][nc] == 0) {
                    if (nr == 0 || nr == n - 1 || nc == 0 || nc == m - 1) {
                        return steps; 
                    }
                    q.push({nr, nc});
                    vis[nr][nc] = 1; 
                }
            }
        }
    }
    
    return -1; 
    }
