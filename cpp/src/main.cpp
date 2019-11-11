#include <iostream>
#include <fstream>
#include <algorithm>
#include <memory>
#include <chrono>
#include "Graph.h"

const uint SUCCESS = 1;
const uint FAILED = 0;

bool openFile(int argc, char **argv, std::ifstream &data) {
    if (argc != 2) {
        std::cout << "Pass input file as argument" << std::endl;
        return FAILED;
    } else {
        data.open(argv[1]);
        if (!data.is_open()) {
            std::cout << "Can't open file." << std::endl;
            return FAILED;
        }
    }
    return SUCCESS;
}

std::unique_ptr<Graph> loadData(std::ifstream &input) {
    uint vertices, edges, v1, v2;
    input >> vertices >> edges;
    std::unique_ptr<Graph> graph(new Graph(vertices, edges));
    for (uint edge = 0; edge < edges; ++edge) {
        input >> v1 >> v2;
        graph->addEdge(v1, v2);
        graph->addEdge(v2, v1);
    }
    return std::move(graph);
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

int main(int argc, char **argv) {
    std::ifstream data;
    if (openFile(argc, argv, data) == SUCCESS) {
        auto graph = loadData(data);
        auto start = std::chrono::steady_clock::now();
        for (uint v = 0; v < graph->vertices; ++v) {
            if (graph->D[v] == 0)
                graph->DFSBridge(v, -1);
        }
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
    }
    return 0;
}