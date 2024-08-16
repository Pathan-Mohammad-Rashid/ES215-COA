#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<int> fibonacci(int n) {
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);

    for (int i = 2; i < n; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }

    return fib;
}

int main() {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    int n = 50;
    vector<int> fibNumbers = fibonacci(n);

    cout << "First " << n << " Fibonacci numbers:" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibNumbers[i] << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "\nTime taken by loop with memoization: " << time_taken << " seconds\n";
    
    return 0;
}