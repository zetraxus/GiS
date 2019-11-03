#include <iostream>
#include <fstream>
#include <algorithm>
#include "Graph.h"

typedef std::pair<uint, uint> puu;

Graph *loadData(std::ifstream &input) {
    uint vertices, edges, v1, v2;
    input >> vertices >> edges;
    auto graph = new Graph(vertices, edges);
    for (uint edge = 0; edge < edges; ++edge) {
        input >> v1 >> v2;
        graph->addEdge(v1, v2);
        graph->addEdge(v2, v1);
    }
    return graph;
}

uint DFSBridge(uint v, int vf, Graph *graph, std::vector<uint> &D, uint cv, std::vector<puu> &bridges) {
    D[v] = cv;
    uint low = cv++;
    for (auto &el : graph->adjacencyMatrix[v]) {
        if (el != vf) {
            if (D[el] == 0) {
                uint temp = DFSBridge(el, v, graph, D, cv, bridges);
                if (temp < low)
                    low = temp;
            } else {
                if (D[el] < low)
                    low = D[el];
            }
        }
    }

    if (vf > -1 && low == D[v])
        bridges.emplace_back(std::make_pair(vf, v));

    return low;
}

std::vector<std::pair<uint, uint>> runAlgorithm(Graph *graph) {
    std::vector<puu> bridges;
    std::vector<uint> D(graph->vertices);
    uint cv = 1;

    DFSBridge(0, -1, graph, D, cv, bridges);

    return bridges;
}

void compareResults(std::ifstream &results, std::vector<puu> &bridges) {
    uint v1, v2, it = 0;
    std::sort(bridges.begin(), bridges.end());
    while (results >> v1 && results >> v2) {
        if (bridges[it].first != v1 || bridges[it++].second != v2) {
            std::cout << "failed" << std::endl;
            return;
        }
    }
    if (it != bridges.size())
        std::cout << "failed" << std::endl;
    else
        std::cout << "success" << std::endl;
}

int main(int argc, char **argv) {
    std::ifstream data;
    std::ifstream results;

    if (argc != 3) {
        std::cout << "Pass input and output files as arguments" << std::endl;
        return -1;
    } else {
        data.open(argv[1]);
        results.open(argv[2]);
        if (!data.is_open() || !results.is_open()) {
            std::cout << "Can't open file." << std::endl;
            return -2;
        }
    }

    auto graph = loadData(data);
    auto bridges = runAlgorithm(graph);
    compareResults(results, bridges);

    return 0;
}