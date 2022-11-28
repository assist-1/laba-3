import matplotlib as mpl
import matplotlib.pyplot as plt
import numpy as np

colors = ["red", "green", "blue", "black", "yellow", "orange", "purple", "brown", "pink", "gray", "olive", "cyan"]

with open("test.txt", "r") as f:
    n = int(f.readline())
    values = [[float(x) for x in line.split()] for line in f.readlines()]

fig, ax = plt.subplots()
for i in range(n):
    a, b = values[i]
    col = colors.pop()
    ax.plot(np.linspace(a, b, 100), [i + 1] * 100, color=col)
    ax.plot([a] * 100, np.linspace(0, i + 1, 100), color=col)
    ax.plot([b] * 100, np.linspace(0, i + 1, 100), color=col)
plt.show()