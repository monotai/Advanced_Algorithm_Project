#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    // Open the input file
    std::ifstream infile("node.xlsx");

    // Check if the file is open
    if (!infile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> data;  // Vector to collect the processed data
    std::string line;

    while (std::getline(infile, line)) {
        std::stringstream ss(line);  // Use stringstream to process each line
        std::string word;
        std::vector<int> row;  // Temporary vector to store numbers of the current line
        int count = 0;

        // Read each word, remove commas, and collect three numbers
        while (std::getline(ss, word, ',')) {
            // Remove any leading or trailing spaces
            word.erase(0, word.find_first_not_of(' '));
            word.erase(word.find_last_not_of(' ') + 1);

            // Convert the word to an integer and add to the row vector
            row.push_back(std::stoi(word));
            count++;
            if (count == 3) {
                break;  // Stop after collecting three numbers
            }
        }

        // Add the row to the main data vector
        data.push_back(row);

        // Output the row to the terminal
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    infile.close();

    // Example: Accessing collected data from the vector
    std::cout << "\nCollected Data in Vector:" << std::endl;
    for (const auto& row : data) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
