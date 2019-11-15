//
// Created by adam on 10.11.2019.
//

#include "Generator.h"
#include <string>

int main(int argc, char **argv) {
    Generator generator;
    generator.indexFirstGraph = std::stoi(argv[1]);
    generator.generateGraphs();
}