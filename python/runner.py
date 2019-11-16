import sys
from timeit import default_timer

from tarjan import TarjanAlgorithm


def input_reader(input_file):
    with open(input_file, "r") as file:
        v = int(file.readline().split(' ')[0])
        graph = [[] for _ in range(v)]
        for line in file:
            start, end = [int(e) for e in line.rsplit()]
            graph[start].append(end)
            graph[end].append(start)
        return graph


def print_output(output):
    output = sorted([sorted(line) for line in output])
    for line in output:
        print(*line)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise Exception("Input file must be specific")

    sys.setrecursionlimit(4*sys.getrecursionlimit())
    graph = input_reader(sys.argv[1])
    tarjan = TarjanAlgorithm(graph)

    start = default_timer()
    tarjan.run()
    end = default_timer()

    print(int((end-start) * 1000000))  # microseconds, without fractional part
