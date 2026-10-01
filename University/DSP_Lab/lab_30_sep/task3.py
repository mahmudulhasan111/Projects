import numpy as np
import matplotlib.pyplot as plt
from scipy import signal

# RC Circuit Parameters (1 kOhm, 1 uF)
R = 1000  
C = 1e-6  
fc = 1 / (2 * np.pi * R * C)
print(f"Filter Cutoff Frequency: {fc:.2f} Hz")

# Transfer Functions
sys_lp = signal.TransferFunction([1], [R*C, 1])          # Low Pass: 1 / (RCs + 1)
sys_hp = signal.TransferFunction([R*C, 0], [R*C, 1])     # High Pass: RCs / (RCs + 1)

# Frequency range for Bode plot (10^1 to 10^5 rad/s)
w = np.logspace(1, 5, 500)

# Calculate Bode plot data
w_lp, mag_lp, phase_lp = signal.bode(sys_lp, w)
w_hp, mag_hp, phase_hp = signal.bode(sys_hp, w)

# Plotting
plt.figure(figsize=(10, 8))

# Low Pass Magnitude
plt.subplot(2, 2, 1)
plt.semilogx(w_lp / (2*np.pi), mag_lp, 'b')
plt.title('Analog Low Pass Filter - Magnitude')
plt.ylabel('Magnitude (dB)')
plt.grid(True, which="both", ls="-")

# Low Pass Phase
plt.subplot(2, 2, 3)
plt.semilogx(w_lp / (2*np.pi), phase_lp, 'b')
plt.title('Analog Low Pass Filter - Phase')
plt.xlabel('Frequency (Hz)')
plt.ylabel('Phase (degrees)')
plt.grid(True, which="both", ls="-")

# High Pass Magnitude
plt.subplot(2, 2, 2)
plt.semilogx(w_hp / (2*np.pi), mag_hp, 'r')
plt.title('Analog High Pass Filter - Magnitude')
plt.grid(True, which="both", ls="-")

# High Pass Phase
plt.subplot(2, 2, 4)
plt.semilogx(w_hp / (2*np.pi), phase_hp, 'r')
plt.title('Analog High Pass Filter - Phase')
plt.xlabel('Frequency (Hz)')
plt.grid(True, which="both", ls="-")

plt.tight_layout()
plt.show()