//
// Created by adam on 10.11.2019.
//

#include "Generator.h"
#include <random>
#include <set>
#include <iostream>
#include <fstream>

void Generator::saveToFile(uint v, uint e, const std::set<std::pair<uint, uint>> &edges) {
    std::ofstream output;
    std::string filename = "../../examples/generate/in" + std::to_string(generated);
    output.open(filename);
    if (output.is_open()) {
        output << v << " " << e << std::endl;
        for (auto &edge: edges)
            output << edge.first << " " << edge.second << std::endl;
    } else
        std::cerr << "Can't open file." << std::endl;
}

void Generator::generate(uint v, uint e) {
    std::set<std::pair<uint, uint>> edges;

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, v - 1);

    while (edges.size() != e) {
        uint v1 = dis(gen);
        uint v2 = dis(gen);
        if (v1 < v2)
            edges.insert(std::make_pair(v1, v2));
        if (v1 > v2)
            edges.insert(std::make_pair(v2, v1));
    }

    saveToFile(v, e, edges);
    ++generated;
}

void Generator::generateGraphs() {
    std::vector<uint> vertices = {10, 100, 1000};
    std::vector<float> density = {0.25, 0.5, 0.75};
    uint graphs = 3;
    for (auto &v : vertices) {
        for (auto &d : density) {
            uint e = v * (v - 1) / 2 * d;
            for (uint g = 0; g < graphs; ++g) {
                std::cout << "Progress " << generated << "/" << vertices.size() * density.size() * graphs << std::endl;
                generate(v, e);
            }
        }
    }
}

