""" Module for running Tarjan's algorithm

Algorithm is run with graph from file given as a first
comand-line argument. Time of execution is printed on
standard output in microseconds.

Example runs from CLI:

    python3 runner.py graph0.in
"""
import sys
from timeit import default_timer

from tarjan import TarjanAlgorithm


def load_graph(input_file):
    """ Expected file format:

    <vertex_count: int> <edges_count: int>
    <one edge as a pair u v per line: int int>

    Vertexes' numbers start with 0. Example:
    4 3
    0 1
    1 2
    2 3
    """
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

    # Recursion limit must allow to run recursion DFS
    # at worst in depth equals to vertex count
    graph = load_graph(sys.argv[1])
    sys.setrecursionlimit(sys.getrecursionlimit() + len(graph))
    tarjan = TarjanAlgorithm(graph)

    start = default_timer()
    tarjan.run()
    end = default_timer()

    print(int((end-start) * 1000000))  # microseconds, without fractional part
