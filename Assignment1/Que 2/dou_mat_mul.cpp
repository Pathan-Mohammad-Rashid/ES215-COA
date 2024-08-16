#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void multiplyMatrixDouble(int N) {
    vector<vector<double>> A(N, vector<double>(N, 1.0));
    vector<vector<double>> B(N, vector<double>(N, 2.0));
    vector<vector<double>> C(N, vector<double>(N, 0.0));

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
        multiplyMatrixDouble(N);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> elapsed = end - start;
        cout << "Time for double matrix: " << elapsed.count() << " seconds" << endl;
    }
    return 0;
}
