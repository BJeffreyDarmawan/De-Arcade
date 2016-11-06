//
//Header file
//
#ifndef DECLARE_HPP
#define DECLARE_HPP

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>

using namespace std;

class UserData{
	private:
		string userName;
		int counter = 0; 
		int igCurrency=0;	
	public:
		UserData();
		void setUserName(string);
		void setCounter(int );
		void setIGCurrency(int );
		string getUserName();
		int getCounter();
		int getIGCurrency();
		void saveGame();
		void checkIGC();
		void checkUserName();
};
	void log_In(UserData &);
	void defaultInterface();
	void chooseGame(UserData &);
	void gameGuessTheNumber(UserData &);
	void gameSlots(UserData &);
	void gameHorseRace(UserData &);
	void topUpCredits(UserData &);
	void playerInfo(UserData &);
#endif
