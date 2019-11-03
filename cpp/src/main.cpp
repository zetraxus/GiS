#include <iostream>
#include <fstream>
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

uint DFSBridge(uint v, uint vf, Graph *graph, std::vector<uint> &D, uint cv, std::vector<puu> &bridges) {
    std::cout<<"#" << std::endl;
    D[v] = cv;
    uint low = cv++;
    uint temp;
    for (auto &el : graph->adjacencyMatrix[v]) {
        if (el != vf) {
            if (D[el] == 0) {
                temp = DFSBridge(el, v, graph, D, cv, bridges);
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

std::vector<std::pair<uint, uint>> &runAlgorithm(Graph *graph) {
    std::vector<puu> bridges;
    std::vector<uint> D(graph->vertices);
    uint cv = 1;
    uint vf;

    uint start = 1;
    DFSBridge(start, start, graph, D, cv, bridges);

    for (auto &el : bridges)
        std::cout<< el.first << " " << el.second;
}

int main(int argc, char **argv) {
    std::ifstream input;

    if (argc != 2) {
        std::cout << "Pass filename as argument";
        return -1;
    } else {
        input.open(argv[1]);
        if (!input.is_open()) {
            std::cout << "Can't open file.";
            return -2;
        }
    }

    auto graph = loadData(input);
    runAlgorithm(graph);

    return 0;
}

//https://eduinf.waw.pl/inf/alg/001_search/0130a.php