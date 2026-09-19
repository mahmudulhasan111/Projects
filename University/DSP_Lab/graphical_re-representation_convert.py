import numpy as np
import matplotlib.pyplot as plt

# Original signal (Example)
n = np.arange(-3, 5)
x = np.array([0, 1, 2, 3, 2, 1, 0, 1])   # Replace with your signal values

# x(n-3): Delay by 3 samples
n_delay = n + 3

# x(n+2): Advance by 2 samples
n_advance = n - 2

plt.figure(figsize=(12,4))

# Original Signal
plt.subplot(1,3,1)
plt.stem(n, x)
plt.title("Original Signal x(n)")
plt.xlabel("n")
plt.ylabel("Amplitude")
plt.grid(True)

# x(n-3)
plt.subplot(1,3,2)
plt.stem(n_delay, x)
plt.title("Delayed Signal x(n-3)")
plt.xlabel("n")
plt.grid(True)

# x(n+2)
plt.subplot(1,3,3)
plt.stem(n_advance, x)
plt.title("Advanced Signal x(n+2)")
plt.xlabel("n")
plt.grid(True)

plt.tight_layout()
plt.show()
