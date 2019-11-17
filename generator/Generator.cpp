//
// Created by adam on 10.11.2019.
//

#include "Generator.h"
#include <set>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>

void Generator::saveToFile(uint v, uint e, float d, const std::set<std::pair<uint, uint>> &edges, uint g) {
    std::ofstream output;
    std::string filename =
        base_path + std::to_string(v) + '/' + std::to_string(d).substr(0, 4) + '/' + std::to_string(g + indexFirstGraph);
//    std::cout << filename << std::endl;
    output.open(filename);
    if (output.is_open()) {
        output << v << " " << e << std::endl;
        for (auto &edge: edges)
            output << edge.first << " " << edge.second << std::endl;
    } else
        std::cerr << "Can't open file." << std::endl;
    output.close();
}

void Generator::generate(uint v, uint e, float d, uint g) {
    std::set<std::pair<uint, uint>> edges;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, v - 1);

    while (edges.size() != e) {
        uint v1 = dis(gen);
        uint v2 = dis(gen);
        if (v1 < v2)
            edges.insert(std::make_pair(v1, v2));
        if (v1 > v2)
            edges.insert(std::make_pair(v2, v1));
    }

    saveToFile(v, e, d, edges, g);
    ++generated;
}

void Generator::generateGraphs() {
    for (auto &v : vertices) {
        for (auto &d : density) {
            uint e = v * (v - 1) / 2 * d;
            for (uint g = 0; g < graphs; ++g) {
                if (generated == 249)
                    std::cout << "Progress " << generated << "/" << vertices.size() * density.size() * graphs << " ";
                generate(v, e, d, g);
            }
        }
    }
}
