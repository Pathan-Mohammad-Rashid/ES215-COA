#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Part (a): Fibonacci using Recursion
long long fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Part (b): Fibonacci using Loop
long long fibonacci_loop(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Part (c): Fibonacci using Recursion with Memoization
vector<long long> memo(50, -1);

long long fibonacci_memo_recursive(int n) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return n;
    memo[n] = fibonacci_memo_recursive(n - 1) + fibonacci_memo_recursive(n - 2);
    return memo[n];
}

// Part (d): Fibonacci using Loop with Memoization
long long fibonacci_memo_loop(int n) {
    vector<long long> memo(n + 1, 0);
    memo[1] = 1;
    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }
    return memo[n];
}

// Measure time for recursion
void measure_recursive(int n) {
    for (int i = 0; i < n; i++) {
        fibonacci(i);
    }
}

// Measure time for loop
void measure_loop(int n) {
    for (int i = 0; i < n; i++) {
        fibonacci_loop(i);
    }
}

// Measure time for recursion with memoization
void measure_memo_recursive(int n) {
    fill(memo.begin(), memo.end(), -1); // Reset memoization table
    for (int i = 0; i < n; i++) {
        fibonacci_memo_recursive(i);
    }
}

// Measure time for loop with memoization
void measure_memo_loop(int n) {
    for (int i = 0; i < n; i++) {
        fibonacci_memo_loop(i);
    }
}

// Function to measure time
double measure_time(void (*func)(int), int n) {
    timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    func(n);

    clock_gettime(CLOCK_MONOTONIC, &end);
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    int n = 50; // Fibonacci number to calculate

    // Measure time for recursion
    double time_recursive = measure_time(measure_recursive, n);

    // Measure time for loop
    double time_loop = measure_time(measure_loop, n);

    // Measure time for recursion with memoization
    double time_memo_recursive = measure_time(measure_memo_recursive, n);

    // Measure time for loop with memoization
    double time_memo_loop = measure_time(measure_memo_loop, n);

    // Output the times
    cout << "Time taken by recursion: " << time_recursive << " seconds\n";
    cout << "Time taken by loop: " << time_loop << " seconds\n";
    cout << "Time taken by recursion with memoization: " << time_memo_recursive << " seconds\n";
    cout << "Time taken by loop with memoization: " << time_memo_loop << " seconds\n";

    // Calculate speedups
    double speedup_loop = time_recursive / time_loop;
    double speedup_memo_recursive = time_recursive / time_memo_recursive;
    double speedup_memo_loop = time_recursive / time_memo_loop;

    cout << "Speedup of loop over recursion: " << speedup_loop << "\n";
    cout << "Speedup of recursion with memoization over recursion: " << speedup_memo_recursive << "\n";
    cout << "Speedup of loop with memoization over recursion: " << speedup_memo_loop << "\n";

    return 0;
}
