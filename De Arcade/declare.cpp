//
//File where functions' body are written
//
//include header file 
#include"declare.hpp"

string temporaryAllFile[999]; //stores all content of Database.txt file
int i = 0; //total number of lines on the txt file

	//member functions in UserData class
	UserData::UserData(){
		this->userName = "";
		this->counter = 0;
		this->igCurrency = 0;
		}
	
	void UserData::setUserName(string userName)
	{
		this->userName = userName;
	}
	void UserData::setCounter(int counter)
	{
		this->counter = counter;
	}
	void UserData::setIGCurrency(int igCurrency)
	{
		this->igCurrency = igCurrency;
	}
	
	string UserData::getUserName()
	{
		return this->userName;
	}
	int UserData::getCounter()
	{
		return this->counter;
	}
	int UserData::getIGCurrency()
	{
		return this->igCurrency;
	}
	
	void UserData::saveGame()
	{
		//save game by rewriting the file
		fstream fileOp;
		fileOp.open("Database.txt", ios_base::in | ios_base::out);
		temporaryAllFile[counter-1] = userName; //in the array, userName is located before the igCurrency
		temporaryAllFile[counter] = to_string(igCurrency);
		
		for(int j = 0; j < i; j++)
		{
			fileOp << temporaryAllFile[j] << "\n";
			j++;
			fileOp << temporaryAllFile[j] << "\n\n";
		}
		fileOp.close();
	}
	void UserData::checkIGC()
	{
		cout << "In-game currency balance: " << igCurrency << endl;
	}
	void UserData::checkUserName()
	{
		cout << "UserName: " << userName << endl;
	}
//global functions
void defaultInterface()
{
	cout << "--------Welcome to DE ARCADE---------" << endl;
	cout << "You will experience tons of happiness" << endl;
	cout << "      by playing fun games here      " << endl;
	cout << "This game is made by Jeffrey Darmawan" << endl;
	cout << "-------------------------------------" << endl;
	cout << endl;
}

void playerInfo(UserData &player)
{
	int userInput;
	system("CLS");
	cout << "--- Your Data ------------------------" << endl;
	player.checkUserName();
	player.checkIGC();
	cout << endl << "1. Return to choose game" << endl;
	cout << "0. Exit" << endl;
	cin >> userInput;
	switch(userInput)
	{
		case 1: chooseGame(player);
				break;
		case 0: break;
		default: break;
	}
}

