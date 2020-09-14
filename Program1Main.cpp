#include <iostream>
#include <ctime>
#include <random>
using namespace std;


//Returns a random integer between 1 and 6
int RollDie(){
	int roll = (rand() % 6) + 1;
	return roll;
}


//Finds the largest possible arrangement of rolls from two rolls
int AddDice(int firstRoll, int secondRoll) {
	int roll = -1;
	//Checks for the highest roll, then puts it in the ten's place
	if (secondRoll > firstRoll) {
		roll = (secondRoll * 10) + firstRoll;
	}
	else {
		roll = (firstRoll * 10) + secondRoll;
	}
	return roll;
}


//Takes an y or n from the user, and outputs either true or false
bool promptUser() {
	char userInput;
	bool waitingForUser = true;
	bool result;
	cout << "Try again? y/n ";

	//Loop runs while waiting or input is invalid
	while (waitingForUser) {
		cin >> userInput;
		switch (userInput) {
		case 'N':
		case 'n':
			result = false;
			waitingForUser = false;
			break;
		case 'Y':
		case 'y':
			result = true;
			waitingForUser = false;
			break;
		default:
			cout << "Invalid Input, please try again" << endl;
			break;
		}
	}
	return result;
}


int main() {
	//Initializing Variables
	srand(time(NULL));
	bool exit = false;
	int userWins = 0;
	int computerWins = 0;
	int topNumber = 0;

	//Main Game Loop, runs while exit is false
	while (!exit) {

		//Setting user rolls and number
		int userRoll1 = RollDie();
		int userRoll2 = RollDie();
		int userNumber = AddDice(userRoll1, userRoll2);
		cout << "Rolling 2 dice for human: " << endl;
		cout << "Rolled " << userRoll1 << " and " << userRoll2 << ", making " << userNumber << "." << endl;
		cout << endl;

		//Checks if user has lost, if not the game continues
		if (topNumber >= userNumber) {
			//Game end conditions
			computerWins++;
			cout << "Too bad, the Computer Wins!" << endl;
			cout << "The current score is - Human: " << userWins << ", Computer: " << computerWins << endl;
			exit = !promptUser();
			topNumber = 0;

			//Exits game if exit is true, else continues
			if (exit) {
				break;
			}
			else {
				continue;
			}
		}
		else {
			topNumber = userNumber;
			cout << topNumber << " is the number to beat!" << endl;
		}
		
		//Setting computer rolls and number
		int computerRoll1 = RollDie();
		int computerRoll2 = RollDie();
		int computerNumber = AddDice(computerRoll1, computerRoll2);
		cout << "Rolling 2 dice for computer: " << endl;
		cout << "Rolled " << computerRoll1 << " and " << computerRoll2 << ", making " << computerNumber << "." << endl;
		cout << endl;

		//Checks if computer has lost, if not the game continues
		if (topNumber >= computerNumber) {
			//Game end conditions
			userWins++;
			cout << "User Wins!" << endl;
			cout << "The current score is - Human: " << userWins << ", Computer: " << computerWins << endl;
			exit = !promptUser();
			topNumber = 0;
		}
		else {
			topNumber = computerNumber;
			cout << topNumber << " is the number to beat!" << endl;
		}
	}
}