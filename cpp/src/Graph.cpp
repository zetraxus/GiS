//
// Created by adam on 02.11.2019.
//

#include "Graph.h"

Graph::Graph(uint vertices, uint edges) : vertices(vertices), edges(edges) {
    adjacencyMatrix.reserve(vertices);
}

void Graph::addEdge(uint v1, uint v2) {
    adjacencyMatrix[v1].push_back(v2);
}

uint Graph::DFSBridge(uint v, int vf, std::vector<uint> &D, uint cv, std::vector<puu> &bridges) {
    D[v] = cv;
    uint low = cv++;
    for (auto el : adjacencyMatrix[v]) {
        if (el != vf) {
            if (D[el] == 0) {
                uint temp = this->DFSBridge(el, v, D, cv, bridges);
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
