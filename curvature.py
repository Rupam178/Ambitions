import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Define the function
def f(x, y):
    return 2 * np.pi * x**2 * y

# Create a grid of x and y values
x = np.linspace(-2, 2, 100)
y = np.linspace(-2, 2, 100)
X, Y = np.meshgrid(x, y)
Z = f(X, Y)

# Create the 3D plot
fig = plt.figure(figsize=(10, 7))
ax = fig.add_subplot(111, projection='3d')

# Plot the surface with smooth shading and realistic lighting
surf = ax.plot_surface(
    X, Y, Z,
    cmap='viridis',
    alpha=0.9,
    linewidth=0,
    antialiased=True,
    edgecolor='none',
    shade=True
)

# Add grid lines and axis labels
ax.grid(True, color='gray', linestyle='--', linewidth=0.5)
ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')
ax.set_title(r'$z = 2 pi x^2 y$', fontsize=14)

# Add a color bar to show z‑values
fig.colorbar(surf, ax=ax, shrink=0.5, aspect=5)

# Adjust view angle for better 3D perspective
ax.view_init(elev=20, azim=45)

plt.tight_layout()
plt.show()