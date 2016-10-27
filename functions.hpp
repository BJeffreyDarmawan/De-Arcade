#incude<iostream>

#include "declare.hpp"

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
	
	cout << "Enter username "; cin >> userName;
	
	string temp;
	int igCurrency;
	ifstream fileIn;
	fileIn.open("Database.txt");
	
	while(fileIn >> temp)
	{
		if(temp == userName)
		{
			
			fileIn >> igCurrency;
			fileIn.close();
			break;
		}
	}
	
	
	
	
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
	int slot1, slot2, slot3;
	slot1 = rand() % 100;
	slot2 = rand() % 100;
	slot3 = rand() % 100;	
	int result1, result2, result3;
	int result[3];
	
	
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
		
		
		
/*	
	//can change into looped ifs
	if (slot1 >= 0 && slot1 <= 10)
	{
		result1 = 7;
		cout << " " << result1<< " | ";
		slot2 += 1;
		if (slot2 >= 0 && slot2 <= 10)
		{
			result2 = 7;
			cout << " " << result2<< " | ";
			slot3 += 2;
			if (slot3 >= 0 && slot3 <= 10)
			{
				result2 = 7;
				cout << " " << result2<< " | ";
			}
			else if 
		}
	}
	else if (
				
*/	
	
}


void gameX()
{
}
