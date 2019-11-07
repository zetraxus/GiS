//
// Created by adam on 02.11.2019.
//

#ifndef CPP_GRAPH_H
#define CPP_GRAPH_H


#include <vector>
#include <sys/param.h>

typedef std::pair<uint, uint> puu;

struct Graph {
    const uint vertices;
    const uint edges;
    std::vector<std::vector<uint>> adjacencyMatrix;
    std::vector<puu> bridges;
    std::vector<uint> D;
    uint cv = 1;

    Graph(uint vertices, uint edges);

    void addEdge(uint v1, uint v2);

    uint DFSBridge(uint v, int vf);
};


#endif //CPP_GRAPH_H
