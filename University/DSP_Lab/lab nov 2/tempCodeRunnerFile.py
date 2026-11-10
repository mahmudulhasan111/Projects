
import numpy as np
import matplotlib.pyplot as plt

# Given values
fs = 1000
fc = 200
N = 21
M = 10

# Cutoff frequency
wc = 2 * np.pi * fc / fs

# Sample index
n = np.arange(N)

# 1. Ideal Impulse Response
hd = np.zeros(N)

for i in range(N):
    if i == M:
        hd[i] = wc / np.pi
    else:
        hd[i] = np.sin(wc * (i - M)) / (np.pi * (i - M))

# 2. Hamming Window
w = 0.54 - 0.46 * np.cos(2 * np.pi * n / (N - 1))

# 3. Final FIR Coefficients
h = hd * w

# Print values
print("Ideal Impulse Response:")
print(hd)

print("\nHamming Window:")
print(w)

print("\nFinal FIR Coefficients:")
print(h)

# 4. Frequency Response using FFT
H = np.fft.fft(h, 2048)
frequency = np.arange(2048) * fs / 2048

magnitude = 20 * np.log10(
    np.abs(H) / np.max(np.abs(H)) + 1e-12
)

# 5. Basic Input Signal
t = np.arange(0, 0.05, 1/fs)

x = np.sin(2 * np.pi * 100 * t) + 0.5 * np.sin(2 * np.pi * 400 * t)

# 6. Draw All Graphs
plt.figure(figsize=(15, 8))

# Graph 1: Basic Input Signal
plt.subplot(2, 2, 1)
plt.plot(t, x)
plt.title("Basic Input Signal")
plt.xlabel("Time (seconds)")
plt.ylabel("Amplitude")
plt.grid()

# Graph 2: Ideal Impulse Response
plt.subplot(2, 2, 2)
plt.stem(n, hd)
plt.title("Ideal Impulse Response")
plt.xlabel("n")
plt.ylabel("Amplitude")
plt.grid()

# Graph 3: FIR Coefficients
plt.subplot(2, 2, 3)
plt.stem(n, h)
plt.title("FIR Coefficients")
plt.xlabel("n")
plt.ylabel("Amplitude")
plt.grid()

# Graph 4: Frequency Response
plt.subplot(2, 2, 4)
plt.plot(frequency[:1024], magnitude[:1024])
plt.axvline(200, linestyle="--", color="red", label="Cutoff = 200 Hz")
plt.title("Frequency Response")
plt.xlabel("Frequency (Hz)")
plt.ylabel("Magnitude (dB)")
plt.xlim(0, 500)
plt.ylim(-120, 5)
plt.legend()
plt.grid()

plt.tight_layout()
plt.show()
