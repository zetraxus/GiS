GRAPH = []  # adjacency list

CV = 1
# D - list of DFS-number for every V


def DFSTarjan(v, parent, graph, D, mosts):
    global CV
    D[v] = CV
    Low = CV
    CV += 1

    for u in graph[v]:
        if u == parent:
            continue
        if D[u] == 0:
            tmp = DFSTarjan(u, v, graph, D, mosts)
            if tmp < Low:
                Low = tmp
        elif D[u] < Low:
            Low = D[u]
    if parent > -1 and Low == D[v]:
        mosts.append((parent, v))
    return Low


def find_mosts(graph):
    global CV
    D = [0] * len(graph)
    mosts = []
    for i in range(len(graph)):
        if D[i] == 0:
            CV = 1
            DFSTarjan(i, -1, graph, D, mosts)
    return mosts


if __name__ == "__main__":
    graph = [[1, 2, 3],  # 0
             [0, 2, 14],  # 1
             [0, 1, ],  # 2
             [0, ],  # 3
             [11, 12],  # 4
             [6, 9],  # 5
             [5, 7, 8],  # 6
             [6],  # 7
             [6],  # 8
             [5],  # 9
             [15],  # 10
             [4, 15],  # 11
             [4, 15],  # 12
             [14, 16],  # 13
             [1, 13, 16],  # 14
             [10, 11, 12],  # 15
             [13, 14],  # 16
             ]
    print (find_mosts(graph))