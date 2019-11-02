//
// Created by adam on 02.11.2019.
//

#ifndef CPP_GRAPH_H
#define CPP_GRAPH_H


#include <vector>

class Graph {
    const unsigned vertices;
    const unsigned edges;

    std::vector<std::vector<unsigned>> adjacencyMatrix;

public:
    Graph(unsigned vertices, unsigned edges);
    void addEdge(unsigned v1, unsigned v2);
};


#endif //CPP_GRAPH_H
