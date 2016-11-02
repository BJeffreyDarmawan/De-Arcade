//
//this is a temporary file due to 'undefined reference' error when splitting files
//


#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;

	string temporaryAllFile[999];
	//string *temporaryAllFile = new string [0];
	int i = 0; //total number of lines on the txt file

//a class that temporarily stores the data of the player
class UserData{
	private:
		string userName;
		int counter = 0; //to mark the userName's position on the list
		int igCurrency=0;
		
	public:
		PlayGame(){
			this->userName = "";
			this->counter = 0;
			this->igCurrency = 0;
			}
		
		void setUserName(string userName)
		{
			this->userName = userName;
		}
		void setCounter(int counter)
		{
			this->counter = counter;
		}
		void setIGCurrency(int igCurrency)
		{
			this->igCurrency = igCurrency;
		}
		
		string getUserName()
		{
			return this->userName;
		}
		int getCounter()
		{
			return this->counter;
		}
		int getIGCurrency()
		{
			return this->igCurrency;
		}
		
		void saveGame()
		{
			//save game by rewriting the file
			fstream fileOp;
			fileOp.open("Database.txt", ios_base::in | ios_base::out);
			temporaryAllFile[counter-1] = userName;
			temporaryAllFile[counter] = to_string(igCurrency);
			cout << temporaryAllFile[counter] << endl;
			for(int j = 0; j < i; j++)
			{

				fileOp << temporaryAllFile[j] << "\n";
				j++;
				cout << j << endl << counter<< endl  << i;
				fileOp << temporaryAllFile[j] << "\n\n";
			}
			fileOp.close();
		}
		void checkIGC()
		{
			cout << "In-game currency: " << igCurrency << endl;
		}
		void checkUserName()
		{
			cout << "UserName: " << userName << endl;
		}
	
};
	
	void log_In(UserData &);
	void defaultInterface();
	void chooseGame(UserData &);
	void gameGuessTheNumber(UserData &);
	void gameSlots(UserData &);
	void gameX(UserData &);
	
int main()
{	
	

	
	UserData player;
	
	log_In(player); 
	
	chooseGame(player);

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
		cout << "3. x game " << endl;
		cout << "9. Player Info" << endl;
		cout << "0. Exit game " << endl;
		cout << "Your choice : "; cin >> userInput;
		
		switch(userInput)
		{
			case 1: gameGuessTheNumber(player);
					  break;
			case 2: gameSlots(player);
					  break;
			case 3: gameX(player);
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
		temporaryAllFile[i] = temp;//error here
		i++;
		if(temp == userName)         
		{
			fileOp >> temp;
			player.setCounter(i);
			igCurrency = atoi (temp.c_str());
			temporaryAllFile[i] = temp; //error here
			i++;
			flag = true;
			cout << "Loading data..." << endl;
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
	
		player.setCounter(i+1);	
		i+=2;
		cout << "Creating New Username..." << endl;
		//cout << player.getCounter() << " ";
		//cout << i;
	}
	
	//load in game currency
	player.setUserName(userName);
	player.setIGCurrency(igCurrency);
	//cout << player.getIGCurrency();
	
	cout << "--- Your Data ------------------------" << endl;
	player.checkUserName();
	player.checkIGC();
	cin.ignore();
	cin.get();
}


void gameGuessTheNumber(UserData &player)
{
	try{
		//declaration of necessary variables
		srand(time(NULL));
		int num1 = 0, num2 = 0, num3 = 0, digit1 = 0, digit2 = 0, digit3 = 0;
		bool condition = 1;
		int chances = 0;
		int bid, reward = 0, multiplier = 2;
		
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
					string failGuess;
					throw failGuess;
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
					string failGuess;
					throw failGuess;
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
					string failGuess;
					throw failGuess;
				}
			}
		}
		
		reward = multiplier * bid;
		cout << "Congratulations, you guessed the right number! " << endl;
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


void gameX(UserData &player)
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
