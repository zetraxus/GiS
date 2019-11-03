#include <iostream>
#include <fstream>
#include <algorithm>
#include "Graph.h"

const uint SUCCESS = 1;
const uint FAILED = 0;

int openFiles(int argc, char **argv, std::ifstream &data, std::ifstream &results) {
    if (argc != 4) {
        std::cout << "Pass input and output files as arguments" << std::endl;
        return FAILED;
    } else {
        data.open(argv[2]);
        results.open(argv[3]);
        if (!data.is_open() || !results.is_open()) {
            std::cout << "Can't open file." << std::endl;
            return FAILED;
        }
    }
    return SUCCESS;
}

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

bool compareResults(std::ifstream &results, std::vector<puu> &bridges) {
    uint v1, v2, it = 0;
    std::sort(bridges.begin(), bridges.end());
    while (results >> v1 && results >> v2) {
        if (bridges[it].first != v1 || bridges[it++].second != v2)
            return false;
    }

    return it == bridges.size();
}

// argv[1]- test no., argv[2]- input filename, argv[3]- result filename
int main(int argc, char **argv) {
    std::ifstream data, results;
    if (openFiles(argc, argv, data, results) == SUCCESS) {
        auto graph = loadData(data);
        for (uint v = 0; v < graph->vertices; ++v) {
            if (graph->D[v] == 0)
                graph->DFSBridge(v, -1, 1);
        }
        std::cout << "test " << argv[1] << ": " << compareResults(results, graph->bridges) << std::endl;
    }
    return 0;
}