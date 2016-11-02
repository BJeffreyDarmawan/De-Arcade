//
//this is a temporary file due to 'undefined reference' error when splitting files
//


#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

void log_In();
void defaultInterface();
void chooseGame();
void gameGuessTheNumber();
void gameSlots();
void gameX();


int main()
{
	log_In(); //logIn system hasn't  finished
	defaultInterface();
	chooseGame();

	return 0;
}

void defaultInterface()
{
	cout << "--------Welcome to DE ARCADE---------" << endl;
	cout << "You will experience tons of happiness" << endl;
	cout << "      by playing fun games here      " << endl;
	cout << "This game is made by Jeffrey Darmawan" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl;
	
}

//I haven't decided the functions types
void chooseGame () 
{
	bool flag;
	int userInput;
	
	do{
		flag = true;
		cout << "Please choose one of the following games: " << endl;
		cout << "1. Guess the Number " << endl;
		cout << "2. Slots " << endl;
		cout << "3. x game " << endl;
		cout << "Your choice : "; cin >> userInput;
		
		switch(userInput)
		{
			case 1: gameGuessTheNumber();
					  break;
			case 2: gameSlots();
					  break;
			case 3: gameX();
					  break;
			case 0: userInput = 0;
					  break;
			default: 
			{
				cout << "Please re-enter your choice" << endl;
				cout << "Press enter to continue " << endl;
				cin.ignore();
				cin.get();
				flag = false;
				system("CLS");
			}
		}
	}while(!flag);

}

void log_In()
{
	string userName;
	cout << "Enter username "; 
	cin >> userName;
	
	string temp;
	string getData[999];
	int igCurrency;
	fstream fileOp;
	fileOp.open("Database.txt", ios_base::in | ios_base::out | ios_base::app );
	int i = 0;
	bool flag = false;
	
	while(fileOp >> temp)
	{
		cout << temp;
		getData[i] = temp;

		if(temp == userName)
		{
			fileOp >> temp;
			igCurrency = atoi (temp.c_str());
			getData[i] = igCurrency;
			i++;
			flag = true;
		}
	}
	fileOp.close();

	if (flag == false)
	{
		fileOp.open("Database.txt", ios_base::in | ios_base::out | ios_base::app);
		fileOp << userName << "\n";
		igCurrency = 100;
		fileOp << igCurrency << "\n\n";
		fileOp.close();
	}
	
	cout << igCurrency;
	
	
/*	
	while(fileIn >> temp)
    {
        if(strTemp == strReplace){
            strTemp = strNew;
            //found = true;
        }
        strTemp += "\n";
        fileout << strTemp;
        //if(found) break;
    }
	
*/	
//	ifstream inputFile;
//	inputFile.open("Records.txt");
	/*
	will make something like::
	check from username data file,
	
	int i = 0, j = 0;
	while (i = 0 && inputFile)
	{
		if (inputFile == userName)
		{
			inputFile >> userName;
			inputFile >> inGameCurrency;
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
		::app
	
	*/
}


void gameGuessTheNumber()
{
	
	
	srand(time(NULL));
	int num1 = 0, num2 = 0, num3 = 0, digit1 = 0, digit2 = 0, digit3 = 0;
	bool condition = 1;
	int chances = 0;
	int bid, reward = 0, multiplier = 2;
	
	cout << "How much do you want to bet? "; cin >> bid;
	
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
			condition = 0;
		}
		else
		{
			cout << "You entered wrong number!! PLEASE TRY AGAIN!" << endl;
			chances++;
			if(chances >= 5)
			{
				cout << "You failed guessing the number " << endl;
				//I'll find a way that after passing this step, the program will go to 'do you want to play again' or 'choose game' or 'exit'
			}
		}
	}
	
	condition = 1;
	while (condition)
	{	
		cout << "Please guess the second digit : "; cin >> digit2;
		if (digit2 == num2)
		{
			condition = 0;	
		}
		else
		{
			cout << "You entered wrong number!! PLEASE TRY AGAIN!" << endl;
			chances++;
			if(chances >= 5)
			{
				cout << "You failed guessing the number " << endl;
			}
		}
	}
	
	condition = 1;	
	while (condition)
	{	
		cout << "Please guess the third digit : "; cin >> digit2;
		if (digit3 == num3)
		{
			condition = 0;
		}
		else
		{
			cout << "You entered wrong number!! PLEASE TRY AGAIN!" << endl;
			chances++;
			if(chances >= 5)
			{
				cout << "You failed guessing the number " << endl;
			}
		}
	}
	
	reward = multiplier * bid;
	cout << "Congratulations, you guessed the right number! " << endl;
	cout << "Here is your reward : " << reward << endl;
	
	
}

