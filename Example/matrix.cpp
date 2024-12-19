#include <iostream>
#include <vector>
#include <string>

int main() {
    // Create a 4x4 string matrix
    std::vector<std::vector<std::string>> matrix = {
        {"", "", "", ""},
        {"", "", "", ""},
        {"", "", "", ""},
        {"", "", "", ""}
    };

    std::vector<std::vector<std::string>> matrix1 = {
        {"c01", "0", "s00", "0"},
        {"s00", "0", "-c00", "0"},
        {"0", "1", "0", "a1"},
        {"0", "0", "0", "0"}
    };

    std::vector<std::vector<std::string>> matrix2 = {
        {"c01", "-s01", "0", "-a2s01"},
        {"s01", "c01", "0", "a2c01"},
        {"0", "0", "1", "0"},
        {"0", "0", "0", "1"}
    };

    for(int i = 0;i < 4;i++) {
        for(int j = 0;j < 4;j++) {
            for(int k = 0;k < 4;k++) {
                matrix[i][j] += matrix1[k][i] + matrix2[j][k];
            }
        }
    }
    // Print the matrix
    std::cout << "4x4 String Matrix:" << std::endl;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
