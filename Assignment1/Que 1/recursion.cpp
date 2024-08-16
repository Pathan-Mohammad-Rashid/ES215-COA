#include <iostream>
#include <time.h>
using namespace std;

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int n = 50;
    cout << "First " << n << " Fibonacci numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "\nTime taken by recursion: " << time_taken << " seconds\n";

    return 0;
}