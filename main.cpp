#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, p;
    n = 2, m = 4, p = 3;
    vector<vector<vector<int>>> Matrix3D(n, vector<vector<int>>(m, vector<int>(p)));
    vector<int> vector1D(n * m * p);
    int dummy = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                Matrix3D[i][j][k] = dummy++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                cout << Matrix3D[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                int y = i * m * p + j * p + k;
                vector1D[y] = Matrix3D[i][j][k];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                int y = i * m * p + j * p + k;
                cout << vector1D[y]<<" ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
