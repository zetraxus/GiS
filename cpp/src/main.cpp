#include <iostream>
#include <fstream>
#include "Graph.h"

Graph* loadData(std::ifstream& input){
    unsigned vertices, edges, v1, v2;
    input >> vertices >> edges;
    auto graph = new Graph(vertices, edges);
    for (unsigned edge = 0; edge < edges; ++edge){
        input >> v1 >> v2;
        graph->addEdge(v1, v2);
    }
    return graph;
}

int main(int argc, char** argv) {
    std::ifstream input;

    if (argc != 2){
        std::cout << "Pass filename as argument";
        return -1;
    } else {
        input.open(argv[1]);
        if(!input.is_open()) {
            std::cout << "Can't open file.";
            return -2;
        }
    }

    auto graph = loadData(input);

    return 0;
}

//https://eduinf.waw.pl/inf/alg/001_search/0130a.php