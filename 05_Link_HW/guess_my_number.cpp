#include <iostream>
#include <string>

#include "guess_my_num_utils.h"

int max_val = 100;

int main(int argc, char *argv[]) {
    if (argc == 2) {
        std::string param = argv[1];
        if (param == "--table") {
            show_high_scores_table();  
            return 0;
        } else {
            std::cout << "Incorrect parametr: " << param << std::endl;
            return -1;
        }
    } else if (argc == 3) {
        std::string param1 = argv[1];
        if (param1 == "--max") {
            std::string param2 = argv[2];
            int param2_int = std::stoi(param2);
            max_val = param2_int;
        } else {
            std::cout << "Incorrect parametr: " << param1 << std::endl;
            return -1;
        }
    } else if (argc > 3) {
        std::cout << "Incorrect parametrs!" << std::endl;
        return -1;
    }

    std::string name;
    int secret;
    int user_guess;
    int attempts = 0;
    std::string result;

    std::cout << "Enter Your name: ";
    std::cin >> name;
	if (std::cin.fail()) {
		std::cout << "Bad value!" << std::endl;
		return -1;
	}
    
    secret = get_random_int_value(max_val);
    std::cout << "Your secret: " << secret << std::endl;
    
    std::cout << "Hi " << name;
    std::cout << "! I made a number from 0 to "  << max_val << " (inclusive).\n";
    std::cout << "Please";
    while (true)
    {

        std::cout << ", enter your guess: ";
        std::cin >> user_guess;
        if (std::cin.fail()) {
            std::cout << "Bad value!" << std::endl;
            return -1;
        }
        attempts++;

        if (user_guess < secret)
        {
            std::cout << "Greater than " << user_guess;
        } else if (user_guess > secret)
        {
            std::cout << "Less than " << user_guess;
        } else if (user_guess == secret)
        {
            std::cout << "You guessed! Attempts = " << attempts << std::endl;
            break;
        } else {            
            break;
        }
    }
    result = name + ' ' + std::to_string(attempts);
    add_to_high_scores_table(result);
    show_high_scores_table();    
}
