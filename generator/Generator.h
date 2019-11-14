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
    const std::vector<uint> vertices = {1000, 2500, 5000, 7500, 10000};
    const std::vector<float> density = {0.02, 0.1, 0.3, 0.6};
    const uint graphs = 2;
//    const uint graphs = 1000; uncomment it later
    const std::string base_path = "../../examples/";
    std::random_device rd;
    uint generated = 0;

    void generate(uint v, uint e, float d, uint it);

    void saveToFile(uint v, uint e, float d, const std::set<std::pair<uint, uint>> &edges, uint it);

public:
    void generateGraphs();
};


#endif //CPP_GENERATOR_H