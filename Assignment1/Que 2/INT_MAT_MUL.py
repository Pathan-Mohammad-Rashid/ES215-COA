import time
import numpy as np

def multiply_matrix_int(N):
    A = np.ones((N, N), dtype=int)
    B = np.full((N, N), 2, dtype=int)
    C = np.zeros((N, N), dtype=int)

    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i, j] += A[i, k] * B[k, j]

sizes = [64, 128, 256, 512, 1024]
for N in sizes:
    print(f"Matrix Size: {N}x{N}")
    start = time.time()
    multiply_matrix_int(N)
    end = time.time()
    elapsed = end - start
    print(f"Time for int matrix: {elapsed} seconds")
