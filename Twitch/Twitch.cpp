// Twitch.cpp : Defines the entry point for the console application.
//

#include "FlappyTwitch/GameManager.h"
#include<iostream>
#include<time.h>
using namespace std;




int main()
{
	cout << "Hello twitch!" << endl;
	srand(time(NULL));
	GameManager gameManager;
	gameManager.start();
	
	
	return 0;
}

