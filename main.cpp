//	 _______  __   __  _______  _______  _______  ___   __    _  _______    _______  _______  __   __  _______ 
//	|       ||  | |  ||       ||       ||       ||   | |  |  | ||       |  |       ||   _   ||  |_|  ||       |
//	|    ___||  | |  ||    ___||  _____||  _____||   | |   |_| ||    ___|  |    ___||  |_|  ||       ||    ___|
//	|   | __ |  |_|  ||   |___ | |_____ | |_____ |   | |       ||   | __   |   | __ |       ||       ||   |___ 
//	|   ||  ||       ||    ___||_____  ||_____  ||   | |  _    ||   ||  |  |   ||  ||       ||       ||    ___|
//	|   |_| ||       ||   |___  _____| | _____| ||   | | | |   ||   |_| |  |   |_| ||   _   || ||_|| ||   |___ 
//	|_______||_______||_______||_______||_______||___| |_|  |__||_______|  |_______||__| |__||_|   |_||_______|
//
//	Try to guess the right number in the least amount of guesses!
//
//	Sawyer Scheve
//	8/29/2024

#include <iostream>

int main () {
	// Variables.
	int num, input, guesses = 0;

	char again;

	bool gameIsRunning = true, hasWon = false;
	
	// Main loop.
	while (gameIsRunning) {
		// Randomize the number generator and set the number.
		srand(time(NULL));
		num = rand() % 101;

		std::cout << "I have generated a random number from 1-100. Please type a guess." << std::endl;
		
		// Gameplay loop. (ie: guessing and checking)
		while (!hasWon) {
			std::cin >> input;
			if (!std::cin.fail()) { // Handle wrong input. (Please... the extra credit)
				guesses++;
			
				// Check win condition.
				if (input != num) {
					input < num ? std::cout << "Too low." << std::endl : std::cout << "Too high." << std::endl;
				} else {
					hasWon = true;
				}
			} else {
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid response!" << std::endl;
			}
		}
		// Check if the player wants to play again. If not, exit program.
		std::cout << "You won in " << guesses << " guesses!" << std::endl; // !!BROKEN!!
		std::cout << "Play again? [y/N]" << std::endl;

		std::cin >> again;

		if (!std::cin.fail()) { // Handle wrong input.
			again = std::tolower(again, std::locale());

			if (again == 'y') {
				hasWon = false;
				guesses = 0;
			} else {
				gameIsRunning = false;
			}
		} else {
			std::cin.clear();
			std::cin.ignore(100, '\n');
			gameIsRunning = false;
		}
	}
}
