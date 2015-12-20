#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cstdlib>

int main(int argc, char** argv) {

    if (argc != 5) {
        std::cerr << "Usage: Nx Ny Nz filename" << std::endl;
        return -1;
    }

    const size_t Nx = atoi(argv[1]);
    const size_t Ny = atoi(argv[2]);
    const size_t Nz = atoi(argv[3]);
    const char* filename = argv[4];

    std::ifstream file;
    file.open(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error while opening geo file" << std::endl;
        return -1;
    }

    std::vector<unsigned char> geo;
    geo.resize(Nx * Ny * Nz);
    file.read((char *)&geo[0], Nx * Ny * Nz * sizeof(char));

    std::cout << "Point g[x=45, y=23, z=17] = " << int(geo[45 + 23 * Nx + 17 * Nx * Ny]) << std::endl;

    return 0;
}
