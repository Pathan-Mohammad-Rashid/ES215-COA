#include <iostream>
#include <time.h>

using namespace std;

int main() {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int n = 50;
    long long int fib[n];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    for (int i = 0; i < n; i++) {
        cout << fib[i] << " ";
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "\nTime taken by loop: " << time_taken << " seconds\n";
    
    return 0;
}