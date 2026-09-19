import numpy as np
import matplotlib.pyplot as plt

A = 1
f = 5
t = np.linspace(0, 1, 1000)

x1 = A * np.sin(2 * np.pi * f * t)
x2 = A * np.sin(2 * np.pi * f * t + 2 * np.pi / 3)
x3 = A * np.sin(2 * np.pi * f * t - 2 * np.pi / 3)

plt.figure(figsize=(10, 6))

plt.plot(t, x1, 'b-', linewidth=2, label='Phase-1')
plt.plot(t, x2, 'g--', linewidth=2, label='Phase-2')
plt.plot(t, x3, 'r:', linewidth=2, label='Phase-3')

plt.title('Three phase sinusoidal signal')
plt.xlabel('Time (t)')
plt.ylabel('Amplitude (V)')
plt.legend()
plt.grid()
plt.tight_layout()

plt.show()



x = np.linspace(0, 60, 1000)

y1 = np.sin(np.pi * x / 3)
y2 = -np.sin(np.pi * x / 30)

plt.figure(figsize=(10, 4))

# Blue high-frequency signal
plt.plot(x, y1, 'b-', linewidth=2)

# Orange dashed signal with circular markers
x_points = np.arange(0, 61, 5)
y_points = -np.sin(np.pi * x_points / 30)

plt.plot(x_points, y_points, 'o--', linewidth=2)

plt.xlim(0, 62)
plt.ylim(-1, 1)

plt.xticks([0, 20, 40, 60])
plt.yticks([-0.5, 0, 0.5])

plt.grid(False)
plt.show()

fig, ax = plt.subplots(3, 1, figsize=(10, 10))
# ================= GRAPH 1 =================
n1 = np.array([1, 2, 4, 6, 8, 10])
x1 = np.ones(len(n1))

ax[0].stem(n1, x1, basefmt=" ")
ax[0].set_title("Graph 1")
ax[0].set_xlabel("n")
ax[0].set_ylabel("x[n]")
ax[0].set_xlim(0, 12)
ax[0].set_ylim(0, 1.3)
ax[0].grid(True, alpha=0.3)


# ================= GRAPH 2 =================
n2 = np.arange(1, 6)
x2 = np.arange(1, 6)

ax[1].stem(n2, x2, basefmt=" ")
ax[1].set_title("Graph 2")
ax[1].set_xlabel("n")
ax[1].set_ylabel("x[n]")
ax[1].set_xlim(0, 6)
ax[1].set_ylim(0, 5.5)
ax[1].set_xticks(n2)
ax[1].set_yticks(np.arange(0, 6))
ax[1].grid(True, alpha=0.3)


# ================= GRAPH 3 =================
n3 = np.arange(-20, 21)

# x[n] = 5(0.8)^n u[n]
x3 = np.where(n3 >= 0, 5 * (0.8 ** n3), 0)

ax[2].stem(n3, x3, basefmt=" ")

ax[2].set_title(r"Graph 3: $x[n] = 5(0.8)^n u[n]$")
ax[2].set_xlabel("n")
ax[2].set_ylabel("x[n]")
ax[2].set_xlim(-20, 20)
ax[2].set_ylim(-0.2, 5.5)
ax[2].set_xticks(np.arange(-20, 21, 5))
ax[2].set_yticks(np.arange(0, 6))
ax[2].grid(True, alpha=0.3)

plt.tight_layout()
plt.show()