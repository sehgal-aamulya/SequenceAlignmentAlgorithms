import csv
import functools
import operator
import sys

import matplotlib.pyplot as plt

if __name__ == "__main__":
    file_name = sys.argv[1]

    basic = []
    efficient = []

    with open(file_name) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=",")
        next(csv_reader)
        for row in csv_reader:
            if row[0] == "Basic":
                basic.append((row[1], float(row[2]), float(row[3])))
            else:
                efficient.append((row[1], float(row[2]), float(row[3])))

    basic.sort(key=lambda x: int(x[0]))
    efficient.sort(key=lambda x: int(x[0]))

    basic_ps = list(map(lambda x: x[0], basic))
    basic_ct = list(map(lambda x: x[1], basic))
    basic_mu = list(map(lambda x: x[2], basic))

    efficient_ps = list(map(lambda x: x[0], efficient))
    efficient_ct = list(map(lambda x: x[1], efficient))
    efficient_mu = list(map(lambda x: x[2], efficient))

    average_basic_ct = functools.reduce(operator.add, basic_ct) / len(basic_ct)
    average_efficient_ct = functools.reduce(operator.add, efficient_ct) / len(efficient_ct)

    average_basic_mu = functools.reduce(operator.add, basic_mu) / len(basic_mu)
    average_efficient_mu = functools.reduce(operator.add, efficient_mu) / len(efficient_mu)

    print(f"Efficient Algorithm is {average_efficient_ct / average_basic_ct}x slower than Basic Algorithm")
    print(
        f"Efficient Algorithm takes {average_basic_mu / average_efficient_mu}x less memory than Basic "
        f"Algorithm"
    )

    fig, axs = plt.subplots(2, figsize=(14, 10))
    fig.suptitle("Sequence Alignment")

    axs[0].plot(basic_ps, basic_ct, marker="o", label="Basic")
    axs[0].plot(efficient_ps, efficient_ct, marker="o", label="Efficient")
    axs[0].legend(loc="upper left")
    axs[0].set_title("Problem Size Vs CPU Time")
    axs[0].set_xlabel("Problem Size")
    axs[0].set_ylabel("CPU Time (in seconds)")

    axs[1].plot(basic_ps, basic_mu, marker="o", label="Basic")
    axs[1].plot(efficient_ps, efficient_mu, marker="o", label="Efficient")
    axs[1].legend(loc="upper left")
    axs[1].set_title("Problem Size Vs Memory Usage")
    axs[1].set_xlabel("Problem Size")
    axs[1].set_ylabel("Memory Usage (in kilobytes)")

    fig.savefig("AllPlots.png")

    fig.savefig("CPUPlot.png",
                bbox_inches=axs[0].get_window_extent().transformed(fig.dpi_scale_trans.inverted()).expanded(1.2, 1.3))
    fig.savefig("MemoryPlot.png",
                bbox_inches=axs[1].get_window_extent().transformed(fig.dpi_scale_trans.inverted()).expanded(1.3, 1.3))

    plt.show()
