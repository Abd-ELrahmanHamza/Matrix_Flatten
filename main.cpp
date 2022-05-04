#include <iostream>
#include <vector>

using namespace std;

void testRandomCases(int i, int j, int k, int m, int p, vector<vector<vector<int>>> matrix3D, vector<int> vector1D) {
    printf("\nmatrix3D[%d][%d][%d]: %d\n", i, j, k, matrix3D[i][j][k]);
    printf("vector1D[%d]: %d\n", i * m * p + j * p + k, vector1D[i * m * p + j * p + k]);
}

int main() {
    /**************************************************/
    /**** SOLUTION: y = i * m * p + j * p + k O(1) ****/
    /**************************************************/
    cout << "SOLUTION: y = i * m * p + j * p + k  O(1)\n\n";
    int n = 2, m = 4, p = 3;
    vector<vector<vector<int>>> matrix3D(n, vector<vector<int>>(m, vector<int>(p)));
    vector<int> vector1D(n * m * p);

    // Test the solution

    // Fill the matrix with dummy values
    // The values is different to make sure that the algorithm works correctly
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                matrix3D[i][j][k] = (i * m * p + j * p + k) * 10;
            }
        }
    }

    cout << "matrix3D: " << endl;
    // Print the 3D Matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                cout << matrix3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Copy each cell in the 3D Matrix to its corresponding position in the 1d vector using the formula
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                int y = i * m * p + j * p + k;
                vector1D[y] = matrix3D[i][j][k];
            }
        }
    }

    cout << "vector1D: " << endl;
    // Print the 1D vector using the formula
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                int y = i * m * p + j * p + k;
                cout << vector1D[y] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Test random cases
    testRandomCases(1, 2, 2, m, p, matrix3D, vector1D);
    testRandomCases(0, 0, 0, m, p, matrix3D, vector1D);
    testRandomCases(1, 3, 2, m, p, matrix3D, vector1D);
    return 0;
}
