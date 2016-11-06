#include<iostream>
#include<ctime>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
int main(){

	string code; 
	int amount = 10;
	static const char insideRandom[] =
		"0123456789" 
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	

    srand(time(0));
    int codeLength = 12; //12 random characters
    int possRandom = strlen(insideRandom);
    
    fstream fileOp;
    fileOp.open("Voucher.txt");
    for(int x = 0; x < 300; x++)
    {
    	for(int i = 0; i < codeLength; ++i)
   		{
   			code += insideRandom[rand() % possRandom];
 		}
 		fileOp << code << "\n";
 		code = "";
 		fileOp << amount << "\n\n";
 		if(x%5 == 0)
 			amount+=10;
    }
    fileOp.close(); 
    cout << "Generate voucher codes successful!" << endl;
 
 	return 0;   
}
