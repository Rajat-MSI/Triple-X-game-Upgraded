#include<bits/stdc++.h>
using namespace std;
void gameIntro()
{
	cout<<"\t\t\t\t+--------------+"<<endl;
	cout<<"\t\t\t\t| Server Break |"<<endl;
	cout<<"\t\t\t\t+--------------+"<<endl;
	cout<<"+------------------------------------------------------------------------------+"<<endl;
	cout<<"| You are a Hacker you have to gain access to the Umbrella Inc. servers        |"<<endl;
	cout<<"| you have to enter a 3 digit combination code. there are 3 levels of server   |"<<endl;
	cout<<"| security and you only 5 Lifes after that the security protocol will activate |"<<endl;
	cout<<"| our own 'Agent Geek' will be there to help you                               |"<<endl;
	cout<<"+------------------------------------------------------------------------------+"<<endl;
}
bool gamePlay(int Level)
{
	gameIntro();
	int randNumA = rand() % Level + Level - 1;
	int randNumB = rand() % Level + Level - 1;
	int randNumC = rand() % Level + Level - 1;
	
	int randSum = randNumA + randNumB + randNumC;
	int randProduct = randNumA * randNumB * randNumC;
	
	cout<<"Hints -"<<endl;
	cout<<"+-------------------------------+"<<endl;
	cout<<"| Agent Geek - So the hints are |"<<endl;
	cout<<"| The Sum of code give : "<<randSum<<"      |"<<endl;
	cout<<"| The Product of code give : "<<randProduct<<"  |"<<endl;
	cout<<"+-------------------------------+"<<endl;
	
	int guessNumA;
	int guessNumB;
	int guessNumC;
	
	cout<<"\n"<<randNumA<<" "<<randNumB<<" "<<randNumC<<endl<<endl;
	cout<<"Code : ";
	cin>>guessNumA>>guessNumB>>guessNumC;
	system("cls");
	int guessSum = guessNumA + guessNumB + guessNumC;
	int guessProduct = guessNumA * guessNumB * guessNumC;
	
	if(guessSum == randSum && guessProduct == randProduct)
	{
		cout<<"\nCode accepted!! Server level "<<Level - 1<<" access gained."<<endl;
		return true;
	}
	else
	{
		cout<<"\nInvalid Code!! ";
		return false;
	}
}
int main()
{
	srand(time(NULL));
	int Level = 2;
	int const maxLevel = 5;
	int Life = 5;
	while(Level <= maxLevel - 1)
	{
		bool gameStart = gamePlay(Level);
		cin.clear();
		cin.ignore();
		if(gameStart)
		{
			++Level;
		}
		else
		{
			--Life;
			cout<<"Remaining life : "<<Life<<endl;
			if(Life == 0)
			{
				break;
			}
		}
		cout<<endl;
	}
	if(Life == 0)
	{
		cout<<endl;
		cout<<"\t\t\t+----------------------------------------+"<<endl;
		cout<<"\t\t\t| Security protocols are on... Game over |"<<endl;
		cout<<"\t\t\t+----------------------------------------+"<<endl;
	}
	else
	{
		cout<<endl;
		cout<<"\t\t\t+----------------------------------------------+"<<endl;
		cout<<"\t\t\t|  All servers in our control great job Agent! |"<<endl;
		cout<<"\t\t\t+----------------------------------------------+"<<endl;
	}
	return 0;	
}
