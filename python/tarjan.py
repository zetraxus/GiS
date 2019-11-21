class TarjanAlgorithm(object):
    """ A Tarjan's Algorithm for bridge finding

    Initialize with graph as adjacency list. After
    `run`, founded bridges are stored in `bridges` property.
    """
    NOT_ANALYZED = 0
    NO_PARENT = -1

    def __init__(self, adjacency_list):
        self._graph = adjacency_list
        self._length = len(adjacency_list)
        self.clean()

    def clean(self):
        self._bridges = []
        self._dfs_numbers = [self.NOT_ANALYZED] * self._length

    def run(self):
        for i in range(self._length):
            if self._dfs_numbers[i] == self.NOT_ANALYZED:
                self._counter = 1
                self._dfs_tarjan(i, self.NO_PARENT)

    def _dfs_tarjan(self, v, parent):
        self._dfs_numbers[v] = self._counter
        low = self._counter
        self._counter += 1

        for u in self._graph[v]:
            if u != parent:
                if self._dfs_numbers[u] == self.NOT_ANALYZED:
                    tmp = self._dfs_tarjan(u, v)
                    if tmp < low:
                        low = tmp
                elif self._dfs_numbers[u] < low:
                    low = self._dfs_numbers[u]

        if parent > self.NO_PARENT and low == self._dfs_numbers[v]:
            self._bridges.append((parent, v))

        return low

    @property
    def bridges(self):
        return self._bridges
