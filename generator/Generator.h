//
// Created by adam on 10.11.2019.
//

#ifndef CPP_GENERATOR_H
#define CPP_GENERATOR_H


#include <memory>
#include <set>
#include <vector>
#include <random>


class Generator {
    const std::vector<uint> vertices = {10, 100, 1000};
    const std::vector<float> density = {0.25, 0.5, 0.75};
    const uint graphs = 100;
    const std::string base_path = "../../examples/generate/in";
    std::string path;
    std::random_device rd;
    uint generated = 0;

    void generate(uint v, uint e);

    void saveToFile(uint v, uint e, const std::set<std::pair<uint, uint>> &edges);

public:
    void generateGraphs();
};


#endif //CPP_GENERATOR_H
