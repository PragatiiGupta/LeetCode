/**
48. Rotate Image

Intuition
The problem requires rotating the given square matrix by 90 degrees clockwise. To solve this, we can perform a layer-by-layer rotation, starting from the outer layer and moving towards the inner layers.

Approach
Iterate through each layer of the matrix, starting from the outer layer and moving towards the inner layers.
For each layer, iterate through each element in that layer.
Perform a four-way swap of elements in the current layer:
Store the top element in a temporary variable.
Move the left element to the top.
Move the bottom element to the left.
Move the right element to the bottom.
Move the temporary variable to the right.
Repeat this process for all layers, until the entire matrix is rotated.

Complexity
Time complexity: O(n^2), where n is the size of the matrix.
Space complexity: O(1), since we are rotating the matrix in-place.

Code
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
   
        for (int layer = 0; layer < n/2; layer++) {
            for (int i = layer; i < n - layer - 1; i++) {
                int temp = matrix[layer][i];
                matrix[layer][i] = matrix[n - i - 1][layer];
                matrix[n - i - 1][layer] = matrix[n - 1 - layer][n - i - 1];
                matrix[n - 1 - layer][n - i - 1] = matrix[i][n - 1 - layer];
                matrix[i][n - 1 - layer] = temp;
            }
        }
    }
};
