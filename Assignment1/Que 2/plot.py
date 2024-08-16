import matplotlib.pyplot as plt

N_values = [64, 128, 256, 512, 1024]
cpp_int_times = [0.0049553, 0.0308182, 0.265395, 1.90729, 16.3077]  
cpp_double_times = [0.0056593, 0.0278977, 0.273262, 2.41305, 20.0193]  
python_int_times = [0.1680245, 1.4777324, 12.7700958, 101.6159472, 865.3103415]  
python_double_times = [0.1362602, 1.0931088, 9.6865656, 80.1353812, 745.5287251]  

plt.plot(N_values, cpp_int_times, label="C++ Int", marker='o')
plt.plot(N_values, cpp_double_times, label="C++ Double", marker='o')
plt.plot(N_values, python_int_times, label="Python Int", marker='o')
plt.plot(N_values, python_double_times, label="Python Double", marker='o')

plt.xlabel("Matrix Size (N x N)")
plt.ylabel("Execution Time (seconds)")
plt.title("Matrix Multiplication Execution Time: C++ vs Python")
plt.legend()
plt.grid(True)
plt.show()
