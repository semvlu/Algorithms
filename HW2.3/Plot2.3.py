import csv
import seaborn as sns
import matplotlib.pyplot as plt
import matplotlib
import numpy as np

infile = open("2.3.csv", "rt")
data = infile.read()
data = data.replace(",", ".")
infile.close()
infile = open("2.3.csv", "wt")
infile.write(data)
infile.close()

with open("2.3.csv", "r", encoding = 'utf-8') as file:
    spam = csv.reader(file, delimiter = ";")
    tstsize = []
    tsttime = []
    for row in spam:
        tstsize.append(row[1:])
        tsttime.append(row[1:])
size = tstsize[0]
size = list(map(int, size))
time = tsttime[1]
time = list(map(float, time))

font1 = matplotlib.font_manager.FontProperties(fname = '/System/Library/Fonts/PingFang.ttc')

sns.set(style = "darkgrid")
plt.xticks(size)
sns.lineplot(size, time, markers = True, dashes = False, color = '#03A062')   
plt.xticks(np.arange(min(size), max(size) + 1, 2.0))
plt.legend(prop = font1)
plt.title("ISS Quicksort Performance", fontsize = 20, fontproperties = font1)
plt.xticks(fontsize = 6)

plt.savefig('ISS_quicksort_performance.png')
plt.show()