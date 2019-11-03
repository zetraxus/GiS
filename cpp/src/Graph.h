//
// Created by adam on 02.11.2019.
//

#ifndef CPP_GRAPH_H
#define CPP_GRAPH_H


#include <vector>
#include <sys/param.h>

struct Graph {
    const uint vertices;
    const uint edges;
    std::vector<std::vector<uint>> adjacencyMatrix;

    Graph(uint vertices, uint edges);
    void addEdge(uint v1, uint v2);
};


#endif //CPP_GRAPH_H
