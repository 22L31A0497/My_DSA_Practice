#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size(); // Fix column size

        vector<int> row(m, 0); // Store which rows should be zeroed
        vector<int> col(n, 0); // Store which columns should be zeroed

        // Step 1: Mark rows and columns that should be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Step 2: Set matrix elements to zero based on row and column markers
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] ==1|| col[j]==1) { // Fix condition
                    matrix[i][j] = 0;
                }
            }
        }
    }
};