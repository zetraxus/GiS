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
