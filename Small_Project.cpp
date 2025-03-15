#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;

// asks the user to enter the number of rounds
int numOfRounds(string message) {
	cout << message;
	int roundsNumber;
	cin >> roundsNumber;
	cout << "\n";
	return roundsNumber;
}

// asks the user to enter the choice (rock or paper or scissors)
int playerChoice(string message) {
	cout << message;
	int choice;
	cin >> choice;
	cout << "------------------------------\n";
	return choice;
}

// generates a random number for the computer
int randomNumber(int from, int to) {
	srand(time(0));
	return rand() % (to - from) + from;
}

// asks the user to enter the choice(rock or paper or scissors) again in case the choice was invalid input
int enterAgain() {
	
	int playerChoice;
	do {
		cout << "That is wrong answer...Try again : ";
		cin >> playerChoice;
	} while (playerChoice != 1 && playerChoice != 2 && playerChoice != 3);
	cout << endl;
	return playerChoice;
}

// compare the choices between the user(player) and the computer
void compareChoices(int computerChoice, int playerChoice , int &numOfPwins , int &numOfCwins , int &numOfDraws) {
	if (computerChoice == 1) {
		switch (playerChoice) {
		case 1:
			cout << "Player choice :" << playerChoice << endl;
			cout << "Computer choice :" << computerChoice << endl;
			cout << "Round winner : [No winner]\n";
			system("color 6F");
			cout << "------------------------------\n";
			numOfDraws++;
			break;
		case 2:
			cout << "Player choice :" << playerChoice << endl;
			cout << "Computer choice :" << computerChoice << endl;
			cout << "Round winner : [Player]\n";
			system("color 2F");
			cout << "------------------------------\n";
			numOfPwins++;
			break;
		case 3:
			cout << "Player choice :" << playerChoice << endl;
			cout << "Computer choice :" << computerChoice << endl;
			cout << "Round winner : [Computer]\n";
			system("color 4F");
			cout << "------------------------------\n";
			numOfCwins++;
			break;
		default :
			//cout << "That is wrong answer...Try again : ";
			compareChoices(computerChoice, enterAgain() , numOfPwins, numOfCwins , numOfDraws);
		}
	}
	else if (computerChoice == 2) {
		switch (playerChoice) {
		case 1:
			cout << "Player choice :" << playerChoice << endl;
			cout << "Computer choice :" << computerChoice << endl;
			cout << "Round winner : [Computer]\n";
			system("color 4F");
			cout << "------------------------------\n";
			numOfCwins++;
			break;
		case 2:
			cout << "Player choice :" << playerChoice << endl;
			cout << "Computer choice :" << computerChoice << endl;
			cout << "Round winner : [No winner]\n";
			system("color 6F");
			cout << "------------------------------\n";
			numOfDraws++;
			break;
		case 3:
			cout << "Player choice :" << playerChoice << endl;
			cout << "Computer choice :" << computerChoice << endl;
			cout << "Round winner : [Player]\n";
			system("color 2F");
			cout << "------------------------------\n";
			numOfPwins++;
			break;
		default:
			//cout << "That is wrong answer...Try again : ";
			compareChoices(computerChoice, enterAgain() , numOfPwins, numOfCwins , numOfDraws);
		}
	}else {
		switch (playerChoice) {
		case 1:
			cout << "Player choice :" << playerChoice << endl;
			cout << "Computer choice :" << computerChoice << endl;
			cout << "Round winner : [Player]\n";
			system("color 2F");
			cout << "------------------------------\n";
			numOfPwins++;
			break;
		case 2:
			cout << "Player choice :" << playerChoice << endl;
			cout << "Computer choice :" << computerChoice << endl;
			cout << "Round winner : [Computer]\n";
			system("color 4F");
			cout << "------------------------------\n";
			numOfCwins++;
			break;
		case 3:
			cout << "Player choice :" << playerChoice << endl;
			cout << "Player choice :" << computerChoice << endl;
			cout << "Round winner : [No winner]\n";
			system("color 6F");
			cout << "------------------------------\n\n";
			numOfDraws++;
			break;
		default:
			//cout << "That is wrong answer...Try again : ";
			compareChoices(computerChoice, enterAgain() , numOfPwins, numOfCwins , numOfDraws);
		}
	}
}

// print the result and asks if the user want to play again or not
char result(int numOfPwins, int numOfCwins , int numOfDraws , int roundsNumber) {
	cout << "\t\t\t\t  _________________________________________________________\n\n";
	cout << "\t\t\t\t\t\t* * * *G A M E   O V E R* * * * \n";
	cout << "\t\t\t\t  _________________________________________________________\n";
	cout << "\t\t\t\t  _________________[ Game Results ]________________________\n\n";
	cout << "\t\t\t\t  Game Rounds : " << roundsNumber << "\n";
	cout << "\t\t\t\t  Player wins : " << numOfPwins << "\n";
	cout << "\t\t\t\t  Computer wins : " << numOfCwins << "\n";
	cout << "\t\t\t\t  Draw times : " << numOfDraws << "\n";
	
	if (numOfPwins > numOfCwins) {
		cout << "\t\t\t\t  Final Winner : [Player]\n";
		system("color 2F");
	}
	else if (numOfPwins < numOfCwins) {
		cout << "\t\t\t\t  Final Winner : [Computer]\n";
		system("color 4F");
	}
	else {
		cout << "\t\t\t\t  Final Winner : [DRAW]\n";
		system("color 6F");
	}

	cout << "\t\t\t\t  =========================================================\n";
	cout << "\t\t\t\t  Do you want to play again(y/n) ? ";
	char choice;
	cin >> choice;
	return choice;

}

// the menu of all of the above functions
void startingTheGame() {
	int roundsNumber = numOfRounds("How many rounds you want to play ? ");
	int choice;
	int computerRandomChoice;
	int numOfPwins = 0, numOfCwins = 0, numOfDraws = 0;
	for (int i = 0; i < roundsNumber; i++)
	{
		cout << "(((((((((((((((Round [" << (i + 1) << "] begins)))))))))))))))\n\n";
		computerRandomChoice = rand() % 3 + 1;
		choice = playerChoice("Your choice : [1]:Rock, [2]:Paper, [3]:Scissors ? ");
		compareChoices(computerRandomChoice, choice, numOfPwins, numOfCwins, numOfDraws);
	}
	cout << endl;
	char resultChoice = result(numOfPwins, numOfCwins, numOfDraws, roundsNumber);
	
	while (true) {
		if (resultChoice == 'y') {
			cout << "\t\t\t\t  =========================================================\n\n";
			system("color 0F");
			startingTheGame();
			break;
		}
		else if (resultChoice == 'n') {
			cout << "\t\t\t\t  EXITING THE GAME!!!\n";
			cout << "\t\t\t\t  =========================================================\n\n";
			system("color 0F");
			break;
		}
		else {
			cout << "\t\t\t\t  Wrong choice...Try again : ";
			cin >> resultChoice;
		}
	} 
}


int main() {
	startingTheGame();
	return 0;
}