void gameSlots()
{
	srand(time(NULL));
	int slot[3] = {rand() % 100, rand() % 100, rand() % 100};
	int result[3];
	
	int bid, reward = 0, multiplier = 2;
	
	cout << "Welcome to the slots game!" << endl;
	cout << "How much do you want to bet? "; cin >> bid;
	//assume the common chances of the slots are: 10%, 30%, 30%, and 30%
	for (int i = 0; i <=2; i++)
	{
		if (slot[i] >=0 && slot[i] <= 10)
		{
			result[i] = 7;
			cout << " " << result[i]<< " | ";
		}
		else if (slot[i] > 10 && slot[i] <=39)
		{
			result[i] = 1;
			cout << " " << result[i]<< " | ";
		}
		else if (slot[i] > 40 && slot[i] <=69)
		{
			result[i] = 2;
			cout << " " << result[i]<< " | ";
		}
		else if (slot[i] > 70 && slot[i] <=99)
		{
			result[i] = 3;
			cout << " " << result[i]<< " | ";
		}
	}
	
	if(result[0] == result[1] && result[1] == result[2])
	{
		if (result[0] == 7)
		{
			reward = bid * 10;
			cout << "Congratulations! You won: " << reward << endl;
		}
		else if (result[0] == 1 || result[0] == 2 || result[0] == 3)
		{
			reward = bid * 3;
			cout << "Congratulations! You won: " << reward << endl;
		}
	}	
	else if (result[0] == result[1] || result[0] == result[2] || result[1] == result[2])
	{
		if (result[0] == 7 || result[1] == 0)
		{
			reward = 0;
			cout << "Sorry you did not win anything" << endl;
		}
		else 
		{
			reward = bid + 10;
			cout << "Congratulations you won " << reward << endl;
		}
	}
	else cout << "Sorry you did not win anything" << endl;
		
	
}


void gameX()
{
	int numHorses, input, multiplier;
	
	cout << "Welcome to the Fast-Forwarded Horcerace betting!"<< endl;
	cout << "There are 10 horses out there and you are allowed to bet at the maximum of 3 horses" << endl <<
	"How many horses do you want to bet?"; cin >> numHorses;
	
	if(numHorses == 1)
		multiplier = 7;
	else if(numHorses == 2)
		multiplier = 3;
	else if(numHorses == 3)
		multiplier = 2;
	
	int tempWhichHorse[numHorses];
	int tempHowMuch[numHorses];
	
	for (int i = 0; i < numHorses; i++)
	{
		cout <<"Which horse do you want to bet on? (1-10) "; cin >> input;
		tempWhichHorse[i] = input;
		cout << "How much do you want to bet? "; cin >> input;
		tempHowMuch[i] = input;
		cout << "Thank you" << endl;
	}
	
	
	int winnerHorse = rand() % 10+1;
	
	for(int i = 0; i < numHorses; i++)
	{
		if(tempWhichHorse[i] == winnerHorse)
		{
			int reward = tempHowMuch[i] * multiplier;
			cout << "Congratulations, you won: " << reward;
			break;
		}
	}
	
	
}







