#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

vector<long long> memo(51, -1);

long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    vector<long long> fibNumbers;

    for (int i = 0; i < 50; i++) {
        fibNumbers.push_back(fibonacci(i));
    }

    cout << "The first 50 Fibonacci numbers are:" << endl;
    for (int i = 0; i < 50; i++) {
        cout << fibNumbers[i] << " ";
    }
    cout << endl;

    clock_gettime(CLOCK_MONOTONIC, &end);

    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    cout << "\nTime taken by recursion with memoization: " << time_taken << " seconds\n";
    
    return 0;
}