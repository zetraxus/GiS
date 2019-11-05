

class TarjanAlgorithm(object):
    def __init__(self, graph):
        self._graph = graph  # adjacency list
        self._length = len(graph)
        self._bridges = []

    def run(self):
        self._bridges = []
        self._dfs_numbers = [0] * self._length

        for i in range(self._length):
            if self._dfs_numbers[i] == 0:
                self._counter = 1
                self._dfs_tarjan(i, -1)

    def _dfs_tarjan(self, v, parent):
        self._dfs_numbers[v] = self._counter
        low = self._counter
        self._counter += 1

        for u in self._graph[v]:
            if u == parent:
                continue
            if self._dfs_numbers[u] == 0:
                tmp = self._dfs_tarjan(u, v)
                if tmp < low:
                    low = tmp
            elif self._dfs_numbers[u] < low:
                low = self._dfs_numbers[u]
        if parent > -1 and low == self._dfs_numbers[v]:
            self._bridges.append((parent, v))
        return low

    @property
    def bridges(self):
        return self._bridges