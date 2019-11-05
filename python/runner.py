import sys

from tarjan import TarjanAlgorithm


def input_reader():
    v = int(sys.stdin.readline().split(' ')[0])
    graph = [[] for _ in range(v)]
    for line in sys.stdin:
        start, end = [int(e) for e in line.rsplit()]
        graph[start].append(end)
        graph[end].append(start)
    return graph


def print_output(output):
    output = sorted([sorted(line) for line in output])
    for line in output:
        print(*line)


if __name__ == "__main__":
    graph = input_reader()
    tarjan = TarjanAlgorithm(graph)
    tarjan.run()
    print_output(tarjan.bridges)
