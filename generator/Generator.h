//
// Created by adam on 10.11.2019.
//

#ifndef CPP_GENERATOR_H
#define CPP_GENERATOR_H


#include <memory>
#include <set>
#include <vector>
#include <random>


struct Generator {
    const std::vector<uint> vertices = {500, 1000, 1500, 2000, 2500};
    const std::vector<float> density = {0.01, 0.05, 0.1, 0.3, 0.6};
    const uint graphs = 10;
    const std::string base_path = "examples/";

    std::random_device rd;
    uint generated = 0;
    uint indexFirstGraph;

    void generate(uint v, uint e, float d, uint g);

    void saveToFile(uint v, uint e, float d, const std::set<std::pair<uint, uint>> &edges, uint g);

public:
    void generateGraphs();
};


#endif //CPP_GENERATOR_H