//
// Created by adam on 02.11.2019.
//

#include "Graph.h"

Graph::Graph(unsigned vertices, unsigned edges) : vertices(vertices), edges(edges) {
    adjacencyMatrix.reserve(vertices);
}

void Graph::addEdge(unsigned v1, unsigned v2) {
    adjacencyMatrix[v1].push_back(v2);
}
