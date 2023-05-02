#include <iostream>
#include <fstream>
#include <string>


const std::string high_scores_file = "game_high_scores.txt";

int get_random_int_value(int max_val) {
    std::srand(std::time(nullptr));
    const int random_value = std::rand() % max_val;    
    return random_value;
}

int add_to_high_scores_table(const std::string &data) {
    
    std::ofstream out_file{high_scores_file, std::ios_base::app};
    if (!out_file.is_open()) {
        std::cout << "Failed to open file for write: " << high_scores_file << "!" << std::endl;
        return -1;
    }
    out_file << data << std::endl;
    return 0;
}

int show_high_scores_table() {

    std::ifstream hs_file{high_scores_file};
    if (!hs_file.is_open()) {
        std::cout << "Failed to open file for read: " << high_scores_file << "!" << std::endl;
        return -1;
    }

    std::cout << "####################" << std::endl;
    std::cout << " High scores table: " << std::endl;

    std::string username;
    int attempts = 0;
    while (true) {
        hs_file >> username;
        hs_file >> attempts;
        hs_file.ignore();

        if (hs_file.fail()) {
            break;
        }

        std::cout << username << '\t' << attempts << std::endl;
    }
    return 0;
}