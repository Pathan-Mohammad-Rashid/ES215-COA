#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void multiplyMatrixInt(int N) {
    vector<vector<int>> A(N, vector<int>(N, 1));
    vector<vector<int>> B(N, vector<int>(N, 2));
    vector<vector<int>> C(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int sizes[] = {64, 128, 256, 512, 1024};
    for (int N : sizes) {
        cout << "Matrix Size: " << N << "x" << N << endl;

        auto start = chrono::high_resolution_clock::now();
        multiplyMatrixInt(N);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;
        cout << "Time for int matrix: " << elapsed.count() << " seconds" << endl;
    }
    return 0;
}
