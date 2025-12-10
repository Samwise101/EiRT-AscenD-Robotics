import seaborn as sn
import matplotlib.pyplot as plt
import numpy as np

slave_1_shmem = [
58.26,
57.67,
56.26,
57.97,
57.76,
58.57,
57.26,
57.31,
59.57,
57.26,
]

master_1_shmem = [
68.18,
68.26,
68.52,
68.32,
68.31,
68.82,
68.20,
68.91,
68.01,
68.77,
]

master_5_res = [
	76.85,
	73.91,
	74.43,
	74.53,
	75.77,
	75.96,
]

slave_5_res = [
64.25,
64.73,
65.14,
65.02,
64.88,
64.95,
65.04,
]

master_30_res = [
	79.70,
	80.84,
	81.44,
	82.14,
	82.04,
	82.04,
	82.17,
	82.42,
	82.42,
]

slave_30_res = [
70.23,
70.39,
70.05,
69.63,
69.82,
70.12,
69.91,
70.39,
70.00,
70.37,
70.33,
69.93,
70.23,
70.27,
70.18,
69.82,
70.50,
70.14,
69.33,
70.16,
70.17,
70.03,
69.77,
70.39,
69.83,
69.80,
70.41,
70.07,
70.55,
]

slave_data = {
	'S1': slave_1_shmem,
	'S5': slave_5_res,
	'S30': slave_30_res,
}

master_data = {
	'M1': master_1_shmem,
	'M5': master_5_res,
	'M30': master_30_res,
}

print("Slave 1 mean, std", np.mean(slave_1_shmem), np.std(slave_1_shmem))
print("Master 1 mean, std",np.mean(master_1_shmem), np.std(master_1_shmem))
print("Slave 5 mean, std",np.mean(slave_5_res), np.std(slave_5_res))
print("Master 5 mean, std", np.mean(master_5_res), np.std(master_5_res))
print("Slave 30 mean, std",np.mean(slave_30_res), np.std(slave_30_res))
print("Master 30 mean, std", np.mean(master_30_res), np.std(master_30_res))

plt.figure()
boxplot = sn.boxplot(data=slave_data)
boxplot.set_title('Memory usage Comparison - Slave')
boxplot.set_ylabel('Usage (MiB)')
plt.savefig('memory_comparison_slave.png')
plt.grid()

plt.figure()
boxplot = sn.boxplot(data=master_data)
boxplot.set_title('Memory usage Comparison - Master')
boxplot.set_ylabel('Usage (MiB)')
plt.savefig('memory_comparison_master.png')
plt.grid()

plt.show()
