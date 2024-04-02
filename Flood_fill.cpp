/*
Flood fill Algorithm
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Intuition:
The flood fill algorithm is used to fill a connected region of pixels with a specified color. Starting from a given pixel, we explore its neighboring pixels recursively and change their color if they have the same color as the starting pixel. We continue this process until we have explored all connected pixels with the same color.

Approach:
DFS (Depth-First Search):
We start DFS from the given starting pixel (sr, sc).
For each pixel, we check if it's within the bounds of the image, if it's already visited, or if its color is different from the starting color. If any of these conditions are true, we skip the pixel.
Otherwise, we mark the pixel as visited and change its color to the new color.
We recursively call DFS on its neighboring pixels (up, down, left, right).
Updating Image:

After performing DFS, we update the original image based on the visited array. If a pixel is visited, we update its color in the original image.
Time Complexity:
Let n be the number of rows and m be the number of columns in the image.
Each pixel is visited at most once during DFS.
The time complexity of DFS is O(n * m) since we might have to explore every pixel in the worst case.

Space Complexity:
We use additional space for the visited array, which has the same dimensions as the image (n rows and m columns).
The space complexity is O(n * m) to store the visited array.
Additionally, the recursive calls in DFS consume stack space. In the worst case, the depth of the recursion can be O(n * m) if all pixels have the same color and form a single connected component.
Overall, the space complexity is O(n * m).

Code
*/

void dfs(int sr,int sc,vector<vector<int>>& image,vector<vector<int>>& vis, int color, int newColor)
    {
        
        int n = image.size();
        int m = image[0].size();
        if (sr < 0 || sr >= n || sc < 0 || sc >= m || vis[sr][sc] != -1 || image[sr][sc] != color) {
        return;
        }
        vis[sr][sc] = newColor;

        int row[] = {-1,0,1,0};
        int col[] = {0,1,0,-1};
        for(int i=0;i<4;i++)
        {
            int nrow = sr+row[i];
            int ncol = sc+col[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==-1&&image[nrow][ncol]==color)
            dfs(nrow,ncol,image,vis,color,newColor);
        }   
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int color = image[sr][sc];
        dfs(sr,sc,image,vis,color,newColor);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                    if(vis[i][j] != -1)
                        image[i][j] = vis[i][j];
            }
        return image;
    }
