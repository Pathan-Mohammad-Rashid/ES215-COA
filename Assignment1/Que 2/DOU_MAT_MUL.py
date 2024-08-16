import time
import numpy as np

def multiply_matrix_double(N):
    A = np.ones((N, N), dtype=float)
    B = np.full((N, N), 2.0, dtype=float)
    C = np.zeros((N, N), dtype=float)

    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i, j] += A[i, k] * B[k, j]

sizes = [64, 128, 256, 512, 1024]
for N in sizes:
    print(f"Matrix Size: {N}x{N}")
    start = time.time()
    multiply_matrix_double(N)
    end = time.time()
    elapsed = end - start
    print(f"Time for double matrix: {elapsed} seconds")
