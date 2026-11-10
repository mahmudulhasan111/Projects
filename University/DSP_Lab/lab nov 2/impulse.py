import numpy as np
import matplotlib.pyplot as plt

# Given values
fs = 1000
fc = 200
N = 21

# Cutoff frequency
wc = 2 * np.pi * fc / fs

# Center point
M = 10

# Sample index
n = np.arange(N)


# 1. Ideal Impulse Response
hd = np.zeros(N)

for i in range(N):
    if i == M:
        hd[i] = wc / np.pi
    else:
        hd[i] = np.sin(wc * (i - M)) / (np.pi * (i - M))

# Print values
print("Ideal Impulse Response:")
print(hd)


# 5. Draw Graphs

plt.figure(figsize=(15, 4))


# Graph 1: Ideal Impulse Response
plt.subplot(1, 3, 1)

plt.stem(n, hd)

plt.title("Ideal Impulse Response")
plt.xlabel("n")
plt.ylabel("Amplitude")
plt.grid()
plt.show()

