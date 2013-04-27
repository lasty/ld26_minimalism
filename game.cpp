
#include "game.h"

#include <iostream>
using std::cout;
using std::endl;

#include <stdexcept>
using std::runtime_error;

MinGame::MinGame()
{

}

void MinGame::Run()
{
	cout << "Running" << endl;
	throw runtime_error("blah");
}



