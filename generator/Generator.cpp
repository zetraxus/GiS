//
// Created by adam on 10.11.2019.
//

#include "Generator.h"
#include <set>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>

void Generator::saveToFile(uint v, uint e, const std::set<std::pair<uint, uint>> &edges) {
    std::ofstream output;
    std::string filename = path + std::to_string(generated);
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

    saveToFile(v, e, edges);
    ++generated;
}

void Generator::generateGraphs() {
    for (auto &v : vertices) {
        for (auto &d : density) {
            uint e = v * (v - 1) / 2 * d;

            path = base_path + "_" + std::to_string(v) + "_" + std::to_string(d) + "/";
            mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

            for (uint g = 0; g < graphs; ++g) {
                std::cout << "Progress " << generated << "/" << vertices.size() * density.size() * graphs << std::endl;
                generate(v, e);
            }
        }
    }
}

