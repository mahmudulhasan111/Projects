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

# FFT
H = np.fft.fft(h, 2048)

frequency = np.arange(2048) * fs / 2048

magnitude = 20 * np.log10(
    np.abs(H) / np.max(np.abs(H))
)

# Graph
plt.figure(figsize=(8, 5))

plt.plot(frequency[:1024], magnitude[:1024])

plt.axvline(200, linestyle="--")

plt.title("Frequency Response")
plt.xlabel("Frequency (Hz)")
plt.ylabel("Magnitude (dB)")

plt.xlim(0, 500)
plt.ylim(-120, 5)

plt.grid()
plt.show()