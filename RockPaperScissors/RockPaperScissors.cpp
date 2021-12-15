#include <iostream>
#include <cstdlib>
#include <ctime>

//Initialize Variables
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';
char repeater;
int plrWinCount;
int compWinCount;

void clear_console() {
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

//Randomizer
char getComputerOption() {
	srand(time(0));
	// Random Number
	int num = rand() % 3 + 1;
	
	if (num == 1)
		return 'r';
	if (num == 2)
		return 'p';
	if (num == 3)
		return 's';
}

//Display User Options
char getUserOption() {
	char choice;
	std::cout << "Rock, Paper, Scissors\n";
	std::cout << "_____________________\n";
	std::cout << "(r) for Rock\n";
	std::cout << "(p) for Paper\n";
	std::cout << "(s) for Scissors\n";
	std::cout << "Enter your choice (r/p/s): ";
	std::cin >> choice;
 	
	//Error Check in case user entered an invalid option
	while (choice != 'r' && choice != 'p' && choice != 's') {
		std::cout << "Invalid option, please try again" << std::endl;
		std::cout << "(r) for Rock\n";
		std::cout << "(p) for Paper\n";
		std::cout << "(s) for Scissors\n";
		std::cin >> choice;
	}

	return choice;
}

//Show what you and the computer selected
void showSelectedOption (char option) {
	if (option == 'r') std::cout << "Rock" << std::endl;
	if (option == 'p') std::cout << "Paper" << std::endl;
	if (option == 's') std::cout << "Scissors" << std::endl;
}

//Determines the winner of the round (or not if it's a tie)
void chooseWinner (char userChoice, char computerChoice) {
	if (userChoice == ROCK && computerChoice == PAPER) {
		std::cout << "Computer Wins: Rock beats Paper." << std::endl;
		compWinCount = compWinCount + 1;
	}
	else if (userChoice == PAPER && computerChoice == SCISSORS) {
		std::cout << "Computer Wins: Scissors beats Paper." << std::endl;
		compWinCount = compWinCount + 1;
	}
	else if (userChoice == SCISSORS && computerChoice == ROCK) {
		std::cout << "Computer Wins: Rock bests Scissors." << std::endl;
		compWinCount = compWinCount + 1;
	}
	else if (userChoice == ROCK && computerChoice == SCISSORS) {
		std::cout << "You Win: Rock beats Scissors." << std::endl;
		plrWinCount = plrWinCount + 1;
	}
	else if (userChoice == PAPER && computerChoice == ROCK) {
		std::cout << "You Win: Paper beats Rock." << std::endl;
		plrWinCount = plrWinCount + 1;
	}
	else if (userChoice == SCISSORS && computerChoice == PAPER) {
		std::cout << "You Win: Scissors beats Paper." << std::endl;
		plrWinCount = plrWinCount + 1;
	}
	else {
		std::cout << "Tie Game." << std::endl;
	}
}

//Give user option to play another round
void playAgain() {
	std::cout << "Continue Playing? (y/n) ";
	std::cin >> repeater;
	if (repeater == 'y') {
		clear_console();
	}
}

//Display Score
void winCount() {
	
	std::cout << "User: " << plrWinCount << " wins" << std::endl;
	std::cout << "Computer: " << compWinCount << " wins" << std::endl;
}

int main() {
	
	do {
		char userChoice;
		char computerChoice;
		do {	
			userChoice = getUserOption();
			std::cout << "Your choice is: " << std::endl;
			showSelectedOption(userChoice);

			std::cout << "Computer's choice:" << std::endl;
			computerChoice = getComputerOption();
			showSelectedOption(computerChoice);

			chooseWinner(userChoice, computerChoice);
			winCount();
		} while (userChoice == computerChoice);
	playAgain();
	} while (repeater != 'n');
	return 0;
}
