//
// Created by adam on 10.11.2019.
//

#ifndef CPP_GENERATOR_H
#define CPP_GENERATOR_H


#include <memory>
#include <set>

class Generator {

    uint generated = 0;

    void generate(uint v, uint e);

    void saveToFile(uint v, uint e, const std::set<std::pair<uint, uint>>& edges);
public:
    void generateGraphs();
};


#endif //CPP_GENERATOR_H
