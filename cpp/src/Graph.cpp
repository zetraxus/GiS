//
// Created by adam on 02.11.2019.
//

#include <iostream>
#include "Graph.h"

Graph::Graph(uint vertices, uint edges) : vertices(vertices), edges(edges) {
    adjacencyMatrix.reserve(vertices);
    D.reserve(vertices);
}

void Graph::addEdge(uint v1, uint v2) {
    adjacencyMatrix[v1].push_back(v2);
}

uint Graph::DFSBridge(uint v, int vf) {
    D[v] = cv;
    uint low = cv++;
    for (auto el : adjacencyMatrix[v]) {
        if (el != vf) {
            if (D[el] == 0) {
                uint temp = this->DFSBridge(el, v);
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

void Graph::print() {
    std::cout << vertices << " " << edges << std::endl;
    for (uint v1 = 0; v1 < adjacencyMatrix.size(); ++v1) {
        for (auto &v2 : adjacencyMatrix[v1]) {
            std::cout << v1 << " " << v2 << std::endl;
        }
    }
}