//I haven't decided the functions types
void chooseGame (UserData &player) 
{
	bool flag;
	int userInput;
	system("CLS");
	do{
		defaultInterface();
		flag = true;
		cout << "Please choose one of the following games: " << endl;
		cout << "1. Guess the Number " << endl;
		cout << "2. Slots " << endl;
		cout << "3. Horse Race Betting " << endl;
		cout << "8. Top Up Credits" << endl;
		cout << "9. Player Info" << endl;
		cout << "0. Exit game " << endl;
		cout << "Your choice : "; cin >> userInput;
		
		switch(userInput)
		{
			case 1: gameGuessTheNumber(player);
					  break;
			case 2: gameSlots(player);
					  break;
			case 3: gameHorseRace(player);
					  break;
			case 8: topUpCredits(player);
					  break;
			case 9: {
						playerInfo(player);
						break;
					}
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

void log_In(UserData &player)
{
	string userName;
	cout << "Enter username "; 
	cin >> userName;
	
	string temp;
	int igCurrency;
	fstream fileOp;
	fileOp.open("Database.txt", ios_base::in | ios_base::out | ios_base::app );
	bool flag = false;

	while(fileOp >> temp)
	{
		temporaryAllFile[i] = temp;
		i++;
		//if userName exists load igCurrency
		if(temp == userName)         
		{
			fileOp >> temp;
			player.setCounter(i);
			igCurrency = atoi (temp.c_str());
			temporaryAllFile[i] = temp;
			i++;
			flag = true;
			cout << "Loading data..." << endl;
		}
	}
	fileOp.close();
	
	//if userName does not exist,
	//create new userName, write it on the file,
	//and initialize igCurrency as 100
	if (flag == false)
	{
		fileOp.open("Database.txt", ios_base::in | ios_base::out | ios_base::app);
		fileOp << userName << "\n";
		igCurrency = 100;
		fileOp << igCurrency << "\n\n";
		fileOp.close();
	
		player.setCounter(i+1);	
		i+=2;
		cout << "Creating New Username..." << endl;
	}
	
	//assign userName and igCurrency to player class
	player.setUserName(userName);
	player.setIGCurrency(igCurrency);
	
	cout << "--- Your Data ------------------------" << endl;
	player.checkUserName();
	player.checkIGC();
	cin.ignore();
	cin.get();
}


void gameGuessTheNumber(UserData &player)
{
	system("CLS");
	cout << "---------------------------------------" << endl;
	cout << "---------- Guess the Number -----------" << endl;
	cout << "---------------------------------------" << endl;
	try{
		//declaration of necessary variables
		srand(time(NULL));
		int num1 = 0, num2 = 0, num3 = 0, digit;
		bool condition = 1;
		int chances = 0;
		int bid, reward = 0, multiplier = 3;
		
		cout << "How much do you want to bet? "; cin >> bid;
		player.setIGCurrency(player.getIGCurrency() - bid);
		//each digit can't be same as the other
		while (num1 == num2 || num2 == num3 || num1 == num3)
		{
			num1 = rand() % 10; //one digit random number
			num2 = rand() % 10;
			num3 = rand() % 10;
		}
		
		while (condition)
		{	
			cout << "Please guess the first digit : "; cin >> digit;
			if (digit == num1)
			{
				condition = 0; //exit loop
			}
			else if(digit == num2 || digit == num3)
			{
				cout << "You entered a correct number but at the wrong position" << endl;
				cout << "PLEASE TRY AGAIN!" << endl;
				chances++;
				if(chances >= 5)
				{
					cout << "You failed guessing the number " << endl;
					string failGuess;
					throw failGuess;
				}
			}
			else
			{
				cout << "You entered wrong number!! PLEASE TRY AGAIN!" << endl;
				chances++;
				if(chances >= 5)
				{
					cout << "You failed guessing the number " << endl;
					string failGuess;
					throw failGuess;
				}
			}
		}
		condition = 1;
		while (condition)
		{	
			cout << "Please guess the second digit : "; cin >> digit;
			if (digit == num2)
			{
				condition = 0; //exit loop
			}
			else if(digit == num1 || digit == num3)
			{
				cout << "You entered a correct number but at the wrong position" << endl;
				cout << "PLEASE TRY AGAIN!" << endl;
				chances++;
				if(chances >= 5)
				{
					cout << "You failed guessing the number " << endl;
					string failGuess;
					throw failGuess;
				}
			}
			else
			{
				cout << "You entered wrong number!! PLEASE TRY AGAIN!" << endl;
				chances++;
				if(chances >= 5)
				{
					cout << "You failed guessing the number " << endl;
					string failGuess;
					throw failGuess;
				}
			}
		}
		
		condition = 1;	
		while (condition)
		{	
			cout << "Please guess the third digit : "; cin >> digit;
			if (digit == num3)
			{
				condition = 0; //exit loop
			}
			else if(digit == num2 || digit == num1)
			{
				cout << "You entered a correct number but at the wrong position" << endl;
				cout << "PLEASE TRY AGAIN!" << endl;
				chances++;
				if(chances >= 5)
				{
					cout << "You failed guessing the number " << endl;
					string failGuess;
					throw failGuess;
				}
			}
			else
			{
				cout << "You entered wrong number!! PLEASE TRY AGAIN!" << endl;
				chances++;
				if(chances >= 5)
				{
					cout << "You failed guessing the number " << endl;
					string failGuess;
					throw failGuess;
				}
			}
		} //loop ends and earn reward 
		
		reward = multiplier * bid;
		cout << "Congratulations, you guessed the right numbers! " << endl;
		cout << "Here is your reward : " << reward << endl;
		
		player.setIGCurrency(player.getIGCurrency() + reward);
		player.saveGame();
		chooseGame(player);
	}
	catch(string failGuess)
	{
		cout << "You failed this game, please proceed to return to choose game." << endl;
		player.saveGame();
		cin.ignore();
		cin.get();
		chooseGame(player);
	}
}

void gameSlots(UserData &player)
{
	system("CLS");
	cout << "----------------------------------------" << endl;
	cout << "---------------- SLOTS -----------------" << endl;
	cout << "----------------------------------------" << endl;
	srand(time(NULL));
	int slot[3] = {rand() % 100, rand() % 100, rand() % 100};
	int result[3];
	
	int bid, reward = 0, multiplier = 2;
	
	cout << "Welcome to the slots game!" << endl;
	do{
		cout << "How much do you want to bet(min. 10)? "; cin >> bid;
		if (bid < 10)
			cout << "Please re-enter bet======================" << endl;
	}while (bid<10);
		player.setIGCurrency(player.getIGCurrency() - bid);
		cout << player.getIGCurrency();
	
	//assume the common chances of the slots are: 10%, 30%, 30%, and 30%
	for (int i = 0; i <=2; i++)
	{
		if (slot[i] >=0 && slot[i] <= 9)
		{
			result[i] = 7;
			cout << " " << result[i]<< " | ";
		}
		else if (slot[i] > 9 && slot[i] <=39)
		{
			result[i] = 1;
			cout << " " << result[i]<< " | ";
		}
		else if (slot[i] > 39 && slot[i] <=69)
		{
			result[i] = 2;
			cout << " " << result[i]<< " | ";
		}
		else if (slot[i] > 69 && slot[i] <=99)
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
			player.setIGCurrency(player.getIGCurrency() + reward);
			player.saveGame();
			cout << "Please proceed to return to Choose Game Menu..";
			cin.ignore();
			cin.get();
			chooseGame(player);
		}
		else if (result[0] == 1 || result[0] == 2 || result[0] == 3)
		{
			reward = bid * 3;
			cout << "Congratulations! You won: " << reward << endl;
			player.setIGCurrency(player.getIGCurrency() + reward);
			player.saveGame();
			cout << "Please proceed to return to Choose Game Menu..";
			cin.ignore();
			cin.get();
			chooseGame(player);
		}
	}	
	else if (result[0] == result[1] || result[0] == result[2] || result[1] == result[2])
	{
		if ((result[0] == 7 && result[1] == 7) || (result[0] == 7 && result[2] == 7) || (result[2] == 7 && result[1] == 7))
		{
			reward = 0;
			cout << "Sorry you did not win anything" << endl;
			player.setIGCurrency(player.getIGCurrency() + reward);
			player.saveGame();
			cout << "Please proceed to return to Choose Game Menu..";
			cin.ignore();
			cin.get();
			chooseGame(player);
		}
		else 
		{
			reward = bid + 10;
			cout << "Congratulations you won " << reward << endl;
			player.setIGCurrency(player.getIGCurrency() + reward);
			player.saveGame();
			cout << "Please proceed to return to Choose Game Menu..";
			cin.ignore();
			cin.get();
			chooseGame(player);
		}
	}
	else 
	{
		reward = 0;
		cout << "Sorry you did not win anything" << endl;
		player.setIGCurrency(player.getIGCurrency() + reward);
		player.saveGame();
		cout << "Please proceed to return to Choose Game Menu..";
		cin.ignore();
		cin.get();
		chooseGame(player);
	}
}


void gameHorseRace(UserData &player)
{
	system("CLS");
	cout << "---------------------------------------" << endl;
	cout << "--------- Horse Race Betting ----------" << endl;
	cout << "---------------------------------------" << endl;
	int numHorses, input, multiplier;
	bool flag = 0;
	
	cout << "Welcome to the Fast-Forwarded Horcerace betting!"<< endl;
	cout << "There are 10 horses out there and you are allowed to bet at the maximum of 3 horses" << endl <<
	"How many horses do you want to bet?"; cin >> numHorses;
	
	//different reward based on how many horses the player bet on
	if(numHorses == 1)
		multiplier = 7;
	else if(numHorses == 2)
		multiplier = 3;
	else if(numHorses == 3)
		multiplier = 2;
	
	int tempWhichHorse[numHorses];
	int tempHowMuch[numHorses];
	
	//input amount the player bid on each horse
	for (int i = 0; i < numHorses; i++)
	{
		cout <<"Which horse do you want to bet on? (1-10) "; cin >> input;
		tempWhichHorse[i] = input;
		cout << "How much do you want to bet? "; cin >> input;
		tempHowMuch[i] = input;
		
		player.setIGCurrency(player.getIGCurrency() - input);
		cout << "Thank you" << endl;
	}
	
	int winnerHorse = rand() % 10+1;
	int reward;
	
	cout << "Winner is horse: " << winnerHorse << endl;

	for(int i = 0; i < numHorses; i++)
	{
		if(tempWhichHorse[i] == winnerHorse)
		{
			reward = tempHowMuch[i] * multiplier;
			flag = 1;
			break;
		}
	}
		
	if(flag)
	{	
		cout << "Congratulations, you won: " << reward << endl;
		player.setIGCurrency(player.getIGCurrency() + reward);
	}
	else
		cout << "Sorry, you didn't win anything" << endl;
	
	player.saveGame();
	cout << "Please proceed to return to Choose Game Menu..";
	cin.ignore();
	cin.get();
	chooseGame(player);
}

void topUpCredits(UserData &player)
{
	system("CLS");
	string userInput;
	int value, nContents = 0; //nContents stores number of contents the file 
	string allInVoucher[600]; //number of codes exist when it was created was 300 + amount (300) = 600
	cout << "-----------TOP UP CREDITS-----------" << endl;
	cout << "Insert code: "; cin >> userInput;
	
	fstream fileOp;
	fileOp.open("Voucher.txt", ios_base::in | ios_base::out);
	bool flag = false;
	string temp;
	
	while(fileOp >> temp)
	{
		if(userInput == temp) //if the voucher code is correct   
		{
			fileOp >> temp; //retrieve the value below the code
			value = atoi (temp.c_str());
			flag = true;
		}
		else//else, put the content in allInVoucher
		{
			allInVoucher[nContents] = temp;
			nContents++;
		}
	}
	fileOp.close();
	
	cout << "Processing ------------" << endl;
	
	if(flag){
		//rewrite the file
		fstream fileOp;
		fileOp.open("Voucher.txt", ios_base::in | ios_base::out);
		
		for(int j = 0; j < nContents; j++)
		{
			fileOp << allInVoucher[j] << "\n";
			j++;
			fileOp << allInVoucher[j] << "\n\n";
		}
		fileOp.close();
		
		player.setIGCurrency(player.getIGCurrency() + value);
		cout << "Congratulations your In-game currency balance is now " << player.getIGCurrency() << endl;
	}
	else 
	{
		cout << "Sorry the code you inserted is wrong" << endl;
	}
	player.saveGame();
	cout << "Returning to Choose Game" << endl;
	cin.ignore();
	cin.get();
	chooseGame(player);
}
