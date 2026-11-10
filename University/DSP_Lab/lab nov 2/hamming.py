import numpy as np
import matplotlib.pyplot as plt

# Given values
fs = 1000
fc = 200
N = 21

wc = 2 * np.pi * fc / fs
M = 10

n = np.arange(N)

# Ideal Impulse Response
hd = np.zeros(N)

for i in range(N):
    if i == M:
        hd[i] = wc / np.pi
    else:
        hd[i] = np.sin(wc * (i - M)) / (np.pi * (i - M))

# Hamming Window
w = 0.54 - 0.46 * np.cos(2 * np.pi * n / (N - 1))

# Final FIR Coefficients
h = hd * w

print("Hamming Window:")
print(w)

print("\nFinal FIR Coefficients:")
print(h)

# Graph
plt.figure(figsize=(8, 5))
plt.stem(n, h)

plt.title("FIR Coefficients")
plt.xlabel("Sample Index (n)")
plt.ylabel("Amplitude")
plt.grid()

plt.show()