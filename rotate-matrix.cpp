#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int depth = (n + 1) / 2;

    for (int d = 0; d < depth; d++) {
        for (int i = d; i < n - d - 1; i++) {
            int tmp = matrix[d][i];

            matrix[d][i] = matrix[n - i - 1][d];
            matrix[n - i - 1][d] = matrix[n - d - 1][n - i - 1];
            matrix[n - d - 1][n - i - 1] = matrix[i][n - d - 1];
            matrix[i][n - d - 1] = tmp;
        }
    }
}
void test() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // [[7,4,1],[8,5,2],[9,6,3]]
    rotate(matrix);

    for (auto r : matrix) {
        cout << "[";
        for (int j = 0; j < r.size(); j++) {
            cout << r[j] << (j < r.size() - 1 ? ", " : "");
        }
        cout << "], ";
    }

    cout << endl;
}