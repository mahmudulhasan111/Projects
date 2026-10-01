import numpy as np
import matplotlib.pyplot as plt

# Get sequences from user
x_input = input("Enter first sequence x(n) separated by space (e.g., 1 2 3): ")
y_input = input("Enter second sequence y(n) separated by space (e.g., 1 2 1): ")

x = np.array([float(i) for i in x_input.split()])
y_seq = np.array([float(i) for i in y_input.split()])

# Calculate cross-correlation 
r = np.correlate(x, y_seq, mode='full')

print("\nCross-Correlation Result r(n):", r)

# Plotting
plt.figure(figsize=(8, 6))
plt.subplot(3, 1, 1)
plt.stem(x)
plt.title('Sequence x(n)')
plt.grid(True)

plt.subplot(3, 1, 2)
plt.stem(y_seq, linefmt='g', markerfmt='go')
plt.title('Sequence y(n)')
plt.grid(True)

plt.subplot(3, 1, 3)
plt.stem(r, linefmt='r', markerfmt='ro')
plt.title('Cross-Correlation r(n)')
plt.xlabel('Lag')
plt.grid(True)

plt.tight_layout()
plt.show()