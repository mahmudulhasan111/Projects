import numpy as np
import matplotlib.pyplot as plt

# Get sequences from user1
x_input = input("Enter first sequence x(n) separated by space (e.g., 1 2 3 4): ")
h_input = input("Enter second sequence h(n) separated by space (e.g., 1 1 1): ")

x = np.array([float(i) for i in x_input.split()])
h = np.array([float(i) for i in h_input.split()])

# Calculate convolution
y = np.convolve(x, h)

print("\nConvolution Result y(n):", y)

# Plotting
plt.figure(figsize=(8, 6))
plt.subplot(3, 1, 1)
plt.stem(x)
plt.title('Input Sequence x(n)')
plt.grid(True)

plt.subplot(3, 1, 2)
plt.stem(h, linefmt='g', markerfmt='go')
plt.title('Impulse Response h(n)')
plt.grid(True)

plt.subplot(3, 1, 3)
plt.stem(y, linefmt='r', markerfmt='ro')
plt.title('Convolution y(n)')
plt.grid(True)

plt.tight_layout()
plt.show()