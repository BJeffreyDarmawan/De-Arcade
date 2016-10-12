//
//Draft of De Arcade
//
//by Jeffrey Darmawan
//
//draft inside Draft...
//


#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;





string userName;
char userInput;

int main()
{
/*
main function will call functions work like :

defaultInterface();
logIn();

do 
{
	chooseGame
	{
		switchcase 
		{
			loadGame -> play game
			{
				playGame 
				recordData
			}
		}
		choose other game / log out / exit
	}
} while (userInput != 0) 



*/
}

void defaultInterface()
{
	cout << "--------Welcome to DE ARCADE---------" << endl;
	cout << "You will experience tons of happiness" << endl;
	cout << "      by playing fun games here      " << endl;
	cout << "This game is made by Jeffrey Darmawan" << endl;
	
}



//I haven't decided the functions types
void chooseGame () 
{

/*
	cout << "Please choose one of the following games: " << endl;
	cout << "1. Guess the Number " << endl;
	cout << "2. Slots " << endl;
	cout << "3. x game " << endl;
	switch(userInput)
	{
		case '1': guessTheNumber();	
				  break;
		case '2': gameSlots();
				  break;
		case '3': gameX();
				  break;
		case '0': userInput = 0;
				  break;
		default: cout << "Please re-enter your choice" << endl;
	
	}
*/

}

void logIn()
{
	cout << "Enter username "; cin >> userName;
	/*
	will make something like::
	check from username data file,
	
	int i = 0, j = 0;
	while (i = 0 && inputFile)
	{
		if (inputFile == userName)
		{
			i = 1;
		}
		j++
	}
	
	
	if (i = 1)
		load userName
		load in-game currency
	else
		create / record as new userName
		add in-game currency by 100
	
	*/
}


void gameGuessTheNumber()
{
	
	/*
	srand(time(NULL));
	int num1 = 0, num2 = 0, num3 = 0;
	bool condition = 0;
	
	//each digit can't be same as the other
	while (num1 == num2 || num2 == num3 || num1 == num3)
	{
		num1 = rand() % 10; //one digit random number
		num2 = rand() % 10;
		num3 = rand() % 10;
	}
	
	while (condition)
	{	
		cout << "Please guess the first digit : "; cin >> digit1;
		if (digit1 == num1)
		{
			condition = 1;
		}
	
	}
	
	condition = 0;
	while (condition)
	{	
		cout << "Please guess the second digit : "; cin >> digit2;
		if (digit2 == num2)
		{
			condition = 1;
		}
	
	}
	
	condition = 0;	
	while (condition)
	{	
		cout << "Please guess the third digit : "; cin >> digit2;
		if (digit3 == num3)
		{
			condition = 1;
		}
	
	}
	
	cout << "Congratulations, you guessed the right number! " << endl;
	cout << "Here is your reward : " << reward << endl;
	
	
	*/
	
	
	
}





