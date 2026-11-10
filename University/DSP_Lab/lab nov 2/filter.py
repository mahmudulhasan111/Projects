
import numpy as np
import matplotlib.pyplot as plt


fs = 1000
fc = 200
N = 21
M = 10


wc = 2 * np.pi * fc / fs


n = np.arange(N)

hd = np.zeros(N)

for i in range(N):
    if i == M:
        hd[i] = wc / np.pi
    else:
        hd[i] = np.sin(wc * (i - M)) / (np.pi * (i - M))


w = 0.54 - 0.46 * np.cos(2 * np.pi * n / (N - 1))

h = hd * w

print("Ideal Impulse Response:")
print(hd)

print("\nHamming Window:")
print(w)

print("\nFinal FIR Coefficients:")
print(h)

H = np.fft.fft(h, 2048)
frequency = np.arange(2048) * fs / 2048

magnitude = 20 * np.log10(
    np.abs(H) / np.max(np.abs(H)) + 1e-12
)

t = np.arange(0,1, 1/fs)

x = np.round(5 * np.sin(2 * np.pi * 20 * t))

plt.figure(figsize=(15, 8))

plt.subplot(2, 2, 1)
plt.plot(t, x, marker='o', markersize=3)
plt.title("Basic Input Signal")
plt.xlabel("Time (seconds)")
plt.ylabel("Amplitude")
plt.grid()

plt.subplot(2, 2, 2)
plt.stem(n, hd)
plt.title("Ideal Impulse Response")
plt.xlabel("n")
plt.ylabel("Amplitude")
plt.grid()

plt.subplot(2, 2, 3)
plt.stem(n, h)
plt.title("FIR Coefficients")
plt.xlabel("n")
plt.ylabel("Amplitude")
plt.grid()

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
